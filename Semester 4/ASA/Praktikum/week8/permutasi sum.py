def backtrack(state: list[int], target: int, total: int, arr: list[int], res: list[list[int]], start: int = 0) -> None:
    # base case
    if total == target:
        res.append(list(state))
    else:
        # rekurens
        # traversal 3 4 5
        for i in range(start, len(arr)):
            if total + arr[i] > target:  # pruning
                continue
            else:
                # [3 3]
                state.append(arr[i])  # [3 3]
                backtrack(state, target, total + arr[i], arr, res, i)
                state.pop()  # backtrack

    return


def solusi(arr: list[int], target: int) -> list[list[int]]:  # --> res
    state: list[int] = []
    total: int = 0
    res: list[list[int]] = []
    backtrack(state, target, total, arr, res)
    return res


n: int = int(input())
arr: list[int] = list(map(int, input().split()))
target: int = int(input())

hasil: list[list[int]] = solusi(arr, target)
if hasil == []:
    print("Tidak ada kombinasi")
for perm in hasil:
    for num in perm:
        print(num, end=' ')
    print()
