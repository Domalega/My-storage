function checkSpam(str) {
    if (str.toLowerCase().includes("viagra") == true || str.toLowerCase().includes("xxx") == true)
        return true;
    return false;
}

alert(checkSpam('buy ViAgRA now'));
alert(checkSpam('free xxxxx'));
alert(checkSpam("innocent rabbit"));