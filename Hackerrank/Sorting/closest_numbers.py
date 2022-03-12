n = int(input())
arr = list(map(int, input().split()))
arr.sort()
smallest = None
smallest_arr = []
for i in range(n-1):
    if smallest == None:
        smallest = arr[i+1]-arr[i]
        smallest_arr.append(arr[i])
        smallest_arr.append(arr[i+1])
    elif smallest < arr[i+1]-arr[i]:
        continue
    elif smallest == arr[i+1]-arr[i]:
        smallest_arr.append(arr[i])
        smallest_arr.append(arr[i+1])
    elif smallest > arr[i+1]-arr[i]:
        smallest_arr = []
        smallest = arr[i+1]-arr[i]
        smallest_arr.append(arr[i])
        smallest_arr.append(arr[i+1])
print(*smallest_arr, end=' ')
