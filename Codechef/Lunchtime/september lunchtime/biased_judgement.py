for t in range(int(input())):
    n, m = map(int, input().split())
    d = list(map(int, input().split()))
    array = []
    submissions = []
    for i in range(n):
        array.append(list(map(int, input().split())))
    for i in range(n):
        submissions.append(list(map(int, input().split())))
