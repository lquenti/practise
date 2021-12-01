const fs = require("fs");
const input = fs
  .readFileSync(process.cwd() + "/input1")
  .toString()
  .split("\n")
  .filter((val) => val.trim !== "")
  .map((val) => parseInt(val));

const solve = (xs) => {
  let res = 0;

  xs.reduce((prev, curr) => {
    if (curr > prev) {
      res += 1;
    }
    return curr;
  });
  console.log(res);
};

solve(input);
solve(
  input
    .map((_, i) => input[i] + input[i + 1] + input[i + 2])
    .filter((v) => v !== undefined)
);
