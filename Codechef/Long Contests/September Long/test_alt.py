import operator
n = 6
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
            p = 0
            while p < n:
                posi = 2
                arr[posi], arr[p] = arr[p], arr[posi]
                p += 1
                #l = 0
                q = 0
                while q < n:
                    posi = 3
                    arr[posi], arr[q] = arr[q], arr[posi]
                    q += 1
                    s = 0
                    while s < n:
                        posi = 4
                        arr[posi], arr[s] = arr[s], arr[posi]
                        s += 1
                        l = 0

                        while l < n:
                            posi = 5
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
