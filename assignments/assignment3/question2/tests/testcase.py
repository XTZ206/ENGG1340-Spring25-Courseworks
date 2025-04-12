import random

class Vertex:
    def __init__(self, name: str,  cost: float):
        self.name: str = name
        self.cost: float = cost

    def __repr__(self):
        return f"Vertex({self.name}, {self.cost})"

    def __hash__(self):
        return hash(self.name)

class Graph:
    def __init__(self, row: int, col: int, costs: list[float]):
        if len(costs) != row * col:
            raise ValueError("costs length must be equal to row * col")
        
        self.row: int = row
        self.col: int = col
        self.vertices = [Vertex("start", 0)] + \
            [Vertex(f"{y},{x}", costs[y * col + x]) for y in range(row) for x in range(col)] + \
            [Vertex("end", 0)]

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
        if vertex.name == "start":
            for y in range(self.row):
                yield self.get_vertex(f"{y},0")
            return
        
        if vertex.name == "end":
            return

        y, x = map(int, vertex.name.split(","))
        for ny, nx in [(y-1, x), (y+1, x), (y, x-1), (y, x+1)]:
            if 0 <= ny < self.row and 0 <= nx < self.col:
                if self.get_step(self.get_vertex(f"{ny},{nx}"), vertex) != float("inf"):
                    yield self.get_vertex(f"{ny},{nx}")

        if x == self.col - 1:
            yield self.get_vertex("end")

    def get_step(self, start: Vertex, end: Vertex) -> float:
        if start.cost - end.cost > 2.5:
            return float("inf")
        if end.cost - start.cost > 1.5:
            return float("inf")
        if start.cost >= end.cost:
            return 0
        return end.cost - start.cost
    
    def get_cost(self, start: Vertex, end: Vertex) -> float:
        visited = set()
        unvisited = set(self.vertices)
        distances = {vertex: float("inf") for vertex in self.vertices}
        distances[start] = 0

        while unvisited:
            visiting = min(unvisited, key=lambda v: distances[v])
            # if distances[visiting] == float("inf"):
            #     break
            visited.add(visiting)
            unvisited.remove(visiting)

            pass

            for neighbor in self.get_neighbors(visiting):
                step_cost = self.get_step(visiting, neighbor)
                if step_cost + distances[visiting] < distances[neighbor]:
                    distances[neighbor] = step_cost + distances[visiting]

        return distances[end]
        
def get_input_str(graph):
    ret = f"{graph.row} {graph.col}\n"
    
    for y in range(graph.row):
        for x in range(graph.col):
            cost = graph.get_vertex(f"{y},{x}").cost
            if cost == int(cost):
                cost = int(cost)
            ret += f"{cost}"
            if x != graph.col - 1:
                ret += " "
        if y != graph.row - 1:
            ret += "\n"

    return ret

def get_output_str(graph):
    cost = graph.get_cost(graph.get_vertex("start"), graph.get_vertex("end"))
    if cost == float("inf"):
        return "0"
    else:
        if cost == int(cost):
            cost = int(cost)
        return f"1\n{cost}"

def get_testcase(row_max: int, col_max: int):
    row = random.randint(2, row_max)
    col = random.randint(2, col_max)
    costs = [random.randint(0, 6) / 2 for _ in range(row * col)]
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
