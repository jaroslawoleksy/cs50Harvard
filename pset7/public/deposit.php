<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("deposit_form.php", ["title" => "Deposit"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        $cash = CS50::query("SELECT cash FROM users WHERE id = {$_SESSION["id"]}");
        $cash = $cash[0]["cash"] + $_POST["deposit"];
        CS50::query("UPDATE users SET cash = $cash WHERE id = {$_SESSION["id"]}");
        redirect("index.php");
        
    }

?>