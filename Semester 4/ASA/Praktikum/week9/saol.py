import heapq
''' INPUT
4
Budi Edo Fani Lala
UI/UX_Designer Web_Developer AI_Engineer Quality_Control
10 11 9 7
8 11 4 20
2 5 4 9
13 15 19 53
'''
''' EXPECTED OUTPUT
28
'''

def print_node(node: Node) -> None:
    print(f"Worker ID: {node.pelajar_id}, Assigned Jobs: {node.nilai_pelajaran}, Cost: {node.cost}, Bound: {node.bound}")
class Node:
    def __init__(self, pelajar_id: str, nilai_pelajaran: int, cost: int, bound: int):
        self.pelajar_id = pelajar_id
        self.nilai_pelajaran = nilai_pelajaran
        self.cost = cost
        self.bound = bound
    
    def __lt__(self, other: Node) -> bool:
        return self.bound > other.bound

def calculate_bound(job_matriks: list[list[int]], pelajar_id: int, nilai_pelajaran: list[int]) -> int:
    n: int = len(job_matriks)
    bound: int = 0

    for i in range(pelajar_id + 1, n):
        min_cost: int = -float('inf')
        for job in range(n):
            if job not in nilai_pelajaran:
                max_cost = max(min_cost, job_matriks[i][job])
        bound += max_cost

    return bound

def job_assign(job_matriks: list[list[int]]) -> int:
    n: int = len(job_matriks)
    prique: list[Node] = []

    root_bound: int = calculate_bound(job_matriks, pelajar_id=-1, nilai_pelajaran=[])
    root = Node(pelajar_id=-1, nilai_pelajaran=[], cost=0, bound=root_bound)
    heapq.heappush(prique, root)

    while prique:
        
        curr_node: Node = heapq.heappop(prique)
        print_node(curr_node)

        if curr_node.pelajar_id == n - 1:
            return curr_node.cost
        
        next_pelajar_id: int = curr_node.pelajar_id + 1
        for job in range(n):
            if job not in curr_node.nilai_pelajaran:
                new_pelajar_id: int = next_pelajar_id
                new_nilai_pelajaran: list[int] = curr_node.nilai_pelajaran + [job]
                new_cost: int = curr_node.cost + job_matriks[new_pelajar_id][job]
                new_bound: int = new_cost + calculate_bound(job_matriks, pelajar_id= next_pelajar_id, nilai_pelajaran= new_nilai_pelajaran)

                new_node: Node = Node(pelajar_id= new_pelajar_id, nilai_pelajaran= new_nilai_pelajaran, cost= new_cost, bound= new_bound)
                heapq.heappush(prique, new_node)


N: int = int(input())  # jumlah node
workers: list[str] = list(input().split())  # nama pekerja
jobs: list[str] = list(input().split())  # nama pekerjaan

job_matriks: list[list[int]] = []
for _ in range(N):
    temp: list[int] = list(map(int, input().split())) #
    job_matriks.append(temp)

result: int = job_assign(job_matriks)
print(result)