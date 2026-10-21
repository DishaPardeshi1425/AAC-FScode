let name = document.getElementById("name");
let age = document.getElementById("age");

let sub = document.getElementById("submit");
let res = document.getElementById("res");

function details() {

    let sal = Number(document.getElementById("sal").value);

    let da = 0.12 * sal;
    let hra = 0.30 * sal;
    let gross = sal + da + hra;
    let pf = 0.12 * sal;

    res.innerHTML =
        "Employee Name: " + name.value + "<br>" +
        "Employee Age: " + age.value + "<br>" +
        "Basic Salary: " + sal + "<br>" +
        "DA: " + da + "<br>" +
        "HRA: " + hra + "<br>" +
        "Gross: " + gross + "<br>" +
        "PF: " + pf;

    return false;
}
