n, q = map(int, input().split())
last_answer = 0
array = [[] for _ in range(n)]
for i in range(q):
    inp = list(map(int, input().split()))

    x = inp[1]
    y = inp[2]
    seq_index = ((x ^ last_answer) % n)

    if inp[0] == 1:
        array[seq_index].append(y)

    elif inp[0] == 2:
        element = y % len(array[seq_index])
        last_answer = array[seq_index][element]
        print(last_answer)
