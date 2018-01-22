import nltk

class Analyzer():
    """Implements sentiment analysis."""

    def __init__(self, positives, negatives):
        """Initialize Analyzer."""

        # TODO
        self.positives = []
        self.negatives = []
        with open(positives, "r") as positivesFileContent:
            # chr(10) is a new line sign
            # rstrip removes the newline sign at the end of each word
            for line in positivesFileContent:
                if line[0] != ";" and line[0] != chr(10):
                    self.positives.append(line.strip())
        with open(negatives, "r") as negativesFileContent:
            for line in negativesFileContent:
                if line[0] != ";" and line[0] != chr(10):
                    self.negatives.append(line.strip())

    def analyze(self, text):
        """Analyze text for sentiment, returning its score."""

        # TODO
        tknzr = nltk.tokenize.TweetTokenizer()
        tokens = tknzr.tokenize(text)
        score = 0
        for token in tokens:
            if token.lower() in self.positives:
                score += 1
            if token.lower() in self.negatives:
                score -= 1
        return score
