let flag = true;

function setClock() {
    var text = "";
    var openImage = "<img src=\"" + getPath(location.href) + "assets/dg"
    var closeImage = ".gif\" height=21 width=16>"
    var date = new Date();
    var hour = date.getHours();
    var minute = date.getMinutes();
    var second = date.getSeconds();
    var date = null;
    ampm = "";
    if (hour > 12)
        ampm = "pm";

    else
        ampm = "am";
    hour = (hour == 24) ? 0 : hour;
    if (hour < 10)
        hour = "0" + hour;
    if (minute < 10)
        minute = "0" + minute;
    if (second < 10)
        second = "0" + second;
    second += "";
    document.getElementById("second1").src = 'assets/dg' + second.charAt(i) + '.gif';
    minute += "";
    document.getElementById("minute1").src = 'assets/dg' + minute.charAt(i) + '.gif';
    hour += "";
    document.getElementById("hour1").src = 'assets/dg' + hour.charAt(i) + '.gif';
    for (var i = 0; i < hour.length; ++i)
        document.getElementById("hour").src = 'assets/dg' + hour.charAt(i) + '.gif';
    for (var i = 0; i < minute.length; ++i)
        document.getElementById("minute").src = 'assets/dg' + minute.charAt(i) + '.gif';
    for (var i = 0; i < second.length; ++i)
        document.getElementById("second").src = 'assets/dg' + second.charAt(i) + '.gif';
    document.getElementById("ampm").src = 'assets/dg' + ampm + '.gif';
    setTimeout("setClock()", 200);
    return text;
}

function setDate() {
    text = "";
    openImage = "<img src=\"" + getPath(location.href) + "assets/dg";
    closeImage = ".gif\" height=21 width=16>";
    now = new Date();
    date = now.getDate();
    month = now.getMonth();
    year = now.getFullYear();
    now = null;
    month++;
    if (flag) {
        date += "";
        document.getElementById("day1").src = 'assets/dg' + date.charAt(i) + '.gif';

        month += "";
        document.getElementById("month1").src = 'assets/dg' + month.charAt(i) + '.gif';
    }
    year += "";
    document.getElementById("year1").src = 'assets/dg' + year.charAt(i) + '.gif';

    for (var i = 0; i < year.length; ++i)
        document.getElementById("year").src = 'assets/dg' + year.charAt(i) + '.gif';
    if (flag) {
        for (var i = 0; i < date.length; ++i)
            document.getElementById("day").src = 'assets/dg' + date.charAt(i) + '.gif';

        for (var i = 0; i < month.length; ++i)
            document.getElementById("month").src = 'assets/dg' + month.charAt(i) + '.gif';
    }

    setTimeout("setDate()", 200);
    return text;
}

function getPath(url) {
    lastSlash = url.lastIndexOf("/");
    return url.substring(0, lastSlash + 1);
}

function fun1() {
    document.getElementById("day1").src = 'assets/dg0.gif';
    document.getElementById("day").src = 'assets/dg1.gif';
    document.getElementById("month1").src = 'assets/dg0.gif';
    document.getElementById("month").src = 'assets/dg1.gif';
    flag = false
}