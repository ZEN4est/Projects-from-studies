<?php
session_start();

$db = dba_open('parameters.db', 'c');

$email = $_SESSION['email'];

$inputJSON = file_get_contents('php://input');
$inputData = json_decode($inputJSON, true);

$velocity = $inputData['velocity'];
$angle = $inputData['angle'];

$newData = json_encode(['velocity' => $velocity, 'angle' => $angle]);

dba_replace($email, $newData, $db);

dba_close($db);

?>
