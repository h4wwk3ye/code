if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n=int(input())
        copy_n=n
        while copy_n%3!=0 and copy_n>0:
            copy_n-=5
        if copy_n<0:
            print (-1)
        else:
            string='5'*copy_n+'3'*(n-copy_n)
            print(string)            
