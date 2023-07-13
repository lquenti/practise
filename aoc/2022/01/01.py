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
