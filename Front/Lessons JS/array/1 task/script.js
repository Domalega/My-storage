function sumInput() {
    let arr = [],
        sum = 0;
    while (true) {
        let input = prompt("Введите числа", "");
        if (input === "" || input === null || !isFinite(input)) break;
        arr.push(+input);
    }
    for (let i of arr) sum += i;
    return sum;
}

alert(sumInput());