const express       = require('express');
const routes 		= require('./routes/api.js');
const bodyParser    = require('body-parser');

var api = express();

api.set('port', process.env.PORT || 5000);

api.use(bodyParser.json());

routes.build(api);

api.listen(api.get('port'));
module.exports = api;

