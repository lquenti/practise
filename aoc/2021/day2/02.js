const fs = require("fs");
const input = fs
  .readFileSync(process.cwd() + "/input")
  .toString()
  .split("\n")
  .slice(0, -1);

const height = input
  .filter((v) => v.startsWith("up") || v.startsWith("down"))
  .map((v) => parseInt(v.split(" ")[1]) * (v.startsWith("up") ? -1 : 1))
  .reduce((a, b) => a + b);

const length = input
  .filter((v) => v.startsWith("forward"))
  .map((v) => parseInt(v.split(" ")[1]))
  .reduce((a, b) => a + b, 0);

console.log(height * length);
