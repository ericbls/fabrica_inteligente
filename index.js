const express = require('express');
const cors = require('cors');
const api = express();

api.use(cors());

api.get('/rand', function(req, res){
	var rand = Math.random();
	console.log(rand);
	res.send(rand.toString());
});

api.listen(7000, ()=>(console.log('Escutando na porta 7000')));

