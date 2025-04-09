import random

def get_testcase(wordlist):

    SUFFIX_LENGTH = 5
    PREFIX_LENGTH = 5

    prefix = " " * random.randint(0, PREFIX_LENGTH)
    suffix = " " * random.randint(0, SUFFIX_LENGTH)
    words: list[str] = random.choices(wordlist)
    longest = ""

    inputs = prefix
    outputs = prefix
    for word in words:
        space = " " * random.randint(1, 5)
        capitalize = (random.randint(0, 1) == 1)
        if capitalize:
            word = word.capitalize()
        inputs += word + space
        outputs += word[::-1] + space
        longest = word if len(word) >= len(longest) else longest
    inputs += suffix
    outputs += suffix

    outputs += "\n" + longest[::-1]
    
    outputs += "\n" + longest[::-1][len(longest) // 2 - 1] if len(longest) % 2 == 0 else ""
    outputs += "\n" + longest[::-1][len(longest) // 2]

    return inputs, outputs

def main(): 
    TESTCASE_COUNT = 10
    TESTCASE_OFFSET = 10

    with open("wordlist.txt", "r") as f:
        words = f.read().splitlines()

    for i in range(TESTCASE_OFFSET, TESTCASE_COUNT + TESTCASE_OFFSET):  
        inputs, outputs = get_testcase(words)  
        with open(f"expected/output1_e{i + 1}.txt", "w") as f:
            f.write(outputs)
            f.write("\n")
        with open(f"inputs/input1_e{i + 1}.txt", "w") as f:
            f.write(inputs)
            f.write("\n")
        print(f"\rTestcase {i + 1} Generated", end="")
    print("\nDone")

main()
    