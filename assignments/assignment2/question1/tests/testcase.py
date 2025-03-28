import random

def is_prime(n):
    if n < 2 or n == 4:
        return False
    if n < 4:
        return True

    return all(n % i != 0 for i in range(2, n // 2))

def get_factor(n):
    for i in range(2, n // 2 + 1):
        if n % i == 0 and is_prime(i) and is_prime(n // i) and i != n // i:
            return i, n // i
    return -1, -1

def get_solution(n):
    a = b = -1
    s = n - 1
    while a == -1 and b == -1:
        s += 1
        a, b = get_factor(s)
    return a, b, s



def get_testcase(): 
    TESTCASE_INPUT_MIN = 1
    TESTCASE_INPUT_MAX = 100000001
    TESTCASE_COUNT = 100

    for i, n in enumerate(random.sample(range(TESTCASE_INPUT_MIN, TESTCASE_INPUT_MAX), TESTCASE_COUNT)):
        a, b, s = get_solution(n)
        with open(f"expected/output1_e{i + 1}.txt", "w") as f:
            f.write(f"{a} {b} {s}\n")
        with open(f"inputs/input1_e{i + 1}.txt", "w") as f:
            f.write(f"{n}\n")
        print(f"\rTestcase {i + 1} Generated", end="")
    print("\nDone")

get_testcase()
    