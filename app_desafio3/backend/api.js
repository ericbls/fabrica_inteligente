const machine = require('./machine');

exports.build = function(server){

  server
  	//.get('/api/maquina', 	machine.getall)
    .post('/data', 	machine.add_data)