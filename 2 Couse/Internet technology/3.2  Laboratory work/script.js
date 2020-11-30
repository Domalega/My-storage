window.addEventListener("load", () => {
    setCookie("count", +getCookie("count") + 1);
});

window.addEventListener("unload", () => {
    setCookie("time", new Date());
});

function main() {
    document.getElementById("reg").classList = "hide";
    document.getElementById("unreg").classList = "hide";

    const user = getCookie("user");
    const count = +(getCookie("count") || 0) + 1;
    
    var limit = 2;
    document.getElementById("count").style.color = "black";
    if (count > limit)
        document.getElementById("count").style.color = "red";
    if (count == limit)
        document.getElementById("count").style.color = "orange";
           
    document.getElementById("name").innerText = user;
    document.getElementById("count").innerText = count;
    document.getElementById("time").innerText =
        getCookie("time") || new Date();

    if (user) {
        document.getElementById("reg").classList = "show";
    } else {
        document.getElementById("unreg").classList = "show";
    }

    document.getElementById("exit").onclick = () => {
        setCookie("user", "");
        setCookie("count", "");
        setCookie("time", "");
        main();
    };

    document.getElementById("register").onclick = () => {
        const name = document.getElementById("input").value;
        setCookie("user", name);
        main();
    };
}

function setCookie(name, value) {
    document.cookie = `${name}=${value};`;
}

function getCookie(name) {
    const cookies = document.cookie.split(";");
    return cookies
        .find((x) => x.trim().startsWith(name + "=")) 
        .replace(name + "=", "")
        .trim();
}