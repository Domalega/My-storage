var userInput = prompt("Кто?", "");
if (userInput == "Админ") {
    var password = prompt("Введите пароль"< "");
    if (password == "Я главный") {
        alert("Здравствуй!")
    } else if (password == null || password == " ") {
        alert("Отмена")
    } else {
        alert("Неверный пароль")
    }
} else if (userInput == null || userInput == " ") {
    alert("Отмена")
} else {
    alert("Я вас не знаю");
}