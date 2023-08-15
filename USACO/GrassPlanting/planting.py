# http://www.usaco.org/index.php?page=viewproblem2&cpid=894
def main():

    # build bidirectional graph
    with open('planting.in', 'r') as fp:
        lines = fp.readlines()
        N = int(lines[0])
        lines = lines[1:]
    graph = {i: [] for i in range(1,N+1)}
    for line in lines:
        l,r = map(int, line.strip().split(" "))
        graph[l].append(r)
        graph[r].append(l)

    # build graph where every connection == 2 hops
    graph2 = {}
    for v in graph:
        # add our neighbours
        all_neighbours = set(graph[v])

        # add our neighbours neighbours
        for neighbour in graph[v]:
            all_neighbours = all_neighbours.union(set(graph[neighbour]))

        # we are not our neighbour
        all_neighbours.remove(v)
        graph2[v] = all_neighbours

    # greedy coloring
    colors_visited = {}
    queue = [1]
    biggest_color = -1
    while len(queue) > 0:
        current = queue.pop(0)
        if current in colors_visited:
            continue

        # get all forbidden colors
        neighbours = graph2[current]
        all_used_colors = set()
        for n in neighbours:
            if n in colors_visited:
                # if the color is used, we want to know it
                all_used_colors.add(colors_visited[n])
            else:
                queue.append(n)

        if all_used_colors:
            gaps = set(range(1,max(all_used_colors))).difference(all_used_colors)
            if len(gaps) == 0:
                current_color = max(all_used_colors)+1
            else:
                current_color = min(gaps)
        else:
            current_color = 0
        # actual computation we want
        if current_color > biggest_color:
            biggest_color = current_color

        colors_visited[current] = current_color

    with open('planting.out', 'w') as fp:
        fp.write(str(biggest_color))

    #   /--\
    # 1-2-3-4
    # \--/

if __name__ == '__main__':
    main()