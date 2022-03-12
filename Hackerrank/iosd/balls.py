k = int(input())
n = int(input())
array = []*n
for i in range(1, n+1):
    array.append(i)

for i in range(n):
    no = int(input())
    index = array.index(no)
    arr_1 = []
    arr_2 = []
    try:
        arr_1 = array[0:index]
    except:
        arr_1 = []
    try:
        arr_2 = array[index+1:]
    except:
        arr_2 = []
    if len(arr_1) < k and len(arr_2) < k:
        output = no
        break
    if len(arr_1) > len(arr_2):
        array = []
        array = arr_1.copy()
    else:
        array = []
        array = arr_2.copy()

print(output)
