# class Node:


def check(parent_array, color_array, parent_index, child_color):
    if child_color == color_array[parent_index]:
        return parent_index
    if parent_array[parent_index] == 0:
        return -1
    return check(parent_array, color_array, parent_array[parent_index], child_color)


if __name__ == '__main__':
    n, c = map(int, input().split())
    parent_array = list(map(int, input().split()))
    new_parent_array = [None, 0]
    for i in parent_array:
        new_parent_array.append(i)
    # print(new_parent_array)
    array_color = list(map(int, input().split()))
    child_array_color = [None]
    for i in array_color:
        child_array_color.append(i)
    color_ancestor = []
    color_ancestor.append(-1)
    for i in range(2, n+1):
        color_ancestor.append(check(new_parent_array, child_array_color,
                                    new_parent_array[i], child_array_color[i]))
    # print(color_ancestor)
    for element in color_ancestor:
        if element:
            print(element, end=' ')
