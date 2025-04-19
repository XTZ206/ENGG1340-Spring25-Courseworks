import itertools


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
                self.top -= 2
                self.insert(str(a + b))

            case "-":
                if self.top < 2:
                    raise ValueError("Not enough operands for -")
                b = self.data.pop()
                a = self.data.pop()
                self.top -= 2
                self.insert(str(a - b))

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


def get_testcases():
    for chars in itertools.permutations("0123456789+-", 3):
        stack = Stack()
        prints = []

        try:
            for char in chars:
                stack.insert(char)
                prints.append(stack.print())
        except ValueError:
            continue

        if len(stack.data) != 1:
            continue

        yield "".join(chars) + "=", "\n".join(prints)


def main():
    TESTCASE_OFFSET = 1
    for index, (inputs, outputs) in enumerate(get_testcases()):
        with open(f"expected/output3_e{index + TESTCASE_OFFSET}.txt", "w") as f:
            f.write(outputs)
            f.write("\n")
        with open(f"inputs/input3_e{index + TESTCASE_OFFSET}.txt", "w") as f:
            f.write(inputs)
            f.write("\n")
        print(f"\rTestcase {index + TESTCASE_OFFSET} Generated", end="")
    print("\nDone")


main()
