def quick_sort(arr):
    if len(arr) <= 1:
        return 0
    pivot = arr[len(arr)//2]
    cnt = 0;
    for x in arr:
        if x 