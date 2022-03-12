p, s = map(int, input().split())
count_array = [0]*(s+1)
for i in range(p):
    dict = {}
    score = list(map(int, input().split()))
    no_of_contestatnts = list(map(int, input().split()))
    for p, q in zip(score, no_of_contestatnts):
        dict[p] = q
    # print(dict)
    dict = sorted(dict.items())
    # print(dict[0][0])
    for j in range(1, s):
        if dict[j][1] < dict[j-1][1]:
            count_array[i] += 1
        # print(dict[j-1][1])
for i in range(s):
    print(count_array[i]+1)
