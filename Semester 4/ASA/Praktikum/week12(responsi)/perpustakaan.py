def max_sum_titles(n: int, a: int, b: int, titles: list[str]) -> int:
    counts: list[tuple[int, int]] = [(s.count('%'), s.count('?')) for s in titles]
    dp: list[list[int]] = [[0] * (b + 1) for _ in range(a + 1)]
    for p, q in counts:
        if p > a or q > b:
            continue
        for i in range(a, p - 1, -1):
            for j in range(b, q - 1, -1):
                dp[i][j] = max(dp[i][j], dp[i - p][j - q] + 1)
    return dp[a][b]

if __name__ == "__main__":
    n: int = int(input().strip())
    a, b = map(int, input().split())
    titles: list[str] = [input().strip() for _ in range(n)]
    print(max_sum_titles(n, a, b, titles))