<?php

    // configuration
    require("../includes/config.php");
    
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
    
        $portfolios = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
        $i = 0;
        $positions = [];
        if (!empty($portfolios))
        {
            foreach ($portfolios as $portfolio)
            {
                $stock = lookup($portfolio["symbol"]);
                $positions[$i] = $portfolio["symbol"];
                
                $i++;
            }
        }
        
        // render sell
        render("sell_form.php", ["title" => "Sell", "positions" => $positions]);
    }
    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $shares = CS50::query("SELECT shares FROM portfolios WHERE user_id = {$_SESSION["id"]} AND symbol = \"{$_POST["stock_to_sell"]}\"");
        CS50::query("DELETE FROM portfolios WHERE user_id = {$_SESSION["id"]} AND symbol = \"{$_POST["stock_to_sell"]}\"");
        $stock = lookup($_POST["stock_to_sell"]);
        $income = $shares[0]["shares"] * $stock["price"];
        $cash = CS50::query("SELECT cash FROM users WHERE id = {$_SESSION["id"]}");
        $cash = $cash[0]["cash"] + $income;
        CS50::query("UPDATE users SET cash = $cash WHERE id = {$_SESSION["id"]}");
        
        //update history
        CS50::query("INSERT INTO history (user_id, symbol, buy, shares, price) VALUES({$_SESSION["id"]}, '{$stock["symbol"]}', false, {$shares[0]["shares"]}, {$stock["price"]})");
        redirect("index.php");
    }
?>