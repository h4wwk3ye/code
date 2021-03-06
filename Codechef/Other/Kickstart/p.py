s1 = [80, 50, 10, 50]
s2 = [10, 10, 100, 30]
# s3 = [10, 1, 4]


def find_max_sum(s_arr, n):
    if n == 0:
        return 0

    if len(s_arr) == 1:
        return sum(s_arr[0][-n:])

    # Assume no term is picked form the first stack
    max_sum = find_max_sum(s_arr[1:], n)

    first_stack = s_arr[0]
    for i in range(1, n + 1):
        stack_sum = sum(first_stack[-i:])
        rem_sum = find_max_sum(s_arr[1:], n - i)
        if stack_sum + rem_sum > max_sum:
            max_sum = stack_sum + rem_sum

    return max_sum


print(find_max_sum([s1, s2], 5))
