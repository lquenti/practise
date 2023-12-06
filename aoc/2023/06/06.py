import sys

def solve01():
    with open(sys.argv[1], "r") as fp:
        time, distance = fp.readlines()

    # parse
    time = [int(x) for x in time.split(":")[1].strip().split(" ") if x.strip() != ""]
    distance = [int(x) for x in distance.split(":")[1].strip().split(" ") if x.strip() != ""]
    races = [*zip(time, distance)]

    ret = 1
    for allowed_time, previous_best in races:
        ways_to_beat = 0
        for holding_time in range(0, allowed_time+1):
            distance = (allowed_time-holding_time) * holding_time
            if distance > previous_best:
                ways_to_beat += 1

        ret *= ways_to_beat
    
    print(ret)

solve01()
