window.onload = function(){
    var todoList = [];

    document.getElementById("add").onclick = function() {
        var d = document.getElementById("in").nodeValue;
        var temp = {};
        temp.todo = d;
        temp.check = false;
        var i = todoList.length;
        todoList[i] = temp;
        console.log(todoList);
    }
}