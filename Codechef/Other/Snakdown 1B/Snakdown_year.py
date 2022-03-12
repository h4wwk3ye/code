import sys
if __name__ == '__main__':
    years = [2010, 2015, 2016, 2017, 2019]
    for tc in range(int(input())):
        n = int(input())
        if n in years:
            print('HOSTED', sep=' ', end='\n', file=sys.stdout, flush=False)
        else:
            print('NOT HOSTED', sep=' ', end='\n', file=sys.stdout, flush=False)
