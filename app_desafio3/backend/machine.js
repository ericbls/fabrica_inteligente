const mysql = require('mysql');

var connection = mysql.createConnection({
  host     : 'localhost',
  user     : 'ubuntu',
  password : 'buonpater7'
  database : 'desafio3'
});

function get_data(req,res){
	connection.query('SELECT * FROM desafio3.Dados', function(error, results){
		if(error){
			res.sendStatus(500);
		} else {
			res.send(results);
		}
	})
}

function add_data(req,res){

	console.log(req.body);

	let values = '"' + req.body.maquina_id + '","' + req.body.ip + '","' + req.body.pmc_alm + '","' + req.body.alm_stat + '","' + req.body.emg_stat + '","' + req.body.run_stat + '","' + req.body.motion_stat + '","' + req.body.time + '","' + req.body.date + '"';
	connection.query('INSERT INTO desafio3.Dados(maquina_id, ip, pmc_alm, alm_stat, emg_stat, run_stat, motion_stat, time, date) VALUES (' + values + ')', function(error, results){
		if(error){
			console.log(error);
			res.sendStatus(500);
		} else{
			res.send(req.body);
		}
	})
}

function get_machine(req,res){
	connection.query('SELECT * FROM desafio3.Maquinas', function(error, results){
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

function get_data_from_machine(req, res){
  connection.query("SELECT * FROM desafio3.Dados WHERE maquina_id=" + req.params.id, function(error, results){
    if(error){
      console.log(error);
      res.sendStatus(500);
    } else {
      res.send(results);
    }
  })
}

module.exports = {get_data, get_machine, add_machine, add_data, get_data_from_machine}
