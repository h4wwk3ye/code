import operator
n = 3
j = k = l = count = 0
dict = {}
for i in range(n):
    arr = [h+1 for h in range(n)]

    while j < n:
        posi = 0
        arr[j], arr[posi] = arr[posi], arr[j]
        j += 1
        k = 0
        while k < n:
            posi = 1
            arr[posi], arr[k] = arr[k], arr[posi]
            k += 1
            l = 0
            while l < n:
                posi = 2
                arr[l], arr[posi] = arr[posi], arr[l]
                l += 1
                string = ''
                string = ''.join(str(_) for _ in arr)
                count += 1
                if string not in dict:
                    dict[string] = 0
                dict[string] += 1
sorted_dict = sorted(dict.items(), key=operator.itemgetter(1))
print(sorted_dict)
print(count)
