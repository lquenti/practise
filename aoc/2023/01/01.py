with open("./01.input") as fp:
    lines = fp.readlines()

sum = 0
for line in lines:
    if line.strip() == "":
        continue
    # find leftmost
    for i in range(len(line)):
        if line[i] in "0123456789":
            left = line[i]
            break
    # find rightmost
    for i in range(len(line)-1, 0-1, -1):
        if line[i] in "0123456789":
            right = line[i]
            break
    if left is None or right is None:
        raise Exception(line)
    sum += int(f"{left}{right}")

print(sum)
