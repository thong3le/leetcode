
tc = int(raw_input())
for _ in range(tc):
    n = int(raw_input())
    a = map(int, raw_input().split())
    max_ending_here = max_so_far = a[0]
    max_noncontiguous = 0
    for i in a[1:]:
        max_ending_here = max(i, max_ending_here + i)
        max_so_far = max(max_ending_here, max_so_far)
    
    for i in a:
        if i >= 0:
            max_noncontiguous += i
    if max_noncontiguous == 0:
        max_noncontiguous = max(a)
    print max_so_far, max_noncontiguous