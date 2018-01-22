<?php

    // configuration
    require("../includes/config.php"); 

    $history = CS50::query("SELECT * FROM history WHERE user_id = ?", $_SESSION["id"]);
    $i = 0;
    $positions = [];
    if (!empty($history))
    {
        foreach ($history as $row)
        {
            $stock = lookup($row["symbol"]);
            $price = $stock["price"];
            $positions[$i]["symbol"] = $row["symbol"];
            $positions[$i]["name"] = $stock["name"];
            $positions[$i]["shares"] = $row["shares"];
            $positions[$i]["price"] = number_format($price, 4, ".", " ");
            $positions[$i]["total"] = number_format($positions[$i]["shares"] * $positions[$i]["price"], 2, ".", " ");
            $positions[$i]["date"] = $row["date"];
            $positions[$i]["transaction"] = ($row["buy"]) ? "BUY" : "SELL";
            $i++;
        }
    }

    // render history
    render("history.php", ["title" => "History", "positions" => $positions]);

?>
