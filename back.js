const express = require('express');
const fs = require('fs');
const { spawn } = require('child_process');

const app = express();
const port = 3000;

let gpio_Value = ''; 

app.get('/', (req, res) => {
    fs.readFile('index.html', (err, data) => {
        if (err) {
            res.writeHead(500, {'Content-Type': 'text/plain'});
            res.end('Internal Server Error');
        } else {
            res.writeHead(200, {'Content-Type': 'text/html'});
            res.end(data);
        }
    });
});
let caseValue;
let processPY;
app.get('/get_timer_value', (req, res) => {
    let mode = req.query.mode;
	switch(mode) {
		case 'numeric':
			processPY = spawn('python', ['GPIO.py']);
			processPY.stdout.on('data', (gpio_Value) => {
			  console.log(`子进程的输出：${gpio_Value}`);
			  caseValue=gpio_Value.toString().trim();
			});
			console.log(`test:${caseValue}`);
			res.send(caseValue);
			processPY.on('close', (code) => {
			  console.log(`子进程退出，退出码 ${code}`);
			});
			return;
		case 'N':
			processPY = spawn('python', ['GPIO.py','0']);
			caseValue = 'LED1 OFF, LED2 OFF';
			break;
		case 'A':
			processPY = spawn('python', ['GPIO.py','A']);
			caseValue = 'LED1 ON, LED2 OFF';
			break;
		case 'B':
			processPY = spawn('python', ['GPIO.py','B']);
			caseValue = 'LED1 OFF, LED2 ON';
			break;
		case 'BOTH':
			processPY = spawn('python', ['GPIO.py','AB']);
			caseValue = 'LED1 ON, LED2 ON';
			break;
		default:
			console.log(`back ground: ERROR ${mode}`);
			break;
	}
	processPY.stdout.on('data', (gpio_Value) => {
		console.log(`子进程的输出：${gpio_Value}`);
	});
	processPY.stderr.on('data', (data) => {
		console.error(`子进程的错误输出：${data}`);
	});
	processPY.on('close', (code) => {
	    console.log(`子进程退出，退出码 ${code}`);
	});
	console.log(`back ground: ${caseValue}`);
    res.send(caseValue);
});



app.use(express.static('public'));

app.listen(port, () => {
    console.log(`Server is running at http://localhost:${port}`);
});
