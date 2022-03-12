# !/usr/bin/env python3
# -*- coding: utf-8 -*-


#	✪ H4Wk3yE乡
#	Mohd. Farhan Tahir
#	Indian Institute Of Information Technology and Management,Gwalior

inf = float("inf")
mod = 1000000007


import sys
from itertools import combinations


def get_array():
    return list(map(int, sys.stdin.readline().split()))


def input():
    return sys.stdin.readline()

# ///==========MAIN=============///


def main():
    for tc in range(int(input())):
        n = int(input())
        if n > 6:
            #arr = [i for i in range(n+1)]
            flag_arr = [True for i in range(n+2)]
            flag_count = 0
            popped = set()
            check = False
            #prev_index = 1
            while True:
                op = []
                for i in range(1, n+1):
                    #prev_index += 1
                    if flag_arr[i]:
                        op.append(i)
                        if i == n:
                            #print(i, 'yes')
                            check = True
                        if len(op) == 5:
                            break
                if len(op) != 5:
                    for i in range(1, n+1):
                        if not flag_arr[i]:
                            op.append(i)
                            '''if i == n:
                                check = True'''
                            if len(op) == 5:
                                break

                print('?', op[0], op[1], op[2], op[3], op[4])
                sys.stdout.flush()
                x, y = map(int, input().split())
                popped.add(x)
                popped.add(y)
                flag_arr[x] = False
                flag_arr[y] = False
                flag_count += 2
                if check:
                    break
            # print(popped)
            popped = list(popped)
            popped = popped[:4]
            op = []
            for i in range(1, n+1):
                if flag_arr[i] == True:
                    op.append(i)
                    if len(op) == 3:
                        break
            print('?', op[0], popped[0], popped[1], popped[2], popped[3])
            sys.stdout.flush()
            p, q = map(int, input().split())
            print('?', op[1], popped[0], popped[1], popped[2], popped[3])
            sys.stdout.flush()
            r, s = map(int, input().split())
            print('?', op[2], popped[0], popped[1], popped[2], popped[3])
            sys.stdout.flush()
            u, v = map(int, input().split())

            #print(p, q, r, s, u, v)
            if (p != r and q != s) and(p != u and q != v):
                print('!', op[0])
                sys.stdout.flush()
            elif (r != u and v != s) and (r != p and s != q):
                print('!', op[1])
                sys.stdout.flush()
            else:
                print('!', op[2])
                sys.stdout.flush()
        elif n == 6:
            x = set()
            flag_arr = [True]*(n+2)
            op = []
            print('?', 1, 2, 3, 4, 5)
            sys.stdout.flush()
            p, q = map(int, input().split())
            flag_arr[p] = False
            flag_arr[q] = False
            x.add(p)
            x.add(q)
            print('?', 1, 2, 3, 4, 6)
            sys.stdout.flush()
            r, s = map(int, input().split())
            flag_arr[r] = False
            flag_arr[s] = False
            x.add(r)
            x.add(s)
            print('?', 2, 3, 4, 5, 6)
            sys.stdout.flush()
            u, v = map(int, input().split())
            flag_arr[u] = False
            flag_arr[v] = False
            x.add(u)
            x.add(v)
            x = list(x)
            op = []
            for i in range(1, n+1):
                if flag_arr[i]:
                    op.append(i)
            # print(op)
            if len(x) == 2:
                if 2 not in x:
                    print('!', 2, flush=True)
                elif 3 not in x:
                    print('!', 3, flush=True)
                else:
                    print('!', 4, flush=True)
            else:
                print('?', op[0], op[1], x[0], x[1], x[2])
                sys.stdout.flush()
                p, q = map(int, input().split())
                print('?', op[1], op[2], x[0], x[1], x[2])
                sys.stdout.flush()
                r, s = map(int, input().split())
                print('?', op[0], op[2], x[0], x[1], x[2])
                sys.stdout.flush()
                u, v = map(int, input().split())
                # print(op)
                if (p != r and q != s) and(p != u and q != v):
                    print('!', op[2])
                    sys.stdout.flush()
                elif (r != u and v != s) and (r != p and s != q):
                    print('!', op[0])
                    sys.stdout.flush()
                else:
                    print('!', op[1])
                    sys.stdout.flush()


if __name__ == "__main__":
    main()
