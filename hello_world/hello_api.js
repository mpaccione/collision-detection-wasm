const cors = require('cors');
const express = require("express");
const fs = require('fs');
const wasm = fs.readFileSync('./a.out.wasm');
const app = express();

app.use(cors());

app.get("/wasm", function(req, res, next) {
	console.log('WASM Endpoint Requested');
	console.log(wasm);
	res.writeHead(200, {'Content-Type': 'application/wasm'});
	res.end(wasm);
});

app.listen(5000, () => console.log('Example app listening on port 5000!'))