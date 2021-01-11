let calculator = {
    read() { 
       firstValue = +prompt("Введите первое значение", "")
       secondValue = +prompt("Введите второе занчение","")
    },
    sum() {
        return firstValue + secondValue;
    },
    mul() {
        return firstValue * secondValue;
    }
};

calculator.read();
console.log(calculator.sum());
console.log(calculator.mul());


let calculator_with_this = {
    read() { 
       this.firstValue = +prompt("Введите первое значение", "")
       this.secondValue = +prompt("Введите второе занчение","")
    },
    sum() {
        return this.firstValue + this.secondValue;
    },
    mul() {
        return this.firstValue * this.secondValue;
    }
};

calculator.read();
console.log(calculator.sum());
console.log(calculator.mul());