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

class Node:
    def __init__(self, worker_id: str, assigned_jobs: int, cost: int, bound: int):
        self.worker_id = worker_id
        self.assigned_jobs = assigned_jobs
        self.cost = cost
        self.bound = bound
    
    def __lt__(self, other: Node) -> bool:
        return self.bound < other.bound

def calculate_bound(job_matriks: list[list[int]], worker_id: int, assigned_jobs: list[int]) -> int:
    n: int = len(job_matriks)
    bound: int = 0

    for i in range(worker_id + 1, n):
        min_cost: int = float('inf')
        for job in range(n):
            if job not in assigned_jobs:
                min_cost = min(min_cost, job_matriks[i][job])
        bound += min_cost

    return bound

def job_assign(job_matriks: list[list[int]]) -> int:
    n: int = len(job_matriks)
    prique: list[Node] = []

    root_bound: int = calculate_bound(job_matriks, worker_id=-1, assigned_jobs=[])
    root = Node(worker_id=-1, assigned_jobs=[], cost=0, bound=root_bound)
    heapq.heappush(prique, root)

    while prique:
        
        curr_node: Node = heapq.heappop(prique)

        if curr_node.worker_id == n - 1:
            return curr_node.cost
        
        next_worker_id: int = curr_node.worker_id + 1
        for job in range(n):
            if job not in curr_node.assigned_jobs:
                new_worker_id: int = next_worker_id
                new_assigned_jobs: list[int] = curr_node.assigned_jobs + [job]
                new_cost: int = curr_node.cost + job_matriks[new_worker_id][job]
                new_bound: int = new_cost + calculate_bound(job_matriks, worker_id= next_worker_id, assigned_jobs= new_assigned_jobs)

                new_node: Node = Node(worker_id= new_worker_id, assigned_jobs= new_assigned_jobs, cost= new_cost, bound= new_bound)
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