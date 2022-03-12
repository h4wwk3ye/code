from string import ascii_lowercase

alphabets = dict((k, v) for k, v in enumerate(ascii_lowercase, 1))
index_char = dict((v, k) for k, v in alphabets.items())

print(alphabets)
print(index_char)


def alpha_index(character):
    return index_char[character]


def index_value(index):
    return alphabets[index]


arr = [0]*27

s = input()
for i in s:
    index = alpha_index(i)
    arr[index] += 1
for i in range(len(arr)):
    arr[i] //= 2
# print(arr)
length = len(s)//2
j = 1
output = []
for i in range(len(arr)):
    if arr[i] == 0:
        continue
    while(arr[i] != 0 and j <= length):
        output.append(i)
        arr[i] -= 1
        j += 1
output_string = ''
for i in output:
    character = index_value(i)
    output_string += character
print(output_string)
