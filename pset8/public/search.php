<?php

    require(__DIR__ . "/../includes/config.php");

    // numerically indexed array of places
    $places = [];

    // TODO: search database for places matching $_GET["geo"], store in $places
    
    $place = explode(" ", $_GET["geo"]);
    print($place[0] . "\n");
    print($place[1] . "\n");
    //$places = CS50::query("SELECT postal_code, place_name FROM places WHERE postal_code LIKE ?", $_GET["geo"] . "%");
    
    //$places = CS50::query("SELECT * FROM places WHERE MATCH (postal_code, place_name) AGAINST (?)", "%" . $_GET["geo"] . "%");
    $query = "SELECT postal_code, place_name FROM places WHERE (";
    
    for ($i = 0; $i < count($place); $i++)
    {
        if ($i > 0)
        {
            $query = $query . " AND (";
        }
        
        $query = $query . "postal_code LIKE \"". $place[$i] . 
        "\"% OR place_name LIKE \"" . $place[$i] . 
        "\"% OR admin_name1 LIKE \"" . $place[$i] . "\"%)";
    }
    
    print($query);
    
    $places = CS50::query($query);
    //$places = CS50::query("SELECT postal_code, place_name FROM places WHERE 
    //    postal_code LIKE ?",  . "%");
    

    // output places as JSON (pretty-printed for debugging convenience)
    header("Content-type: application/json");
    print(json_encode($places, JSON_PRETTY_PRINT));

?>