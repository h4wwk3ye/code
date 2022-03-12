# trying to reduce the number of lines
from collections import Counter
from operator import itemgetter
for tc in range(int(input())):
    _ = input()
    arr = list(map(int, input().split()))
    d = sorted(Counter(arr).items(), key=itemgetter(1), reverse=True)
    ans, lb = 0, float("inf")
    for k, v in d:
        if lb == 0:
            break
        ans += min(v, lb - 1)
        lb = min(v, lb - 1)
    print(ans)
