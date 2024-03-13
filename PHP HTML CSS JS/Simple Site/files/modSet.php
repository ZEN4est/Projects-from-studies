<?php
session_start();
$db = dba_open('mode.db', 'c');

$mode = file_get_contents('php://input');

dba_replace($_SESSION['email'], json_decode($mode,true), $db);
dba_close($db);
?>