const machine = require('./machine');

exports.build = function(server){

  server
  	.get('api/maquina', 	machine.getall)
    .post('api/maquina', 	machine.add)