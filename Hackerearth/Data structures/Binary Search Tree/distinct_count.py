for _ in range(int(input())):
    n, x = map(int, input().split())
    array = list(map(int, input().split()))
    dictionary = {}
    for element in array:
        if not element in dictionary:
            dictionary[element] = 0
        dictionary[element] += 1
    if len(dictionary) == x:
        print('Good')
    elif len(dictionary) < x:
        print('Bad')
    else:
        print('Average')
