<?php
session_start();
if (!isset($_COOKIE['mode'])) {setcookie('mode', 'light_mode', time()+(63072000000),"/");}
$mode = $_COOKIE['mode'];
?>

<?php include 'loginRegister.php'; ?>