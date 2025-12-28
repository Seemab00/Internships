let display = document.getElementById('display');
let expression = '';

function append(char) {
    expression += char;
    display.value = expression;
}

function operate(op) {
    expression += op;
    display.value = expression;
}

function clearDisplay() {
    expression = '';
    display.value = '';
}

function calculate() {
    try {
        display.value = eval(expression);
        expression = display.value;
    } catch (e) {
        display.value = 'Error';
    }
}


document.addEventListener('keydown', (e) => {
    if (e.key >= '0' && e.key <= '9') append(e.key);
});