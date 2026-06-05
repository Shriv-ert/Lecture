
def knapsack(W: int, wt: list[int], val: list[int], n: int) -> int:
    memo: list[list[int]] = [[0 for _ in range(W + 1)] for _ in range(n + 1)]

    # buat tabel
    for i in range(n + 1):
        for j in range(W + 1):
            if i == 0 or j == 0:
                memo[i][j] = 0
            else:
                pick: int = 0

                if(wt[i-1] <= j):
                    pick = val[i -1] + memo[i-1][j - wt[i-1]]
                
                notPick: int = memo[i-1][j]
                memo[i][j] = max(pick, notPick)
            
            

    return memo[n][W]


if __name__ == "__main__":
    N, W = map(int, input().split())
    wt = list(map(int, input().split()))
    val = list(map(int, input().split()))
    print(knapsack(W, wt, val, N))