if "__main__" == __name__:
    kata = input()
    fac = [1]
    for i in range(1, 1001):
        fac.append(fac[-1]*i)
    mapChar = [0]*26
    for char in kata:
        mapChar[ord(char)-ord('A')] += 1
    res = fac[len(kata)]
    for i in mapChar:
        res //= fac[i]
    print(res)