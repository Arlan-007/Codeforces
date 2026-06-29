# gen.py
# Generates a worst-case test that will TLE your solution
import random

n = 300000

with open("tle_test.txt", "w") as f:
    f.write("1\n")
    f.write(str(n) + "\n")
    arr = []
    for i in range(n):
        # Deterministic pseudo-random pattern
        arr.append(str((i * 123457 + 89123) % n + 1))
    f.write(" ".join(arr))


print("Generated tle_test.txt with n =", n)
