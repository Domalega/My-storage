function readNumberRecursion() {
    let value = prompt("Введите число", "")
    if (isFinite(value) == true) {
        if (value != null && value != " ")
            readNumberRecursion();
        else
            return null;
    }
    return value;
}

function readNumber() {
    do {
        let value = prompt("Введите число", "")
    } while (!isFinite(value))
    if (value === null || value === "")
        return null;
    else return value;
}


let choise = prompt("Да - рекурсивно/ нет - не рекурсивно", "");
if (choise === null || choise === "")
    alert("Отмена", "");
else {
    if (choise.toLowerCase() == "нет" || choise.toLowerCase() == "ytn")
        alert(`Число ${readNumber()}`, "")
    if (choise.toLowerCase() == "да" || choise.toLowerCase() == "lf")
        alert(`Число ${readNumberRecursion()}`, "")
    else alert("Ошибка", "");
}