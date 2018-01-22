<table class= "table table-hover">
    
    <?php 
    if (!empty($positions))
    //if ($positions != false)
    {
    ?>
    <thead>
        <tr>
            <th class="text-center">Share Symbol</th>
            <th class="text-center">Name</th>
            <th class="text-center">Number of shares</th>
            <th class="text-center">Share price</th>
            <th class="text-center">Total</th>
        </tr>
    </thead>
    <?php
        foreach ($positions as $position): ?>
        
            <tr>
                <td><?= $position["symbol"] ?></td>
                <td><?= $position["name"] ?></td>
                <td><?= $position["shares"] ?></td>
                <td>$<?= $position["price"] ?></td>
                <td>$<?= $position["total"] ?></td>
            </tr>
        
        <?php endforeach; 
    }?>
        <tr>
            <td>CASH</td>
            <td></td>
            <td></td>
            <td></td>
            <td>$<?= $cash ?></td>
        </tr>
</table>