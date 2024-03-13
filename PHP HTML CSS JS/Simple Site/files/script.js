async function changeMode() {
    var cookieMode = getCookie("mode");
    setCookie("mode", (cookieMode === "light_mode" || cookieMode === "") ? "dark_mode" : "light_mode", 30);
    location.reload();

}


function setParameters() {
    const xhr = new XMLHttpRequest();
    var velocity = document.getElementById("velocityRange").value;
    var angle = document.getElementById("angleRange").value;

    const data = {
    velocity: velocity,
    angle: angle
    };

    const jsonData = JSON.stringify(data);

    xhr.open("POST", 'parameterSet.php', true);
    xhr.setRequestHeader("Content-Type", "application/json");
    xhr.onreadystatechange = function () {
        if (xhr.readyState === 4 ) {
            if (xhr.status === 200) {
        
            } else {
                console.error("Błąd żądania:", xhr.status);
            }
        }
    };
    xhr.send(jsonData);
}


function getParameters() {
    const xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function () {
        if (xhr.readyState === 4 || xhr.readyState === 200) {
            const response = JSON.parse(xhr.responseText);
            const angleRange = document.getElementById('angleRange');
            const velocityRange = document.getElementById('velocityRange');
            const velocityDisplay = document.getElementById('velocityDisplay');
            const angleDisplay = document.getElementById('angleDisplay');
            velocityDisplay.innerHTML = response.velocity + " m/s";
            angleDisplay.innerHTML = response.angle + "°";
            const angle = parseInt(response.angle);
            const velocity = parseInt(response.velocity);
            angleRange.value = angle;
            velocityRange.value = velocity;
            var range = ((velocity*velocity*Math.sin(2*angle * (Math.PI / 180)))/g).toFixed(2);
            var height = ((velocity*velocity*Math.sin(angle * (Math.PI / 180))*Math.sin(angle * (Math.PI / 180)))/(2*g)).toFixed(2);
            document.getElementById('range').innerHTML = range + " m";
            document.getElementById('height').innerHTML = height + " m";
            updateProjectile();
        }
    };
    xhr.open("POST", 'parameterGet.php', true);
    xhr.send();
}



async function changeModeUser() {
    var xhr = new XMLHttpRequest();
    var mode;

    xhr.open("GET", "modGet.php", true);
    xhr.onreadystatechange = function () {
        if (xhr.readyState === 4 && xhr.status === 200) {
            if (xhr.responseText.trim() !== "") {
                mode = xhr.responseText; 
                console.log(mode);

                mode = (mode == "light_mode") ? "dark_mode" : "light_mode";
                var xhrPost = new XMLHttpRequest();
                xhrPost.open("POST", "modSet.php", true);
                xhrPost.setRequestHeader("Content-Type", "application/json");

                xhrPost.onreadystatechange = function () {
                    if (xhrPost.readyState === 4 && xhrPost.status === 200) {
                        console.log(xhrPost.responseText);

                         location.reload();
                    }
                };

                xhrPost.send(JSON.stringify(mode));
            } else {
                console.error("Empty responseText");
            }
        }
    };
    xhr.send();
}

function getCookie(Nazwa) {
    var name = Nazwa + "=";
    var decodedCookie = decodeURIComponent(document.cookie);
    var Array = decodedCookie.split(';');

    for (var i = 0; i < Array.length; i++) {
        var cookie = Array[i].trim();
        if (cookie.indexOf(name) === 0) {
            return cookie.substring(name.length);
        }
    }
    return "";
}

function setCookie(Nazwa, val, days) {
    var date = new Date();
    date.setTime(date.getTime() + days * 86400000);
    var expire = "expire=" + date.toUTCString();
    document.cookie = Nazwa + "=" + val + ";" + expire + ";path=/";
}



