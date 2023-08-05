const getRequest = async()=>
{
var inputvalue = document.getElementById('inputval').value;

// console.log(inputvalue);
  
var select = document.getElementById("select");
select.innerHTML = '';
const response = await axios.get('searchvalues' , {
    params: { "values" : inputvalue } 
})


// document.getElementById('myid').innerHTML = response.data.returnvalues[1];

var select = document.getElementById("select");

console.log(response.data.returnvalues[0])
for (const val of response.data.returnvalues)
{
    var option = document.createElement("option");
    option.value = val;
    option.text = val.charAt(0).toUpperCase() + val.slice(1);
    select.appendChild(option);
}
}