const mysql = require('mysql');

var connection = mysql.createConnection({
  host     : 'localhost',
  user     : 'ubuntu',
  password : 'Pa$$w0rd'
});

function getall(req,res){
	connection.query('SELECT * FROM fabricainteligente.Maquinas', function(error, results){
		if(error){
			res.sendStatus(500);
		} else {
			res.send(results);
		}
	})
}

function add(req,res){
	let values = '"' + req.body.fabricante +'","' + req.body.modelo +'","' + req.body.ip + '"';

	connection.query('INSERT INTO fabricainteligente.Maquinas(Fabricante, Modelo, ip) VALUES (' + values + ')', function(error, results){
	 	if (error){
	 		res.sendStatus(500);
	 	} else {
			res.send(req.body);
		}
	 })
}

module.exports = {getall, add}