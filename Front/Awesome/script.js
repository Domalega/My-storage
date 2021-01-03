function Calculate() {
    massiveOfValue = document.getElementById('display-calc').value.split(" ");
    switch (massiveOfValue[1]){
        case "+":
        document.getElementById('display-calc').value = Number(massiveOfValue[0]) + Number(massiveOfValue[2]);
        break;

        case "-":
        document.getElementById('display-calc').value = Number(massiveOfValue[0]) - Number(massiveOfValue[2]);
        break;

        case "*":
        document.getElementById('display-calc').value = Number(massiveOfValue[0]) * Number(massiveOfValue[2]);
        break;

        case "/":
        document.getElementById('display-calc').value = Number(massiveOfValue[0]) / Number(massiveOfValue[2]);
        break;

    }

}

const input_todo = document.querySelector("input-todo")
const btn_todo = document.querySelector("btn-todo")
const result_todo = document.querySelector("result-todo")
const total_todo = document.querySelector("total-todo")


btn_todo.addEventListener("click", (e) => {
    console.log(input_todo.value)


})