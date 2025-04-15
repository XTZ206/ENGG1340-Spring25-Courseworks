import random

inf: int = 0x3f3f3f3f
class Vertex:
    def __init__(self, name: str):
        self.name: str = name

    def __repr__(self):
        return f"Vertex(name=\"{self.name}\")"

    def __eq__(self, other):
        if isinstance(other, Vertex):
            return self.name == other.name
        return False

    def __hash__(self):
        return hash(self.name)

class Graph:
    def __init__(self, row: int, col: int, costs: list[int]):
        self.row: int = row
        self.col: int = col
        self.vertices: list[Vertex] = [Vertex("start")] + \
            [Vertex(f"{y},{x}") for y in range(row) for x in range(col)] + \
            [Vertex("end")]
        self.costs: dict[Vertex, int] = {Vertex(f"{y},{x}") : costs[y * col + x] for y in range(row) for x in range(col)}
        self.costs[Vertex("start")] = 0
        self.costs[Vertex("end")] = 0
        self.edges: dict[Vertex, dict[Vertex, int]] = {v1 : {v2 : inf if v1 != v2 else 0 for v2 in self.vertices} for v1 in self.vertices}

        for vertex in self.vertices:
            if vertex.name == "start":
                for y in range(row):
                    self.edges[vertex][Vertex(f"{y},0")] = self.get_step(vertex, Vertex(f"{y},0"))
                continue

            if vertex.name == "end":
                continue

            y, x = map(int, vertex.name.split(","))
            for ny, nx in [(y-1, x), (y+1, x), (y, x-1), (y, x+1)]:
                if 0 <= ny < row and 0 <= nx < col:
                    self.edges[vertex][Vertex(f"{ny},{nx}")] = self.get_step(vertex, Vertex(f"{ny},{nx}"))

            if x == col - 1:
                self.edges[vertex][Vertex("end")] = self.get_step(vertex, Vertex("end"))

    def get_vertex(self, name: str) -> Vertex:
        if name == "start":
            return self.vertices[0]
        elif name == "end":
            return self.vertices[-1]
        else:
            y, x = map(int, name.split(","))
            return self.vertices[y * self.col + x + 1]
        # +1 to skip the start vertex
    
    def get_neighbors(self, vertex: Vertex):
        for neighbor, cost in self.edges[vertex].items():
            if cost < inf:
                yield neighbor
        return
    
    def get_step(self, start: Vertex, end: Vertex) -> int:
        if 0 <= self.costs[start] - self.costs[end] < 3:
            return 0
        if self.costs[start] - self.costs[end] == -1:
            return 1
        return inf

    def get_cost(self, start: Vertex, end: Vertex, visited: list[Vertex]) -> int:
        if start == end:
            return 0
        
        cost = inf
        for neighbor in self.get_neighbors(start):
            if neighbor in visited:
                continue

            cost = min(cost, self.edges[start][neighbor] + self.get_cost(neighbor, end, visited + [start]))
        return cost


def get_input_str(graph: Graph):
    ret = f"{graph.row} {graph.col}\n"
    for y in range(graph.row):
        for x in range(graph.col):
            ret += str(graph.costs[Vertex(f"{y},{x}")])
            if x != graph.col - 1:
                ret += " "
        if y != graph.row - 1:
            ret += "\n"
    return ret

def get_output_str(graph: Graph):
    cost = graph.get_cost(Vertex("start"), Vertex("end"), [])
    if cost >= inf:
        return "0"
    else:
        return f"1\n{cost}"

def get_testcase(row_max: int, col_max: int):
    row = random.randint(2, row_max)
    col = random.randint(2, col_max)
    costs = random.choices(range(0, 6), (0.2, 0.2, 0.2, 0.2, 0.1, 0.1), k=row * col)
    graph = Graph(row, col, costs)
    input_str = get_input_str(graph)
    output_str = get_output_str(graph)
    return input_str, output_str

def main(): 
    TESTCASE_COUNT = 10
    TESTCASE_OFFSET = 0
    TESTCASE_ROW_MAX = 5
    TESTCASE_COL_MAX = 5

    for i in range(TESTCASE_OFFSET, TESTCASE_OFFSET + TESTCASE_COUNT):
        inputs, outputs = get_testcase(TESTCASE_ROW_MAX, TESTCASE_COL_MAX)
        with open(f"expected/output2_e{i + 1}.txt", "w") as f:
            f.write(outputs)
            f.write("\n")
        with open(f"inputs/input2_e{i + 1}.txt", "w") as f:
            f.write(inputs)
            f.write("\n")
        print(f"\rTestcase {i + 1} Generated", end="")
    print("\nDone")

main()
