var $ = require("jquery");
var socket = require('socket.io-client')();



socket.on('updateContent', function(data) {
	$('#main').html(data.content);
});



$('#content-editor').on('keyup', function() {
	var content = $(this).val();
	$('#main').html(content);
	socket.emit('onKeyUp', { content: content});
});