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

/* I know this could be a one-liner but I don't */
const solve2 = (xs, is_gen_rating) => {
  for (let i of [...Array(xs[0].length).keys()]) {
    if (xs.length === 2) {
      return xs.filter((v) => v[i] === (is_gen_rating ? "1" : "0"));
    }
    const most_used =
      xs.filter((v) => v[i] === "1").length >=
      xs.filter((v) => v[i] === "0").length
        ? "1"
        : "0";
    const least_used = most_used === "1" ? "0" : "1";
    const wanted = is_gen_rating ? most_used : least_used;
    xs = xs.filter((x) => x[i] === wanted);
  }
};

console.log(
  parseInt(solve2(input, true), 2) * parseInt(solve2(input, false), 2)
);
