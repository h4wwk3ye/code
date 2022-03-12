import sys

for line in sys.stdin:
    input = line.split()

    for user_input in input:
        try:
            val = int(user_input)
            print("int ", end="")
        except ValueError:
            try:
                val = float(user_input)
                print("float ", end="")
            except ValueError:
                print("string ", end="")
    print()

