
def index(level):
    return 2**level-1


if __name__ == '__main__':
    n, q = map(int, input().split())
    array = list(map(int, input().split()))
    for i in range(q):
        inp = list(map(int, input().split()))
        if inp[0] == 1:
            starting_index = index(inp[2]-1)
            final_index = starting_index+inp[1]-1
            print(array[final_index])
        if inp[0] == 2:
            first_level_index = index(inp[1]-1)
            second_level_index = index(inp[2]-1)
            second_level_index_rightmost = second_level_index+(2**(inp[2]-1))-1
            # print(array[first_level_index:second_level_index_rightmost])
            print(sum(array[first_level_index:second_level_index_rightmost]))
        if inp[0] == 3:
            starting_index = index(inp[2]-1)
            final_index = starting_index+inp[1]-1
            array[final_index] = inp[3]
