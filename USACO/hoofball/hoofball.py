from typing import List


def main(lines: List[str]):
    n = int(lines[0])
    xs = [int(x) for x in lines[1].split(" ")]
    xs.sort()

    plays_to_right = [True]
    for i in range(1,n-1):
        plays_to_right.append((xs[i] - xs[i-1]) > (xs[i+1] - xs[i]))
    plays_to_right.append(False)

    res = set()
    for i, k in enumerate(xs):

        gets_from_right = i != n-1 and not plays_to_right[i+1]
        gets_from_left = i != 0 and plays_to_right[i-1]

        # starting point of sequence
        if not gets_from_left and not gets_from_right:
            res.add(k)

        # 2 cows just cycling to each other
        if plays_to_right[i] and gets_from_right and not gets_from_left:
            right_gets_from_right = i != n-2 and not plays_to_right[i+2]
            if not right_gets_from_right:
                res.add(k)



    #print(res)
    return [len(res)]

    """
    # simulate
    cows_reached = []
    for starting_cow in range(n):
        cows_visited = [starting_cow]
        while True:
            current_cow = cows_visited[-1]

            d_left = xs[current_cow] - xs[current_cow-1] if current_cow != 0 else 99999
            d_right = xs[current_cow+1] - xs[current_cow] if current_cow != n-1 else 999999
            if d_right < d_left:
                next_cow = current_cow+1
            else:
                next_cow = current_cow-1

            if len(cows_visited) > 1 and next_cow == cows_visited[-2]:
                break
            cows_visited.append(next_cow)
        cows_reached.append(cows_visited)
    """
    """
    [[0, 1, 2], [1, 2], [2, 1], [3, 2, 1], [4, 3, 2, 1]]

    
    für jede Kuh K können wir feststellen, wer ihr alles zuspielen würde
    wenn niemand, dann müssen wir K zuspielen
    wenn nur einer zuspielt und der nur von K angespielt wird -> einsamer cycle, auch anspielen.    
    
    
    [[0], [4]]
    """

    #print(xs)
    return ["hi"]
"""
x xx   x   x
"""

# http://www.usaco.org/index.php?page=viewproblem2&cpid=808
if __name__ == '__main__':
    with open("hoofball.in", 'r') as fp:
        lines = fp.readlines()
    res = main(lines)
    with open("hoofball.out", 'w') as fp:
        fp.writelines([str(x) for x in res])
