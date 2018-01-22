/**
 * copy.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Copies a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize number infile outfile\n");
        return 1;
    }

    // remember filenames and times resize factor
    float times = atoi(argv[1]);
    if (times < 0 || times > 100) {
        return 4;
    }
    char* infile = argv[2];
    char* outfile = argv[3];

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    
    int infilePadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int infilebiWidth = bi.biWidth;
    int infilebiHeight = abs(bi.biHeight);
    bi.biWidth *= times;
    bi.biHeight *= times;
    // determine padding for scanlines
    int outfilePadding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    bi.biSizeImage = abs(bi.biHeight) * (3 * bi.biWidth + outfilePadding);
    bf.bfSize = 14 + 40 + bi.biSizeImage;
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines
    for (int i = 0; i < infilebiHeight; i++)
    {
        
        for (int m = 0; m < times; m++)
        {
            // iterate over pixels in scanline
            for (int j = 0; j < infilebiWidth; j++)
            {
                // temporary storage
                RGBTRIPLE triple;
    
                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
                
                // write RGB triple to outfile
                for (int l = 0; l < times; l++)
                {
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
                
                
            // skip over padding, if any
            fseek(inptr, infilePadding, SEEK_CUR);
    
            // then add it back (to demonstrate how)
            for (int k = 0; k < outfilePadding; k++)
            {
                fputc(0x00, outptr);
            }
            
            if (m < times - 1)
            {
                int skip = -(infilebiWidth * 3 + infilePadding);
                fseek(inptr, skip, SEEK_CUR);
            }
            
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
