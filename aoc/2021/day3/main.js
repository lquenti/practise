const fs = require("fs");
const input = fs
  .readFileSync(process.cwd() + "/input")
  .toString()
  .split("\n")
  .slice(0, -1);

const gamma = [...Array(input[0].length).keys()]
  .map((i) => input.map((v) => v[i]))
  .map((xs) =>
    xs.filter((v) => v === "1").length >= xs.filter((v) => v === "0").length
      ? "1"
      : "0"
  );

const epsilon = gamma.map((v) => (v === "0" ? "1" : "0"));

console.log(parseInt(epsilon.join(""), 2) * parseInt(gamma.join(""), 2));
