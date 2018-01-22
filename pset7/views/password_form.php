<form action="password.php" method="post">
    <fieldset>
        <div class="form-group">
            <input autocomplete="off" autofocus class="form-control" name="current_password" placeholder="Current password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="new_password" placeholder="New password" type="password"/>
        </div>
        <div class="form-group">
            <input class="form-control" name="confirmation" placeholder="Confirm new password" type="password"/>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">
                <span aria-hidden="true" class="glyphicon glyphicon-log-in"></span>
                Change password
            </button>
        </div>
    </fieldset>
</form>
<div>
    or <a href="index.php">cancel</a>
</div>