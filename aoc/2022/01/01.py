# pt1
with open("./input", "r") as fp:
    best_known = 0
    current = 0
    for line in fp.readlines():
        if line.strip() == "":
            best_known = max(best_known, current)
            current = 0
        else:
            current += int(line)
    print(f"pt1: {best_known}")

# pt2
with open("./input", "r") as fp:
    all_elvs = []
    current = 0
    for line in fp.readlines():
        if line.strip() == "":
            all_elvs.append(current)
            current = 0
        else:
            current += int(line)
    all_elvs.sort()
    print(f"pt2: {sum(all_elvs[-3:])}")
