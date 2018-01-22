<?php

    // configuration
    require("../includes/config.php"); 

    $portfolios = CS50::query("SELECT * FROM portfolios WHERE user_id = ?", $_SESSION["id"]);
    $i = 0;
    $positions = [];
    if (!empty($portfolios))
    {
        foreach ($portfolios as $portfolio)
        {
            $stock = lookup($portfolio["symbol"]);
            $price = $stock["price"];
            $positions[$i]["symbol"] = $portfolio["symbol"];
            $positions[$i]["name"] = $stock["name"];
            $positions[$i]["shares"] = $portfolio["shares"];
            $positions[$i]["price"] = number_format($price, 4, ".", " ");
            $positions[$i]["total"] = number_format($positions[$i]["shares"] * $positions[$i]["price"], 2, ".", " ");
            $i++;
        }
    }

    $cash = CS50::query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);


    // render portfolio
    render("portfolio.php", ["title" => "Portfolio", "positions" => $positions, "cash" => number_format($cash[0]["cash"], 2, ".", " ")]);

?>
