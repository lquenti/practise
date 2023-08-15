from collections import defaultdict

COWS = sorted(["Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"])
N = len(COWS)

def parse_line(line):
    words = line.split(" ")
    return words[0], words[-1]

def build_line_from_node(lookup, v):

    assert len(lookup[v]) == 1
    line = [v, lookup[v][0]]
    while True:
        last = line[-1]
        before_that = line[-2]

        neighbours = lookup[last].copy()
        neighbours.remove(before_that)

        if len(neighbours) == 0:
            break
        assert len(neighbours) == 1
        line.append(neighbours[0])
    return None if line[-1] < line[0] else tuple(line)


with open("lineup.in", "r") as fp:
    lines = fp.readlines()

k = len(lines)-1

constraints = [parse_line(line.strip()) for line in lines[1:]]

lookup = {c: [] for c in COWS}
for a, b in constraints:
    lookup[a].append(b)
    lookup[b].append(a)

visited_vec = [False] * 7
lines = []
for v in COWS:
    deg = len(lookup[v])
    if deg == 2:
        continue
    elif deg == 0:
        # this is a full path
        lines.append((v,))
    else: # deg == 1
        newline = build_line_from_node(lookup, v)
        if newline is not None:
            lines.append(newline)

with open("lineup.out", 'w') as fp:
    for l in lines:
        for c in l:
            fp.write(c + '\n')
# 1. wir bilden das dict
# 2. Wir finden einen Pfad
#    if deg(0): return
#    if deg(1): build_line_from_path(), dann richtig herum sortieren
#    if deg(2): continue
# 3. wir verbinden die linien alphabetisch optimal

# merge lines

