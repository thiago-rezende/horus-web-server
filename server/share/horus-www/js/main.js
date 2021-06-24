function greet() {
    name = document.getElementById('input__name').value;

    if (name != '')
        alert('Hello, ' + name + '!');
    else
        alert('Hello!');
}
