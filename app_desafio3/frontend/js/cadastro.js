function success(){

	var alert  = '<div class="alert alert-success alert-dismissible fade show" role="alert">O cadastro foi realizado com sucesso!' 
	    alert += '<button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span> </button></div>';

	$('.container').prepend(alert);

}

function fail(){
	var alert  = '<div class="alert alert-warning alert-dismissible fade show" role="alert">O cadastro nao pode ser realizado, verifique as opcoes e preencha novamente!' 
	    alert += '<button type="button" class="close" data-dismiss="alert" aria-label="Close"><span aria-hidden="true">&times;</span> </button></div>';

	$('.container').prepend(alert);

}
$(function(){   
      if ($("#fabricante").val() != "" && $("#modelo").val() != "" && $("#ip").val() != "" )
          $("#sub_but").removeAttr("disabled");
      else
          $("#sub_but").attr("disabled", "disabled");      
    })

$(document).ready(function(){

	$("#cadastroForm").on('submit', function(event){
		event.preventDefault();

		var formData = $('#cadastroForm').serializeArray();
		var json = {};

		formData.forEach(function(input_data){
			json[input_data.name] = input_data.value;
		})

		var request = $.ajax({
			method: "POST",
			url: "/desafio3/info/cadastro",
			data: JSON.stringify(json),
			contentType: "application/json",
    		dataType: "json",
		})

		request.fail(function(failed) {
			console.log('FAIL: ', failed)
    		fail();
  		})

  		request.done(function(resp){
			console.log('DONE: ', resp)
			success();
		})

	})
})