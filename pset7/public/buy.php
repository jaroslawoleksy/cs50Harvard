<?php

    // configuration
    require("../includes/config.php"); 

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("buy_form.php", ["title" => "Buy"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        if (empty($_POST["symbol"]))
        {
            apologize("What stock do you want to purchase?");
        }
        else if (empty($_POST["shares"]) || preg_match("/^\d+$/", $_POST["shares"]) == false)
        {
            apologize("How many shares do you want to purchase?");
        }
        else
        {
            $stock = lookup($_POST["symbol"]);
            if ($stock == false || $stock["name"] =="N/A")
            {
                apologize("We couldn't find the stock you want to buy");
            }
            else
            {
                $cost = $stock["price"] * $_POST["shares"];
                $cash = CS50::query("SELECT cash FROM users WHERE id = {$_SESSION["id"]}");
                if ($cost > $cash[0]["cash"])
                {
                    apologize("You don't have enough money");
                }
                else
                {
                    $cash = $cash[0]["cash"] - $cost;
                    CS50::query("UPDATE users SET cash = $cash WHERE id = {$_SESSION["id"]}");
                    CS50::query("INSERT INTO portfolios (user_id, symbol, shares) VALUES({$_SESSION["id"]}, '{$stock["symbol"]}', {$_POST["shares"]}) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)");
                    
                    //update history
                    CS50::query("INSERT INTO history (user_id, symbol, buy, shares, price) VALUES({$_SESSION["id"]}, '{$stock["symbol"]}', true, {$_POST["shares"]}, {$stock["price"]})");
                }
                redirect("index.php");
            }
        }
        
    }
?>