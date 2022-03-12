n = int(input())
a, b = input().split()
x, y = map(int, input().split())

char_range = ord(b) - ord(a) + 1
num_range = y - x + 1
print(char_range ** 2, num_range ** 4)
ans = char_range ** 2 * num_range ** 4 * n
print(ans)
