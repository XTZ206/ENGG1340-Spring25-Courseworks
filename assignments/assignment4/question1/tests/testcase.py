import random
from collections import Counter
from typing import NewType

Word = NewType("Word", str)

with open("wordlist.txt", "r") as f:
    wordlist: list[Word] = f.read().splitlines()


def get_testcase_input(words: list[Word], grouping: int) -> str:
    groups: list[list[str]] = [
        words[i: i + len(words) // grouping] for i in range(0, len(words), len(words) // grouping)]
    return "\n".join(" ".join(group) for group in groups)


def get_testcase_output(words: list[Word]) -> str:
    bigrams: list[str] = []
    counts: list[int] = []

    for word in words:
        for bigram in (word[i: i + 2] for i in range(len(word) - 1)):
            if bigram not in bigrams:
                bigrams.append(bigram)
                counts.append(1)
            else:
                counts[bigrams.index(bigram)] += 1

    if not bigrams:
        return ""

    most_common_count = max(counts)
    most_common_bigram = bigrams[counts.index(most_common_count)]

    prints: list[str] = []
    for word in words:
        if most_common_bigram in word and word not in prints:
            prints.append(word)
    return "\n".join(prints)


def get_testcase() -> tuple[str, str]:
    words = random.choices(wordlist, k=random.randint(3, 10))
    return get_testcase_input(words, random.randint(2, min(5, len(words)))), get_testcase_output(words)


def main():
    TESTCASE_COUNT = 10
    TESTCASE_OFFSET = 0

    for i in range(TESTCASE_OFFSET, TESTCASE_COUNT + TESTCASE_OFFSET):
        inputs, outputs = get_testcase()
        with open(f"expected/output1_e{i + 1}.txt", "w") as f:
            f.write(outputs)
            f.write("\n")
        with open(f"inputs/input1_e{i + 1}.txt", "w") as f:
            f.write(inputs)
            f.write("\n")
        print(f"\rTestcase {i + 1} Generated", end="")
    print("\nDone")


main()
