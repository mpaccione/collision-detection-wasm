const cors = require('cors');
const express = require("express");
const fs = require('fs');
const wasm = fs.readFileSync('./a.out.wasm');
const app = express();

app.use(cors());

app.options("wasm", function(req, res, next) {
  res.setHeader("Access-Control-Allow-Origin", "*");
  res.setHeader('Access-Control-Allow-Methods', '*');
  res.setHeader("Access-Control-Allow-Headers", "*");
  res.end();
});

app.get("/wasm", function(req, res, next) {
	console.log('WASM Endpoint Requested');
	res.send(wasm);
});

app.listen(5000, () => console.log('Example app listening on port 5000!'))