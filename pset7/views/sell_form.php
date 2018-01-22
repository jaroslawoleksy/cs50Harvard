<form action="sell.php" method="post">
    <fieldset>
        <div class="form-group">
            <select class="form-control" name="stock_to_sell">
            <?php
                for ($i = 0; $i < count($positions); $i++)
                { ?>
                    <option value="<?= $positions[$i] ?>"><?= $positions[$i] ?></option>
                <?php } ?>
             </select>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-usd"></span>
                Sell
            </button>
        </div>
    </fieldset>
</form>
