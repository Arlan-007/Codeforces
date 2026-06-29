from collections import defaultdict

if __name__ == "__main__":
    t = int(input())

    divs = defaultdict(list)
    max_computed = 0

    for _ in range(t):
        n = int(input())
        nums = set(map(int, input().split()))

        for i in range(max_computed + 1, n + 1):
            for a in range(1, int(i**0.5) + 1):
                if i % a == 0:
                    b = i // a
                    if a <= b and a <= n and b <= n:
                        divs[i].append([a, b])
        max_computed = max(max_computed, n)

        dp = [-1] * (n + 1)

        for num in nums:
            if num <= n:
                dp[num] = 1

        for i in range(1, n + 1):
            if i in nums:
                continue

            if i not in divs:
                continue

            for pair in divs[i]:
                a, b = pair
                if dp[a] != -1 and dp[b] != -1:
                    cost = dp[a] + dp[b]
                    if dp[i] == -1 or cost < dp[i]:
                        dp[i] = cost

        print(" ".join(str(dp[i]) for i in range(1, n + 1)))