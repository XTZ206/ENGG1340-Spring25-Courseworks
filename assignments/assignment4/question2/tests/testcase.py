import random

CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789*!@#$%^&()_+[]{}|;:,.<>?/~`"
WEIGHTS = [0.4] * 52 + [0.2] * 37

def get_testcase(LENGTH):
    length = random.randint(1, LENGTH)
    inputs = ""
    outputs = ""
    for _ in range(length):
        char, = random.choices(CHARS, WEIGHTS, k=1)
        runlen = random.randint(0, 9)
        inputs += char
        inputs += str(runlen)
        outputs += char * (runlen + 1)
    return inputs, outputs

def main(): 
    TESTCASE_COUNT = 10
    TESTCASE_OFFSET = 0
    TESTCASE_LENGTH = 5

    for i in range(TESTCASE_OFFSET, TESTCASE_OFFSET + TESTCASE_COUNT):
        inputs, outputs = get_testcase(TESTCASE_LENGTH)
        with open(f"expected/output2_e{i + 1}.txt", "w") as f:
            f.write(outputs)
            f.write("\n")
        with open(f"inputs/input2_e{i + 1}.txt", "w") as f:
            f.write(inputs)
            f.write("\n")
        print(f"\rTestcase {i + 1} Generated", end="")
    print("\nDone")

main()
