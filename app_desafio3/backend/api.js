const machine = require('./machine');

exports.build = function(server){

  server
  	.get('/desafio3/dados', machine.get_machine)
  	.get('/cadastro', machine.get_data)
    .post('/cadastro', machine.add_machine)
    .post('/desafio3/dados', machine.add_data)
}
