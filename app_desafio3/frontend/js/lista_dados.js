function updateList(dados){
	$("#listTable tbody").empty()
	var table_html = ''

	dados.forEach(function(item, index){
		table_html += "<tr>"
		table_html += "<th>" + index + "</th>"
		table_html += "<th>" + item.ip + "</th>"
		table_html += "<th>" + item.pmc_alm + "</th>"
		table_html += "<th>" + item.alm_stat + "</th>"
		table_html += "<th>" + item.emg_stat + "</th>"
		table_html += "<th>" + item.run_stat + "</th>"
		table_html += "<th>" + item.motion_stat + "</th>"
		table_html += "<th>" + item.time + "</th>"
		table_html += "<th>" + item.date + "</th>"
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