const fs = require("fs");
const input = fs.readFileSync(process.cwd() + "/input1").toString();

let res = 0;

input
  .split("\n")
  .filter((val) => val.trim() !== "")
  .map((val) => parseInt(val))
  .reduce((prev, curr) => {
    if (curr > prev) {
      res += 1;
    }
    return curr;
  });
console.log(res);
