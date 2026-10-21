   const people = [
  { name: "Rahul", age: 25, city: "Mumbai" },
  { name: "Priya", age: 28, city: "Delhi" },
  { name: "Amit", age: 30, city: "Pune" },
  { name: "Snehal", age: 22, city: "Bangalore" }
];



people[1].name = "Sumit"
people[2].age =21;
delete(people[1]);
people[2].email = "Ramdas@gmail.com"

// for(let person of people)
// {
//     console.log(person)
// }

const person = {
    name: "Rahul",
    age: 25,
    city: "Mumbai"
};

const str = JSON.stringify(person);

console.log(str);
console.log(typeof str);


const str1 = '{"name":"Rahul","age":25,"city":"Mumbai"}';

const person1 = JSON.parse(str);

console.log(person1);
console.log(person1.name);
console.log(typeof person1);

