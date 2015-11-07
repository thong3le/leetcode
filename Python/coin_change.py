n, m = tuple(map(int, raw_input().split()))

coins = map(int, raw_input().split())

coins = sorted(coins)
count = [0]*(n+1)

count[0] = 1

for i in range(m):
    for j in range(coins[i], n+1):
        count[j] += count[j-coins[i]]
        
print count[n]