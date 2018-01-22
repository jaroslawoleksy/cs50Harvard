<?php

    // configuration
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("quote_form.php", ["title" => "Quote"]);
    }
    
    if (empty($_POST["symbol"]))
        {
            apologize("You must provide stock symbol.");
        }
        else
        {
            $stock = lookup($_POST["symbol"]);
            if ($stock == false)
            {
                apologize("Didn't find the symbol. Check again.");
            }
            else
            {
                render("quote.php", ["name" => $stock["name"], "symbol" => $stock["symbol"], "price" => $stock["price"], $title = "Quote"]);
            }
        }

?>