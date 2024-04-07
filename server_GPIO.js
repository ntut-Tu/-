const http = require('http');
const fs = require('fs');
const { exec } = require('child_process');

const server = http.createServer((req, res) => {
    if (req.url === '/') {
        fs.readFile('index.html', (err, data) => {
            if (err) {
                res.writeHead(500, {'Content-Type': 'text/plain'});
                res.end('Internal Server Error');
            } else {
                res.writeHead(200, {'Content-Type': 'text/html'});
                res.end(data);
            }
        });
    } else if (req.url.startsWith('/ToCtrlMode')) {
        // Clear the contents of output.txt before processing a new request
        fs.writeFileSync('output.txt', '');

        // Extract LED identifiers and mode from the request URL
        const [mode, ...leds] = req.url.split('/').slice(2).filter(val => val !== ''); // Extract Mode and LED identifiers
        console.log('ToCtrlMode', mode, leds);

        // Execute the C++ program for each LED
        leds.forEach(led => {
            if (mode === 'OFF') {
                exec(`./GPIO_ctrl ${led} OFF`, (error, stdout, stderr) => {
                    if (error) {
                        console.error(`exec error: ${error}`);
                        return;
                    }
                    console.log(`stdout: ${stdout}`);
                    console.error(`stderr: ${stderr}`);

                    // Append the output to output.txt
                    fs.appendFileSync('output.txt', `${stdout}\n${stderr}\n`);
                });
            } else {
                // Default to ON mode
                exec(`./GPIO_ctrl ${led} ON`, (error, stdout, stderr) => {
                    if (error) {
                        console.error(`exec error: ${error}`);
                        return;
                    }
                    console.log(`stdout: ${stdout}`);
                    console.error(`stderr: ${stderr}`);

                    // Append the output to output.txt
                    fs.appendFileSync('output.txt', `${stdout}\n${stderr}\n`);
                });
            }
        });

        res.writeHead(200, {'Content-Type': 'text/plain'});
        res.end('ToCtrlMode Request Handled');
    }else if (req.url.startsWith('/ToShineMode')) {
        // Clear the contents of output.txt before processing a new request
        fs.writeFileSync('output.txt', '');

        const maxCount = req.url.split('/').slice(2).filter(val => !isNaN(parseInt(val)))[0]; // Extract maximum count
        console.log('ToShineMode', maxCount);

        // Execute the C++ program with Mode_Shine and maximum count as arguments
        exec(`./GPIO_ctrl Mode_Shine ${maxCount}`, (error, stdout, stderr) => {
            if (error) {
                console.error(`exec error: ${error}`);
                return;
            }
            console.log(`stdout: ${stdout}`);
            console.error(`stderr: ${stderr}`);

            // Append the output to output.txt
            fs.appendFileSync('output.txt', `${stdout}\n${stderr}\n`);
        });

        res.writeHead(200, {'Content-Type': 'text/plain'});
        res.end('ToShineMode Request Handled');
    } else {
        res.writeHead(404, {'Content-Type': 'text/plain'});
        res.end('Not Found');
    }
});

const port = 3000;
server.listen(port, () => {
    console.log(`Server running at http://localhost:${port}/`);
});
