def solve1():
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

def solve2():
    def find_number(line, left_to_right=True):
        rng = range(len(line)) if left_to_right else range(len(line)-1,0-1,-1)
        d = {
            "one": 1,
            "two": 2,
            "three": 3,
            "four": 4,
            "five": 5,
            "six": 6,
            "seven": 7,
            "eight": 8,
            "nine": 9
        }
        for i in rng:
            if line[i] in "0123456789":
                return line[i]
            for word, num in d.items():
                if line[i:].startswith(word):
                    return num

        

    with open("./01.input") as fp:
        lines = fp.readlines()
    
    sum = 0
    for line in lines:
        if line.strip() == "":
            continue
        sum += int(f"{find_number(line)}{find_number(line, left_to_right=False)}")
    
    print(sum)

solve2()
