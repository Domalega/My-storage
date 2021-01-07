let user = {};
user.name = "John";
user.surname = "Smith";

if (user.name == "John" && user.surname == "Smith") {
    alert("True");
    user["name"] = "Pete";
}

alert(user.name);
delete user.name;
alert(user.name);