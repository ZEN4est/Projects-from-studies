<?php
include 'loginRegister.php';
function alert($text) {echo "<script type='text/javascript'>alert('$text');</script>";}
session_start();
$db = dba_open('hasla.db', 'c', 'db4');
if ($_SERVER['REQUEST_METHOD'] == 'POST'){
    
        $email = $_POST['email'];
        $password = $_POST['password'];
        if (dba_exists($email, $db)){
            $hPassword = dba_fetch($email, $db);
            if (password_verify($password, $hPassword)){
                $_SESSION['email'] = $email;
                header('Location: MainPage.php');
                exit();
            }
        }
        alert("Błędny email lub hasło.");
        exit();
    
}
dba_close($db);
$mode = $_COOKIE['mode'];
?>
