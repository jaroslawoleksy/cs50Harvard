<table class= "table table-hover">
    
    <?php 
    if (!empty($positions))
    {
    ?>
    <thead>
        <tr>
            <th class="text-center">Transaction</th>
            <th class="text-center">Date/Time</th>
            <th class="text-center">Symbol</th>
            <th class="text-center">Shares</th>
            <th class="text-center">Price</th>
        </tr>
    </thead>
    <?php
        foreach ($positions as $position): ?>
        
            <tr>
                <td><?= $position["transaction"] ?></td>
                <td><?= $position["date"] ?></td>
                <td><?= $position["symbol"] ?></td>
                <td><?= $position["shares"] ?></td>
                <td>$<?= $position["price"] ?></td>
            </tr>
        
        <?php endforeach; 
    }?>
</table>