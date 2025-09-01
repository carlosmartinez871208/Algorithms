let string1 = "Hello";
let string2 = "World";
let combinedString = string1 + " " + string2; // "Hello World"
console.log(combinedString);

//or
let greeting = "Hello";
greeting += " World!"; // "Hello World!"
console.log(greeting);

//or
let name = "Ninmah";
let age = 5;
let message = `My name is ${name} and I am ${age} years old.`;
console.log(message);

//or
let part1 = "Good";
let part2 = "Morning";
let fullGreeting = part1.concat(" ", part2); //
console.log(fullGreeting);

//or
let words = ["JavaScript", "is", "fun"];
let sentence = words.join(" "); // "JavaScript is fun"
console.log(sentence);