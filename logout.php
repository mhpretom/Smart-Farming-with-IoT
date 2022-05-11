<?php 
session_start();
session_destroy();
echo "<meta http-equiv='refresh' content='3;url=login.php' />";
?>