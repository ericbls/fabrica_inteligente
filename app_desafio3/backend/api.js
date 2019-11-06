const machine = require('./machine');

exports.build = function(server){

  server
  	.get('/desafio3/info/cadastro', machine.get_data)
    .post('/desafio3/info/cadastro', machine.add_machine)
    .get('/desafio3/info/dados', machine.get_machine)
    .post('/desafio3/info/dados', machine.add_data)
}
