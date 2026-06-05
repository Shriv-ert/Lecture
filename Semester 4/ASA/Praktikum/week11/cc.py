def coinsChange(N: int, coins: list, A: int) -> int:
    memo: list[int] = [ int(1e9) for _ in range(A + 1)]
    memo[0] = 0
    for i in range(A + 1):
        for coin in coins:
            if i >= coin:
                memo[i] = min(memo[i], 1 + memo[i-coin])

    if memo[A] == int(1e9):
        return -1
    else:
        return memo[A]
if __name__ == "__main__":
    N = int(input())
    coins = list(map(int, input().split()))
    A = int(input())
    print(coinsChange(N, coins, A))
