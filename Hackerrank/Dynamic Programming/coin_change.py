n, m = map(int, input().split())
coins = list(map(int, input().split()))
ways = [0]*(n+1)
for coin in coins:
    if coin > n:
        continue
    ways[coin] += 1   # using the coin itself
    for i in range(coin+1, n+1):  # filling the remaining coins spot ahead of that coin which can be reached by that coin
        ways[i] += ways[i-coin]
