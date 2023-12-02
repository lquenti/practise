REDS = 12
GREENS = 13
BLUES = 14

def solve01():
    with open("./02.input", 'r') as fp:
        lines = fp.readlines()
    
    ret = 0
    for line in lines:
        # Get the "Game XXX:"
        game, tail = line.split(":", 1)
        game_id = int(game.rsplit(" ", 1)[1])
    
        # get the hands
        hands = tail.split(";")
        all_hands_valid = True
        for hand in hands:
            # get all colors
            colors = [color.strip() for color in hand.split(",")]
    
            for color in colors:
                # Check if valid
                n, curr_clr = color.split(" ")
                n = int(n)
                if curr_clr == "red" and n > REDS:
                    all_hands_valid = False
                if curr_clr == "blue" and n > BLUES:
                    all_hands_valid = False
                if curr_clr == "green" and n > GREENS:
                    all_hands_valid = False
        if all_hands_valid:
            ret += game_id
    
    print(ret)

def solve02():
    with open("./02.input", 'r') as fp:
        lines = fp.readlines()
    
    ret = 0
    for line in lines:
        # Get the "Game XXX:"
        game, tail = line.split(":", 1)
        game_id = int(game.rsplit(" ", 1)[1])
    
        # get the hands
        hands = tail.split(";")
        minimal_blues = 0
        minimal_reds = 0
        minimal_greens = 0
        for hand in hands:
            # get all colors
            colors = [color.strip() for color in hand.split(",")]
    
            for color in colors:
                # Check if valid
                n, curr_clr = color.split(" ")
                n = int(n)
                if curr_clr == "red":
                    minimal_reds = max(n, minimal_reds)
                if curr_clr == "blue":
                    minimal_blues = max(n, minimal_blues)
                if curr_clr == "green":
                    minimal_greens = max(n, minimal_greens)
    
        ret += minimal_blues * minimal_greens * minimal_reds
    print(ret)

solve02()
