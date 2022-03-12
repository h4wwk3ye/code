import operator
for t in range(int(input())):
    n=int(input())
    lst=[sorted(input()) for _ in range(n)]
    #print(lst)
    #print(sorted_lst)
    zip_lst=list(zip(*lst))
    #print(zip_lst)
    sorted_zip_lst=[]
    for i in zip_lst:
        sorted_zip_lst.append(tuple(sorted(list(i)))) #tuple because zip creates a tupple
    #print(sorted_zip_lst)
    if zip_lst==sorted_zip_lst:
        print('YES')
    else:
        print('NO')
