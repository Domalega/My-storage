function getMaxSubSum(arr) {
    let max = 0,
        temp = 0;
    for (let i of arr) {
        temp += i;
        max = Math.max(temp, max);
        if (temp < 0) temp = 0;
    }
    return max;
}

alert(getMaxSubSum([-1, 2, 3, -9]));
alert(getMaxSubSum([-1, 2, 3, -9, 11]));
alert(getMaxSubSum([-2, -1, 1, 2]));
alert(getMaxSubSum([100, -9, 2, -3, 5]));
alert(getMaxSubSum([1, 2, 3]));
alert(getMaxSubSum([-1, -2, -3]));