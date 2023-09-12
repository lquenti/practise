# http://www.usaco.org/index.php?page=viewproblem2&cpid=894
def main():

    # build bidirectional graph
    with open('planting.in', 'r') as fp:
        lines = fp.readlines()
        N = int(lines[0])
        lines = lines[1:]

    degree = [0] * (N+1)

    for line in lines:
        a,b = [int(x) for x in line.split(" ")]
        degree[a] += 1
        degree[b] += 1

    biggest_color = max(degree) + 1

    with open('planting.out', 'w') as fp:
        fp.write(str(biggest_color))

    #   /--\
    # 1-2-3-4
    # \--/

if __name__ == '__main__':
    main()