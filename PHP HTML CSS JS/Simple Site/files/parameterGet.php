<?php
session_start();

$email = $_SESSION['email'];

$db = dba_open('parameters.db', 'r');

$parametersJSON = dba_fetch($email, $db);

dba_close($db);

$parametersArray = json_decode($parametersJSON, true);

header('Content-Type: application/json');
echo json_encode($parametersArray);
?>
