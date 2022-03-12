if __name__ == '__main__':
    for t in range(int(input())):
        n, m, x, y = map(int, input().split())
        flag_m = 0
        flag_n = 0
        knowledge = 1
        power = 1
        if knowledge == n or x == 1:
            flag_n = 1

        if power == m or y == 1:
            flag_m = 1

        if knowledge+1 == n and power+1 == m:  # when insatlling sharechat can work
            flag_m = 1
            flag_n = 1

        else:
            new_knowledge = knowledge + ((n-knowledge)//x)*x  # new knowledge and new power
            new_power = power + ((m-power)//y)*y
            # print(power)
            if new_knowledge == n:
                flag_n = 1
            if new_power == m:
                flag_m = 1
            if new_knowledge+1 == n and new_power+1 == m:  # if installing sharechat after increasing can work
                flag_m = 1
                flag_n = 1

            # if we can acheive it by increasing knowledge one time less by using sharechat
            if x == 1 and n != 1 and new_knowledge == n and new_power+1 == m:
                flag_m = 1
                flag_n = 1

            # if we can use power 1 time less by using sharechat to acheive knowledge
            if y == 1 and m != 1 and new_power == m and new_knowledge+1 == n:
                flag_m = 1
                flag_n = 1

            #print(new_knowledge, new_power)

        if flag_m == 1 and flag_n == 1:
            print("Chefirnemo")
        else:
            print("Pofik")
