#!/usr/bin/env python3
# coding: utf-8
# Last Modified: 07/Jan/20 10:42:28 PM


import sys


def remove_brackets(term):
    a = 0
    while True:
        # Find opening bracket
        try:
            a = term.index("(", a)
        except ValueError:
            # No (more) opening brackets found
            break
        # Find corresponding closing bracket
        b = a
        while True:
            b = term.index(")", b + 1)
            if term[a + 1 : b].count("(") == term[a + 1 : b].count(")"):
                break
        # Assemble new term by removing current pair of brackets
        new_term = term[:a] + term[a + 1 : b] + term[b + 1 :]
        # If new term produces a different value, keep term as it is and try with the next pair of brackets
        if eval(term) != eval(new_term):
            a += 1
            continue
        # Adopt new term
        term = new_term
    return term


def main():
    for tc in range(int(input())):
        s = input()
        print(remove_brackets(s))


get_array = lambda: list(map(int, sys.stdin.readline().split()))


get_ints = lambda: map(int, sys.stdin.readline().split())


input = lambda: sys.stdin.readline().strip()


if __name__ == "__main__":
    main()
