import sys

def solve01():
    with open(sys.argv[1], "r") as fp:
        lines = fp.readlines()
    ret = 0
    for card in lines:
        numbers = card.split(":")[1].strip()
        winning_numbers, my_numbers = numbers.split("|")
        winning_numbers = [int(x) for x in winning_numbers.strip().split(" ") if x.strip() != ""]
        my_numbers = [int(x) for x in my_numbers.strip().split(" ") if x.strip() != ""]

        current_wins = 0
        for w in winning_numbers:
            if w in my_numbers:
                current_wins = 1 if current_wins == 0 else current_wins*2
        ret += current_wins
    print(ret)

def solve02():
    with open(sys.argv[1], "r") as fp:
        lines = fp.readlines()
    cards = [None] # 1 based

    # get all cards
    for card in lines:
        numbers = card.split(":")[1].strip()
        winning_numbers, my_numbers = numbers.split("|")
        winning_numbers = [int(x) for x in winning_numbers.strip().split(" ") if x.strip() != ""]
        my_numbers = [int(x) for x in my_numbers.strip().split(" ") if x.strip() != ""]
        cards.append((winning_numbers, my_numbers))

    ret = 0
    queue = [*range(1, len(cards))]
    while len(queue) != 0:
        ret += 1
        curr = queue.pop(0)
        winning_numbers, my_numbers = cards[curr]
        current_wins = 0
        for w in winning_numbers:
            if w in my_numbers:
                current_wins += 1
        if current_wins == 0:
            continue
        for i in range(curr+1, curr+current_wins+1):
            queue.append(i)
    print(ret)


        

solve01()
solve02()
