def matching_strings(string, queries, n, q):
    count = [0]*q
    for i in range(q):
        for j in range(n):
            if queries[i] == string[j]:
                count[i] += 1
    return count


string = []
queries = []
n = int(input())
for i in range(n):
    string.append(input())
q = int(input())
for j in range(q):
    queries.append(input())
print(*matching_strings(string, queries, n, q), sep='\n')
