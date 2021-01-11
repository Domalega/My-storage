function truncate(str, maxLength) {
    let newstr = " ";
    if (str.length >= maxLength) {
        for (let i = 0; i < maxLength - 1; i++) {
            newstr += str[i];
        }
        return newstr + "..";
    }
    return str;
}

alert(truncate("Вот, что мне хотелось бы сказать на эту тему:", 20));
alert(truncate("Всем привет!", 20));