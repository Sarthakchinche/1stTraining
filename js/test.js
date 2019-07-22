var count = 1;
var iDiv ;      
function addIt(){
iDiv = document.createElement('div');
iDiv.id = 'block_'+(count);
iDiv.innerHTML = "<style>body{}#parentContainer{background-color:lightgray;border:2px solid black;max-width:500px;}</style> <input style='border-radius:5px;width:250px;' type = 'text'> <button onclick = 'removeIt()'>Remove this field</button> ";
// document.getElementsByTagName("h1").innerHTML = iDiv.id;
document.getElementById("parentContainer").appendChild(iDiv);
count++;
}



function removeIt(){
        id = "block_"+(count-1);
        // console.log(id);
        var rem = document.getElementById(id);
        // console.log(id);
        parentNode = document.getElementById("parentContainer");
        // console.log(id);
        rem.parentNode.removeChild(rem);
        count--;
}