import random
import math

def get_testcase(TESTCASE_LENGTH_MAX):
    length = random.randint(1, TESTCASE_LENGTH_MAX)
    numbers = [random.randint(1, 100) for _ in range(length * 2)] + [random.randint(-10, -1)]

    inputs = " ".join((str(n) for n in numbers))
    outputs = []

    x = y = 0.0
    for i in range(length):
        distance = numbers[i * 2]
        direction = numbers[i * 2 + 1]
        x += distance * math.sin(math.radians(direction))
        y += distance * math.cos(math.radians(direction))
        outputs.append(f"{distance:.1f} @ {direction:.1f} -> {x:.1f}, {y:.1f}")
    outputs.append(f"{math.sqrt(x ** 2 + y ** 2):.1f} @ {math.degrees(math.atan2(x, y)) + 180:.1f} -> Home")

    return inputs, "\n".join(outputs)

def main(): 
    TESTCASE_COUNT = 10
    TESTCASE_LENGTH = 100

    for i in range(TESTCASE_COUNT):  
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
    