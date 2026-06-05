def keigo(t: list[list[int]], r: int, c: int) -> None:
    #resX, resY, sum = 0
    resX: int = 0
    resY: int = 0
    sum: int = 0
    if (r > c):
        kernelSize = c
        for i in range (r-kernelSize+1):
            for j in range (1):
                sum_temp = 0
                for k in range (kernelSize):
                    for l in range (kernelSize):
                        sum_temp += t[i+k][j+l]
                if (sum_temp > sum):
                    sum = sum_temp
                    resX = i
                    resY = j
        print(f"{sum} {kernelSize} {resX +1} {resY +1}")
    elif (r < c):
        kernelSize = r
        for i in range (1):
            for j in range (c-kernelSize+1):
                sum_temp = 0
                for k in range (kernelSize):
                    for l in range (kernelSize):
                        sum_temp += t[i+k][j+l]
                if (sum_temp > sum):
                    sum = sum_temp
                    resX = i
                    resY = j
        print(f"{sum} {kernelSize} {resX +1} {resY +1}")
    else:
        for i in range (r):
            for j in range (c):
                sum += t[i][j]
        print(f"{sum} {r} {1} {1}")


if __name__ == "__main__":
    r, c = map(int, input().split())
    tab: list[list[int]] = []
    for _ in range (r):
        l: list[int] = list(map(int, input().split()))
        tab.append(l)
    
    keigo(tab, r, c)