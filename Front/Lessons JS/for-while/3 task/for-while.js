var userInput = prompt("Введите до какого числа нужно найти все простые числа", "")
nextPrime:
    for (let i = 2; i < userInput; i++) {
        for (let j = 2; j < i; j++) {
            if (i % j == 0) continue nextPrime;
        }
        alert(i);
    }