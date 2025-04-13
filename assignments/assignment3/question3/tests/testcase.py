import random
import itertools
from collections import namedtuple

Course = namedtuple("Course", ["code", "start", "end"])

class Courses:
    def __init__(self):
        self.courses = []
    
    def insert(self, code: int, start: int, end: int) -> bool:
        # Check if the course has the same code
        if any(course.code == code for course in self.courses):
            return False

        # Check if the course overlaps with existing courses
        for course in self.courses:
            if (course.start <= start < course.end) or (start <= course.start < end):
                return False
        
        self.courses.append(Course(code, start, end))
        return True
    
    def remove(self, code: int) -> bool:
        for course in self.courses:
            if course.code == code:
                self.courses.remove(course)
                return True
        return False
    
    def update(self, code: int, start: int, end: int) -> bool:
        # Check if the course with the given code exists
        if not any(course.code == code for course in self.courses):
            return False
        
        # Remove the course with the given code
        old_course = None
        for course in self.courses:
            if course.code == code:
                old_course = course
                self.courses.remove(course)
                break

        # Check if the new course overlaps with existing courses
        for course in self.courses:
            if (course.start <= start < course.end) or (start <= course.start < end):
                if old_course is not None:
                    self.courses.append(old_course)
                return False
        
        self.courses.append(Course(code, start, end))
        return True

    def print(self) -> str:
        if not self.courses:
            return "Empty"
        # Print courses in the format "<code>: <start> - <end>" and in the order of start time
        return "\n".join([f"{course.code}: {course.start} - {course.end}" for course in sorted(self.courses, key=lambda c: c.start)])

def get_input(commands: list[str]) -> str:
    return "\n".join(commands)

def get_output(commands: list[str]) -> str:
    courses = Courses()
    outputs = []
    
    for command in commands:
        action = command.split()[0]
        match action:
            case "insert":
                code = int(command.split()[1])
                start = int(command.split()[2])
                end = int(command.split()[3])

                result = courses.insert(code, start, end)
                if not result:
                    outputs.append("false")

            case "delete":
                code = int(command.split()[1])
                result = courses.remove(code)
            
            case "update":
                code = int(command.split()[1])
                start = int(command.split()[2])
                end = int(command.split()[3])

                result = courses.update(code, start, end)
                if not result:
                    outputs.append("false")
            
            case "print":
                result = courses.print()
                outputs.append(result)

            case "quit":
                break

    return "\n".join(outputs)
            
def get_testcase() -> tuple[str, str]:
    COMMAND_LENGTH = 50
    CODE_LIMIT = 5
    TIME_LIMIT = 20
    INTERVAL_MIN = 1
    INTERVAL_MAX = 4

    length = random.randint(1, COMMAND_LENGTH)
    commands = []
    actions = random.choices(["insert", "delete", "update", "print", "quit"], [0.25, 0.2, 0.2, 0.2, 0.05], k=length)

    for action in actions:
        match action:
            case "insert":
                code = random.randint(1, CODE_LIMIT)
                start = random.randint(INTERVAL_MIN, TIME_LIMIT - INTERVAL_MAX)
                end = start + random.randint(INTERVAL_MIN, INTERVAL_MAX)
                commands.append(f"insert {code} {start} {end}")
            case "delete":
                code = random.randint(1, CODE_LIMIT)
                commands.append(f"delete {code}")
            case "update":
                code = random.randint(1, CODE_LIMIT)
                start = random.randint(INTERVAL_MIN, TIME_LIMIT - INTERVAL_MAX)
                end = start + random.randint(INTERVAL_MIN, INTERVAL_MAX)
                commands.append(f"update {code} {start} {end}")
            case "print":
                commands.append("print")
            case "quit":
                commands.append("quit")
                break
    commands.append("quit")
    commands = [command for command, _ in itertools.groupby(commands)]

    return get_input(commands), get_output(commands)   

def main():
    TESTCASE_COUNT = 10
    TESTCASE_OFFSET = 0

    for i in range(TESTCASE_OFFSET, TESTCASE_OFFSET + TESTCASE_COUNT):
        inputs, outputs = get_testcase()
        with open(f"expected/output3_e{i + 1}.txt", "w") as f:
            f.write(outputs)
            if outputs != "":
                f.write("\n")
        with open(f"inputs/input3_e{i + 1}.txt", "w") as f:
            f.write(inputs)
            f.write("\n")
        print(f"\rTestcase {i + 1} Generated", end="")
    print("\nDone")

main()
