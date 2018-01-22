<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
        // else render form
        render("password_form.php", ["title" => "Change password"]);
    }

    // else if user reached page via POST (as by submitting a form via POST)
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
        // query database for password
        $rows = CS50::query("SELECT hash FROM users WHERE id = ?", $_SESSION["id"]);
        $row = $rows[0];
        if (empty($_POST["new_password"]) || empty($_POST["current_password"]) || !password_verify($_POST["current_password"], $row["hash"]))
        {
            apologize("You must provide your password.");
        }
        else if ($_POST["new_password"] != $_POST["confirmation"])
        {
            apologize("The fields with your password must be the same");
        }
        else
        {
            $password = password_hash($_POST["new_password"], PASSWORD_DEFAULT);
            CS50::query("UPDATE users SET hash = '$password' WHERE id = {$_SESSION["id"]}");
            
            
            redirect("index.php");
            
        }
        
        
    }

?>