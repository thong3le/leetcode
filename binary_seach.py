v = int(raw_input())
n = int(raw_input())
arr = map(int, raw_input().split())

lo = 0
hi = n

while lo <= hi:
    mid = lo + (hi - lo)/2
    if arr[mid] == v:
        print mid 
        break;
    elif arr[mid] < v:
        lo = mid +1
    else:
        hi = mid - 1