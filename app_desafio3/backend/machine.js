const mysql = require('mysql');

var connection = mysql.createConnection({
  host     : 'localhost',
  user     : 'ubuntu',
  password : 'buonpater7'
});

function getall(req,res){
	connection.query('SELECT * FROM desafio3.Dados', function(error, results){
		if(error){
			res.sendStatus(500);
		} else {
			res.send(results);
		}
	})
}

function add_machine(req,res){
	let values = '"' + req.body.fabricante +'","' + req.body.modelo +'","' + req.body.ip + '"';

	connection.query('INSERT INTO desafio3.Maquinas(Fabricante, Modelo, ip) VALUES (' + values + ')', function(error, results){
	 	if (error){
			console.log(error);
	 		res.sendStatus(500);
	 	} else {
			res.send(req.body);
		}
	 })
}

function add_data(req,res){
	let values = '"' + req.body.id + '"," + req.body.ip + '","' + req.body.pmc_alm +'","' + req.body.alm_stat + '","' + req.body.emg_stat + '","' + req.body.run_stat + '","' + req.body.motion_stat + '";
	connection.query('INSERT INTO desafio3.Dados(id, ip, pmc_alm, alm_stat, emg_stat, run_stat, motion_stat) VALUES (' + values + ')', function(error, results){
		if(error){
			console.log(error);
			res.sendStatus(500);
		} else{
			res.send(req.body);
		}
	})
}

module.exports = {getall, add_machine, add_data}
