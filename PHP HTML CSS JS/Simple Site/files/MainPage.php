<?php
session_start();
$db = dba_open('mode.db', 'c');
$mode = dba_fetch($_SESSION['email'], $db);
if ($mode !== false) {
    dba_close($db);
} else {
    $mode = 'default_mode';
    dba_close($db);
}
?>

<!DOCTYPE html>
<html lang="pl">
<head>
    <meta charset="UTF-8">
    <title>Strona Główna</title>
    <link rel="stylesheet" href="<?php echo $mode == 'dark_mode' ? 'dark_mode.css' : 'light_mode.css'; ?>">
    <script src="script.js"></script>
    <script type="text/javascript" async
            src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.7/MathJax.js?config=TeX-MML-AM_CHTML">
    </script>
    <link rel="stylesheet" href="style.css">
</head>

<body>
    <button id="chmod" onclick="changeModeUser()">Zmień motyw</button>
    
    <button onclick="window.location.href = 'logout.php'">Wyloguj się</button>

    <h2>Rzut poziomy</h2>
    Rzut ukośny to ruch ciała, w którym ciało jest rzucone pod pewnym kątem doziemnej, przy czym prędkość początkowa ma zarówno składową poziomą, jak i pionową.
    <br>Tor ruchu ciała w rzucie ukośnym jest parabolą. Ruch ciała łączy ruch poziomy jednostajny z ruchem pionowym jednostajnie opadającym.
    <p>Zasięg rzutu (\(R\)):</p>
\[ R = \frac{v^2 \sin^2(\theta)}{g} \]

<p>Maksymalna wysokość (\(H\)):</p>
\[ H = \frac{v^2 \sin^2(\theta)}{2g} \]

    <div class="frame" style="margin: 1%; display: flex; align-items: center; justify-content: space-around;">
    <div style="display: flex; flex-direction: column; align-items: center;">
        <label for="velocityRange">Prędkość rzutu (m/s): </label>
        <input type="range" id="velocityRange" min="1" max="100" value="30" style="height: 150px; transform: rotate(-90deg); transform-origin: 50% 50%;">
        <span id="velocityDisplay">30 m/s</span>
    </div>

    <div style="display: flex; flex-direction: column; align-items: center;">
        <label for="angleRange">Kąt rzutu (stopnie): </label>
        <input type="range" id="angleRange" min="0" max="90" value="45" style="height: 150px; transform: rotate(-90deg); transform-origin: 50% 50%;">
        <span id="angleDisplay">45°</span>
    </div>
  
  
    <div style="margin-right: 10px; text-align: center;">
        Zasięg rzutu:    <div id="range">91.84 m</div>
        <br>
        Wysokość maksymalna: <div id="height">22.96 m</div>
        <button onclick="setParameters()">zapisz</button>
        <button onclick="getParameters()">wczytaj zapisane</button>
    </div>

    <canvas id="animationCanvas" width="800" height="500"></canvas>
</div>


    <script src="animation.js"></script>
    <script>getParameters()</script>
        
</body>
</html>
