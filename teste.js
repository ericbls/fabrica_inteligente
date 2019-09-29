
function update(){
	$.ajax({
		method: "GET",
		url: "http://52.67.164.23/rand"
		})
		.done(function(rand){
			$('div').prepend("<p>"+ rand +"</p>");
		})
}


$(document).ready(function(){

	setInterval(function(){update()}, 1000);

})
