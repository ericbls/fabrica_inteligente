function updateList(dados){
	$("#listTable tbody").empty()
	var table_html = ''

	dados.forEach(function(item, index){
		table_html += "<tr>"
		table_html += "<th>" + index + "</th>"
		table_html += "<th>" + item.fabricante + "</th>"
		table_html += "<th>" + item.modelo + "</th>"
		table_html += "<th>" + item.ip + "</th>"
		table_html += "</tr>"
	})
	$("#listTable tbody").html(table_html);
}


$(document).ready(function(){
	$.ajax({
		method: "GET",
		url: "/desafio3/info/dados",
	}).done(function(resp){
		updateList(resp);
	})
	.fail(function() {
    	alert( "error" );
  	})
})