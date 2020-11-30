var flag = 0;

function stop() {
    if (flag > 2)
        alert("Запрет на выполнение!");
}

function backgroundcolor(i) {
    document.body.classList.add("backgroundColor" + i);
    flag++;
    if (i == 1 && flag == 0) {
        document.body.classList.remove("backgroundColor2");
        document.body.classList.remove("backgroundColor3");
        document.body.classList.remove("backgroundColor4");
    }
    if (i == 2) {
        document.body.classList.remove("backgroundColor1");
        document.body.classList.remove("backgroundColor3");
        document.body.classList.remove("backgroundColor4");
    }
    if (i == 3) {
        document.body.classList.remove("backgroundColor1");
        document.body.classList.remove("backgroundColor2");
        document.body.classList.remove("backgroundColor4");
    }
    if (i == 4) {
        document.body.classList.remove("backgroundColor1");
        document.body.classList.remove("backgroundColor2");
        document.body.classList.remove("backgroundColor3");
    }
}

function colorText(i) {
    document.body.classList.add("colorText" + i);
    if (i == 1) {
        document.body.classList.remove("colorText2");
        document.body.classList.remove("colorText3");
    }
    if (i == 2) {
        document.body.classList.remove("colorText1");
        document.body.classList.remove("colorText3");
    }
    if (i == 3) {
        document.body.classList.remove("colorText1");
        document.body.classList.remove("colorText2");
    }
}

function fontSize(i) {
    document.body.classList.add("font" + i);
    if (i == 1) {

        document.body.classList.remove("font2");
        document.body.classList.remove("font3");
    }
    if (i == 2) {

        document.body.classList.remove("font1");
        document.body.classList.remove("font3");
    }
    if (i == 3) {

        document.body.classList.remove("font1");
        document.body.classList.remove("font2");
    }
}

function Menu(i) {
    if (i == 1) {
        document.getElementById("myDropdown").classList.toggle("show");
        document.getElementById("myDropdown1").classList.remove("show");
        document.getElementById("myDropdown2").classList.remove("show");
    }
    if (i == 2) {
        document.getElementById("myDropdown").classList.remove("show");
        document.getElementById("myDropdown1").classList.toggle("show");
        document.getElementById("myDropdown2").classList.remove("show");
    }
    if (i == 3) {
        document.getElementById("myDropdown").classList.remove("show");
        document.getElementById("myDropdown1").classList.remove("show");
        document.getElementById("myDropdown2").classList.toggle("show");
    }
}

window.onclick = function (event) {
    if (!event.target.matches(".dropButton")) {
        var dropdowns = document.getElementsByClassName("dropdown-content");
        var i;
        for (i = 0; i < dropdowns.length; i++) {
            var openDropdown = dropdowns[i];
            if (openDropdown.classList.contains("show")) {
                openDropdown.classList.remove("show");
            }
        }
    }
}