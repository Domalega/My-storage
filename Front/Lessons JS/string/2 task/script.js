function extractCurrencyValue(Value) {
    if (isNaN(+Value) == true)
        return Value.slice(1);
    return Value;
}

alert(extractCurrencyValue('$100'));
alert(extractCurrencyValue("100"));