<?php
session_start();

$email = $_SESSION['email'];

$db = dba_open('mode.db', 'c');

$mode = dba_fetch($email, $db);

dba_close($db);
echo $mode;

?>
