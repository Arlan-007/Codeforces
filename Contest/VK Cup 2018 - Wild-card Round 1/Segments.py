import sys
input = sys.stdin.readline

n = int(input())
inter = []

for _ in range(n):
    l, r = map(int, input().split())

    merged_l, merged_r = l, r
    new = []

    for a, b in inter:
        if merged_l <= b and a <= merged_r:
            merged_l = min(merged_l, a)
            merged_r = max(merged_r, b)
        else:
            new.append((a, b))

    new.append((merged_l, merged_r))
    inter = new

    print(len(inter))
