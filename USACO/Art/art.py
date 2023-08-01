from typing import List

def main(lines: List[str]):
    n = int(lines[0])
    lines = lines[1:]
    lines = [[int(x) for x in l.strip()] for l in lines]

    assert len(lines) == n
    for i in range(len(lines)):
        assert n == len(lines[i])

    # find bounding boxes
    bbs = {}
    for color in range(1,10):
        min_x, max_x, min_y, max_y = n + 1, -1, n + 1, -1
        found = False
        for x in range(0, n):
            for y in range(0,n):
                if lines[x][y] == color:
                    found = True
                    min_x = min(min_x, x)
                    max_x = max(max_x, x)
                    min_y = min(min_y, y)
                    max_y = max(max_y, y)
        if found:
            bbs[color] = [min_x, max_x, min_y, max_y]

    # Build dependencies from bbs
    deps = {}
    for i in range(1,10):
        deps[i] = set()

    for color in bbs:
        min_x, max_x, min_y, max_y = bbs[color]
        for x in range(min_x, max_x+1):
            for y in range(min_y, max_y+1):
                if lines[x][y] != color:
                    deps[color].add(lines[x][y])

    # all of left that arent in right
    #print(lines)
    #print(deps)

    # [[1,2], [3,4]] [1,2,3,4]
    all_deps = set()
    for k in deps:
        v = deps[k]
        all_deps = all_deps.union(v)

    res = bbs.keys() - all_deps
    return [len(res)]


"""
1230
1737
2777
0000

7->[3]
2->[7]

for i in 1..=9:
  for x in dict.values():
    if x.contains(i):
      # klappt nicht
  # sonst klappts
"""

# http://www.usaco.org/index.php?page=viewproblem2&cpid=737
if __name__ == '__main__':
    with open("art.in", 'r') as fp:
        lines = fp.readlines()
    res = main(lines)
    with open("art.out", 'w') as fp:
        fp.writelines([str(x) for x in res])
