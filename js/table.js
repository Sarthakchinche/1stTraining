var n;
var tab;
var tbody;
var tr;
var count = 1;
var flag = 1;
var flag1 = 1;

function reload() {
    location.reload();
}
function createForm1() {
    if(flag1==1){
        flag1 =0;
    n = parseInt(document.getElementById("colNum").value);
    var form1 = document.createElement("form");
    var header = document.createElement("h2");
    header.innerHTML = "Add The name of attributes please.";
    form1.name = "headForm";
    // form1.onsubmit = "return createTable()"
    var str="";
    for(var i = 1 ; i <= n+1 ; i++) {
            if(i==n+1){
                str += '<button type = "button" onclick = "createTable()">CLICK HERE</button>'
            } else {
                str += '<input type="text" name="name'+i+'" id="id'+i+'" placeholder="'+i+' ATTRIBUTE">'
            }
    }
    form1.innerHTML = str;
    document.getElementById("parentContainer").appendChild(header);
    document.getElementById("parentContainer").appendChild(form1);
    }
};

function createTable(){
    tab = document.createElement("table");
    // console.log("Shanti");
    tab.border = "1";
    // console.log(n);
    tab.style.borderCollapse = "Collapse";
    tbody = document.createElement("tbody");
    tbody.id = "tbody";
    tr = document.createElement("tr");
    tr.id = "tr"+count;
    count ++;
    // console.log("Shanti");
    var col = n;
    for(var i = 0 ; i < col ; i++){
        var th = document.createElement("th");
        // console.log("hahaha");
        th.innerHTML = document.getElementById("id"+(i+1)).value;
        // console.log(document.getElementById("id"+(i+1)).value);
        tr.appendChild(th);
    }
    tbody.appendChild(tr);
    tab.appendChild(tbody);
    var butt = document.createElement("p")
    butt.innerHTML = '<button type = "button" onclick = "addData()">CLICK HERE TO ADD DATA</button>';
    // tab.appendChild(butt);
    document.getElementById("parentContainer").appendChild(tab);
    document.getElementById("parentContainer").appendChild(butt);
    // return false;
}

function createFTable(){
    tr = document.createElement("tr");
    tr.id = "tr"+count;
    count++; 
    for(var i = 0 ; i <= n ; i++){
        var td = document.createElement("td");
        // console.log("hahaha");
        if(i == n){
            td.innerHTML = '<button type = "button" onclick = "deleteIt()">DELETE DATA</button>';
        }else {
        td.innerHTML = document.getElementById("row"+(i)).value;
        }
        // console.log(document.getElementById("id"+(i+1)).value);
        tr.appendChild(td);
    }
    tbody.appendChild(tr);
}

function deleteIt() {
    var x = document.activeElement.parentNode.parentNode.id;
    console.log(x);
    var rem = document.getElementById(x);
        // console.log(id);
    var parentNode = document.getElementById("tbody");
        // console.log(id);
    rem.parentNode.removeChild(rem);
}

function addData(){
    if(flag == 1){
        flag = 0;
        console.log("YE chala");
        var form2 = document.createElement("form");
        var head2 = document.createElement("h2");
        head2.innerHTML = "Please ADD the data here";
        form2.name = "RowData";
        str = "";
        for(var i = 0; i<n ; i++){
                var name = document.getElementById("id"+(i+1)).value;
                str += name+':'+'<input type="text" name="name2'+i+'" id="row'+i+'" placeholder="'+(i+1)+' ATTRIBUTE">';
        }
        str += '<button type = "button" onclick = "run()">CLICK HERE</button>'
        form2.innerHTML = str;
        document.getElementById("rowData").appendChild(head2);
        document.getElementById("rowData").appendChild(form2);
    }
}

function run(){
    createFTable();
    for( var i = 0 ; i < n ; i ++){
        document.getElementById('row'+i).value = '';
    }
}

function createIt(){
    
    // console.log(rows);
    for(var i = 0;i<rows;i++){
        var tr = document.createElement('tr');
        
        tbody.appendChild(tr);
        for(var j = 0 ; j< col ; j++){
            var td = document.createElement("td");
            
            td.innerHTML = "test";
            tbody.appendChild(td);
        }
    }
    document.getElementById("parentContainer").appendChild(tab);
}
