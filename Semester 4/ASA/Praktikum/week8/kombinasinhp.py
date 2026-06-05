def backTrack(state: str, target: int, map: dict[int, str], res: list[str], start: int = 0) -> None:
    #base case
    if len(state) == target:
        res.append(state)
        return

    for i in range(start, target):
        digit: int = int(nomor[i])
        if digit in map:
            for char in map[digit]:
                backTrack(state + char, target, map, res, i + 1)

def solusi(nomor: str, map: dict[int, str]) -> list[str]:
    res: list[str] = []
    target: int = len(nomor)
    state: str = ""
    backTrack(state, target, map, res)
    # backtrack
    return res

nomor: str = str(input())
map: dict[int, str] = {
    2: "abc",
    3: "def",
    4: "ghi",
    5: "jkl",
    6: "mno",
    7: "pqrs",
    8: "tuv",
    9: "wxyz"
}
for komb in solusi(nomor, map):
    print(komb, end=' ')