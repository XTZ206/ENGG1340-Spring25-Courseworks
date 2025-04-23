import random


class Stack:

    def __init__(self):
        self.data: list[int] = []
        self.top: int = 0
        self.size: int = 1

    def insert(self, char: str):
        match char:
            case "=":
                pass

            case "+":
                if self.top < 2:
                    raise ValueError("Not enough operands for +")
                b = self.data.pop()
                a = self.data.pop()
                self.data.append(a + b)
                self.top -= 1

            case "-":
                if self.top < 2:
                    raise ValueError("Not enough operands for -")
                b = self.data.pop()
                a = self.data.pop()
                self.data.append(a - b)
                self.top -= 1

            case "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9":
                self.data.append(int(char))
                self.top += 1
                if self.top == self.size:
                    self.size *= 2

            case _:
                if len(char) > 1:
                    raise ValueError(f"Invalid character length: {char}")
                raise ValueError(f"Invalid character: {type(char)}, {char}")

    def print(self) -> str:
        return f"[{self.size}] " + " ".join(map(str, self.data))


def get_testcase(length_limit):
    OPERANDS = "0123456789"
    OPERATORS = "+-"
    length = random.randint(0, length_limit)
    operand_count = length
    operator_count = length

    tokens = [random.choice(OPERANDS)]
    capacity = 0

    for _ in range(length * 2):
        if capacity == 0 or random.randint(1, operand_count + operator_count) < operand_count :
            tokens.append(random.choice(OPERANDS))
            operand_count -= 1
            capacity += 1
        else:
            tokens.append(random.choice(OPERATORS))
            operator_count -= 1
            capacity -= 1

    stack = Stack()
    outputs = []
    for token in tokens:
        stack.insert(token)
        outputs.append(stack.print())

    tokens.append("=")
    return "".join(tokens), "\n".join(outputs)


def main():
    TESTCASE_COUNT = 10
    TESTCASE_OFFSET = 0
    TESTCASE_LENGTH = 10

    for i in range(TESTCASE_OFFSET, TESTCASE_OFFSET + TESTCASE_COUNT):
        inputs, outputs = get_testcase(TESTCASE_LENGTH)
        with open(f"expected/output3_e{i + 1}.txt", "w") as f:
            f.write(outputs)
            f.write("\n")
        with open(f"inputs/input3_e{i + 1}.txt", "w") as f:
            f.write(inputs)
            f.write("\n")
        print(f"\rTestcase {i + 1} Generated", end="")
    print("\nDone")


main()
