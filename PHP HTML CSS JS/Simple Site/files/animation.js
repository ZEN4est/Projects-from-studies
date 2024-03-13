        const canvas = document.getElementById('animationCanvas');
        const ctx = canvas.getContext('2d');

        const g = 9.8; 
        let time = 0.1; 
        let dt = 0.05; 
        let animationInterval;

        function drawCoordinateAxes() {
            ctx.beginPath();
            ctx.moveTo(10, canvas.height - 10);
            ctx.lineTo(canvas.width - 10, canvas.height - 10);
            ctx.stroke();

            ctx.beginPath();
            ctx.moveTo(10, canvas.height - 10);
            ctx.lineTo(10, 10);
            ctx.stroke();

            ctx.font = "12px Arial";
            ctx.fillText("Oś X ", canvas.width - 40, canvas.height - 15);
            ctx.fillText("Oś Y ", 15, 20);
        }

        function drawProjectile(velocity, angle) {
            const initialVelocityX = velocity * Math.cos(angle * (Math.PI / 180));
            const initialVelocityY = velocity * Math.sin(angle * (Math.PI / 180));

            let x = 0;
            let y = canvas.height - 10;

            ctx.clearRect(0, 0, canvas.width, canvas.height);
            drawCoordinateAxes();

            ctx.beginPath();
            ctx.arc(x + 10, y, 5, 0, 2 * Math.PI);
            ctx.fillStyle = 'red';
            ctx.fill();
            ctx.stroke();

            animationInterval = setInterval(() => {
                x = initialVelocityX * time;
                y = canvas.height - 10 - (initialVelocityY * time - (0.5 * g * Math.pow(time, 2)));

                ctx.clearRect(0, 0, canvas.width, canvas.height);
                drawCoordinateAxes();

                ctx.beginPath();
                ctx.arc(x + 10, y, 5, 0, 2 * Math.PI);
                ctx.fillStyle = 'red';
                ctx.fill();
                ctx.stroke();

                time += dt;

                if (y > canvas.height - 10) {
                    time = 0.1;
                }
            }, 10);
        }

        document.getElementById('velocityRange').addEventListener('input', updateProjectile);
        document.getElementById('angleRange').addEventListener('input', updateProjectile);

        function updateProjectile() {
            clearInterval(animationInterval);
            time = 0.1;
            const velocity = document.getElementById('velocityRange').value;
            const angle = document.getElementById('angleRange').value;
            document.getElementById('velocityDisplay').innerHTML = velocity + " m/s";
            document.getElementById('angleDisplay').innerHTML = angle + "°";
            var range = ((velocity*velocity*Math.sin(2*angle * (Math.PI / 180)))/g).toFixed(2);
            var height = ((velocity*velocity*Math.sin(angle * (Math.PI / 180))*Math.sin(angle * (Math.PI / 180)))/(2*g)).toFixed(2);
            document.getElementById('range').innerHTML = range + " m";
            document.getElementById('height').innerHTML = height + " m";
            drawProjectile(velocity, angle);
        }


        drawProjectile(30,45);
