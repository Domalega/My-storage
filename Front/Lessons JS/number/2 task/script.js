let random = function random(firstValue, secondValue) {
    return firstValue + Math.random() * (secondValue - firstValue);
};

function randomInteger(randomNumber) {
    return Math.round(randomNumber);
}

let randomNumber = random(1, 5);
alert(`${randomNumber} ,${randomInteger(randomNumber)} `);