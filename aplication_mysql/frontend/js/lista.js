function updateList(dados){
	$("#listTable tbody").empty()
	var table_html = ''

	dados.forEach(function(item, index){
		table_html += "<tr>"
		table_html += "<th>" + index + "</th>"
		table_html += "<th>" + item.Fabricante + "</th>"
		table_html += "<th>" + item.Modelo + "</th>"
		table_html += "<th>" + item.ip + "</th>"
		table_html += "</tr>"
	})
	$("#listTable tbody").html(table_html);
}


$(document).ready(function(){
	$.ajax({
		method: "GET",
		url: "/exemplo/api/maquina",
	}).done(function(resp){
		updateList(resp);
	})
	.fail(function() {
    	alert( "error" );
  	})
})