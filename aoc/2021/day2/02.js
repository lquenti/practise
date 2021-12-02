const fs = require("fs");
const input = fs
  .readFileSync(process.cwd() + "/input")
  .toString()
  .split("\n")
  .slice(0, -1);

const height1 = input
  .filter((v) => v.startsWith("up") || v.startsWith("down"))
  .map((v) => parseInt(v.split(" ")[1]) * (v.startsWith("up") ? -1 : 1))
  .reduce((a, b) => a + b);

const length = input
  .filter((v) => v.startsWith("forward"))
  .map((v) => parseInt(v.split(" ")[1]))
  .reduce((a, b) => a + b, 0);

console.log(height1 * length);

const solution2 = input.reduce(
  (a, v) => {
    const n = parseInt(v.split(" ")[1]);
    if (v.startsWith("up")) {
      return { ...a, aim: a.aim - n };
    } else if (v.startsWith("down")) {
      return { ...a, aim: a.aim + n };
    }
    return {
      ...a,
      horizontal: a.horizontal + n,
      depth: a.depth + a.aim * n,
    };
  },
  {
    horizontal: 0,
    depth: 0,
    aim: 0,
  }
);

console.log(solution2.horizontal * solution2.depth);
