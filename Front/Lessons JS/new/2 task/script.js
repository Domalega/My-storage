function Accumulator(startingValue) {
    this.value = startingValue;

    this.read = function () {
        this.value += +prompt("Введите значение, которое хотите прибавить", "");
        return this;
    }
}

let startingValue = +prompt("Введите начальное значение", "")
let accumulator = new Accumulator(startingValue);

accumulator.read().read();
alert(accumulator.value)