def same_hand(first, second):
    if (first == 'd' or first == 'f') and (second == 'd' or second == 'f'):
        return True
    elif (first == 'j' or first == 'k')and (second == 'j' or second == 'k'):
        return True
    else:
        return False


if __name__ == '__main__':
    for t in range(int(input())):
        n = int(input())
        d = {}
        time = 0
        for i in range(n):
            word = input()
            local_time = 0
            if word not in d:
                local_time += 2
                for j in range(1, len(word)):
                    if same_hand(word[j-1], word[j]):
                        local_time += 4
                    else:
                        local_time += 2
                d[word] = (local_time)
                time += local_time
            else:
                time += (d[word]//2)
        print(time)
