def populate(max):
    arr = [i for i in range(max+1)]
    for i in range(2, max):
        arr[i+1] = min(arr[i+1], arr[i]+1)
        j = 2   # we need to start  from 4 (2*2)
        while j <= i and i*j <= max:
            arr[i*j] = min(arr[i]+1, arr[i*j])
            j += 1
        #print(arr[i], i)
    return arr


if __name__ == '__main__':
    inputs = []
    for _ in range(int(input())):
        inputs.append(int(input()))
    arrays = populate(max(inputs))
    for i in range(len(inputs)):
        print(arrays[inputs[i]])
