function createTable(){
	var row = parseInt(document.getElementById('row').value);
	var col = parseInt(document.getElementById('col').value);

	var tab = document.createElement("table");
	var tbody = document.createElement("tbody");
	tab.appentChild(tbody);
	for(var i = 0; i < row; i++)
	{
		
	}
	document.getElementById("parentContainer").appentChild(tab);

}