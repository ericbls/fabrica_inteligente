const machine = require('./machine');

exports.build = function(server){

  server
  	.get('/cadastro', machine.getall)
    .post('/cadastro', machine.add_machine)
    .post('/dados', machine.add_data)
}