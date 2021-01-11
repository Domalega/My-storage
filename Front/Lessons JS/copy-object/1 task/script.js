let obj = {
    value1: 200,
    value2: 122,
    important_value: {
        super_value1: "Hello, world!",
        super_value2: "Deep copy"
    }
}

let clone = {}

for (let key in obj) {
    clone[key] = obj[key]; // ????
}

alert(clone.important_value.super_value1);

console.log(clone);
console.log(obj);