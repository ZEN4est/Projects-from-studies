<?php
include 'loginRegister.php';
function alert($text) {echo "<script type='text/javascript'>alert('$text');</script>";}
session_start();
$db = dba_open('hasla.db', 'c', 'db4');
if ($_SERVER['REQUEST_METHOD'] == 'POST'){
    if(isset($_POST['register'])){
        $newEmail = $_POST['registerEmail'];
        $newPassword = $_POST['registerPassword'];
        if (dba_exists($newEmail, $db)) {alert("Podany email już istenieje");}
        else{
            $hPassword = password_hash($newPassword, PASSWORD_DEFAULT);
            if (dba_insert($newEmail, $hPassword, $db)) {
                alert("Zarejestrowano, możesz się zalogować.");
                $dbMode = dba_open('mode.db', 'c');
                $dbParameter = dba_open('parameters.db', 'c');
                dba_insert($newEmail, 'light_mode', $dbMode);
                $dataArray = ['velocity' => 30, 'angle' => 45];
                $dataString = json_encode($dataArray);
                dba_insert($newEmail, $dataString, $dbParameter);
            } 
            else {alert("Błąd.");}
        }
    }
}
$mode = $_COOKIE['mode'];
dba_close($dbParameter);
dba_close($dbMode);
dba_close($db);
?>
