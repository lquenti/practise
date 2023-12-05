import sys

def solve01():
    with open(sys.argv[1], "r") as fp:
        lines = fp.readlines()
        lines = [line.strip() for line in lines]

    ret = 0
    number_offsets_found = set()

    N = len(lines)
    for i in range(N):
        N_line = len(lines[i])
        for j in range(N_line):

            # If it is not a symbol, we don't care
            c = lines[i][j]
            if c.isdigit() or c == ".":
                continue

            # So now its a symbol. Lets look around it
            points_around = [
                (i-1, j-1), (i-1, j), (i-1, j+1),
                (i, j-1),             (i, j+1),
                (i+1, j-1), (i+1, j), (i+1, j+1)
            ]
            # upper
            if i != 0:
                points_around.append((i-1, j-1))
                points_around.append((i-1, j))
                points_around.append((i-1, j+1))
            # side
            points_around.append((i, j-1))
            points_around.append((i, j+1))
            # lower
            if i != N-1:
                points_around.append((i+1, j-1))
                points_around.append((i+1, j))
                points_around.append((i+1, j+1))

            for a,b in points_around:
                # does this number exist
                try:
                    lines[a][b]
                except IndexError:
                    continue

                if not lines[a][b].isdigit():
                    continue
                # Now we have a part number!
                # find its start and its end
                start_offset = b
                while start_offset != 0 and lines[a][start_offset-1].isdigit():
                    start_offset -= 1
                end_offset = b
                while end_offset != len(lines[a])-1 and lines[a][end_offset+1].isdigit():
                    end_offset += 1

                # Do we already added it in? If so, ignore
                # else add it in
                starting_coordinate = (a, start_offset)
                if starting_coordinate in number_offsets_found:
                    continue
                str_num = lines[a][start_offset:end_offset+1]
                print(str_num)
                ret += int(str_num)
                number_offsets_found.add(starting_coordinate)
    print(ret)





solve01()
