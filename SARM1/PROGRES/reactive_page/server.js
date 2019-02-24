var express = require('express');
app = express();

var server = require('http').Server(app);
var io = require('socket.io')(server);

var pageContent = "<h1> Hello </h1>";

app.use(express.static('public'));



io.on('connection', function (socket) {
	socket.emit('updateContent', { content: pageContent});
	console.log("after emit serv");

	socket.on('onKeyUp', function(data) {
		pageContent = data.content;
		console.log("plop:" +data.content);
		socket.broadcast.emit('updateContent', { content: pageContent});
	});
});



server.listen(4000, function () {
	console.log('Example app listening on port 4000!');
});