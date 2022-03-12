# without using qheap python function
def parent(i):
    if i % 2 == 0:
        return (i//2)-1
    else:
        return i//2


def left_child(i):
    return (2*i)+1


def right_child(i):
    return (2*i)+2


def shift_up(array, i):
    if i == 0:
        return array
    if array[parent(i)] > array[i]:
        array[parent(i)], array[i] = array[i], array[parent(i)]
        return shift_up(array, parent(i))
    else:
        return array


def shift_down(array, i):
    min_index = i
    l_child = left_child(i)
    if l_child < len(array) and array[l_child] < array[i]:
        min_index = l_child
    r_child = right_child(i)
    if r_child < len(array) and array[r_child] < array[min_index]:
        min_index = r_child
    if i != min_index:
        array[min_index], array[i] = array[i], array[min_index]
        return shift_down(array, min_index)
    else:
        return array


def insert(array, value):
    array.append(value)
    size = len(array)
    array = shift_up(array, size-1)
    return array


def search(array, value):
    for i in range(len(array)):
        if array[i] == value:
            return i


def extract_min(array):
    size = len(array)-1
    array[0] = array[size]
    min = array.pop()
    array = shift_down(array, 0)
    return array


def delete(array, value):
    index = search(array, value)
    array[index] = array[len(array)-1]
    array.pop()
    array = shift_down(array, index)
    return array


'''def delete(array, value):
    index = search(array, value)
    array[index] = -10**9-1
    array = shift_up(array, index)
    array = extract_min(array)
    return array'''


if __name__ == '__main__':
    array = []
    for _ in range(int(input())):

        inp = input().split()
        if int(inp[0]) == 1:
            array = insert(array, int(inp[1]))

        elif int(inp[0]) == 2:
            array = delete(array, int(inp[1]))

        else:
            print(array[0])
