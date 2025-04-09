import random

def get_testcase(words):
    
    # Randomly select a word from the list
    inputs = ""
    
    for _ in range(random.randint(1, 10)):
        word = random.choice(words)
        inputs += word + " " * random.randint(1, 5)
    
    state = random.randint(0, 3)
    if state % 2 == 0:
        inputs += " " * random.randint(1, 5)
    if state // 2 == 0:
        inputs = " " * random.randint(1, 5) + inputs

    word = ""
    longest = ""
    output = ""

    i = 0
    while i < len(inputs):
        if inputs[i] == ' ':
            output += ' '
            i += 1
            continue

        while i < len(inputs) and inputs[i] != ' ':
            word += inputs[i]
            i += 1
        
        output += word[::-1]

        if len(longest) <= len(word):
            longest = word[::-1]

        word = ""

    outputs = [output, longest]
    
    if len(longest) % 2 == 0:
        outputs.append(longest[len(longest) // 2 - 1])
    outputs.append(longest[len(longest) // 2])

    return inputs, "\n".join(outputs)

def main(): 
    TESTCASE_COUNT = 10

    with open("wordlist.txt", "r") as f:
        words = f.read().splitlines()

    for i in range(TESTCASE_COUNT):  
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
    