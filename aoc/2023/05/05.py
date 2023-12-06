import sys

def solve01():
    with open(sys.argv[1], "r") as fp:
        lines = fp.read()
    
    xs = lines.split("\n\n")
    seeds_str = xs[0]
    maps = xs[1:]

    # extract seeds:
    seeds_str = seeds_str.split(":")[1]
    seeds = [int(x) for x in seeds_str.split(" ") if x.strip() != ""]

    # extract maps
    def extract_map(m_str):
        # remove headline
        ms = m_str.split("\n")[1:]
        return [[int(x) for x in m.split(" ") if x.strip() != ""] for m in ms if m.strip() != ""]
    maps = [extract_map(m) for m in maps]

    def eval_map(m, x):
        for dst_rng, src_rng, rng_len in m:
            # if it is in our range
            if src_rng <= x < (src_rng + rng_len):
                # Formula (solving for Y)
                # src_rng+Y=x
                # Y=x-src_rng
                #
                # Thus we want to return
                # dst_rng+Y = dst_len+x-src_rng
                return dst_rng + x - src_rng
            # else we do not have a fit
        # not found, thus `id`
        return x

    for m in maps:
        seeds = [eval_map(m, x) for x in seeds]
    print(min(seeds))


def solve02():
    with open(sys.argv[1], "r") as fp:
        lines = fp.read()
    
    xs = lines.split("\n\n")
    seeds_str = xs[0]
    maps = xs[1:]

    # extract seeds:
    seeds_str = seeds_str.split(":")[1]
    seed_pairs = [int(x) for x in seeds_str.split(" ") if x.strip() != ""]
    seed_pairs = [*zip(seed_pairs[::2], seed_pairs[1::2])]

    # extract maps
    def extract_map(m_str):
        # remove headline
        ms = m_str.split("\n")[1:]
        return [[int(x) for x in m.split(" ") if x.strip() != ""] for m in ms if m.strip() != ""]
    maps = [extract_map(m) for m in maps]

    def eval_map(m, x):
        for dst_rng, src_rng, rng_len in m:
            # if it is in our range
            if src_rng <= x < (src_rng + rng_len):
                # Formula (solving for Y)
                # src_rng+Y=x
                # Y=x-src_rng
                #
                # Thus we want to return
                # dst_rng+Y = dst_len+x-src_rng
                return dst_rng + x - src_rng
            # else we do not have a fit
        # not found, thus `id`
        return x

    current_best = 999999999999999
    for (begin, length) in seed_pairs:
        for seed in range(begin, begin+length):
            x = seed
            for m in maps:
                x = eval_map(m,x)
            if x < current_best:
                current_best = x
    print(current_best)

solve01()
solve02()
