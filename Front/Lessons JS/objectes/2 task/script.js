let salaries = {
  John: 100,
  Ann: 160,
  Pete: 130
}

alert(+salaries.John + +salaries.Ann + +salaries.Pete)

let sum = 0;
for (let i in salaries) {
  sum += salaries[i];
}
alert(sum);