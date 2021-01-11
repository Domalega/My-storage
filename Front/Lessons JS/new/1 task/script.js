function Calculator() {
    this.read = function () {
        this.firstValue = +prompt("Введите первое значение", "");
        this.secondValue = +prompt("Введите второе значение", "");
    }
    this.sum = function () {
        return this.firstValue + this.secondValue;
    }
    this.mul = function () {
        return this.firstValue * this.secondValue;
    }
}

let calculator = new Calculator();
calculator.read();

alert("Sum = " + calculator.sum());
alert("Mul = " + calculator.mul());