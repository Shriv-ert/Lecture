# Nama: Shofwan Fikrul Huda
# NIM: 24060124130106

import heapq
# return path from start to goal
def gbfs(n: int, heuristic: list[int], edges: list[tuple[int, int]], start: int, goal: int) -> list:
    graph: dict[int, list[int]] = {i: [] for i in range(n+1)}

    # inisialisasi graph
    for u, v in edges:
        graph[u].append(v)
    
    # inisialisasi priority queue
    prique: list[tuple[int, int]] = []

    parent: dict[int, int] = {}  # untuk menyimpan parent node

    # node yang sudah dikunjungi
    visited: dict[int, bool] = {i: False for i in range(n+1)}

    # masukkan node awal ke priority queue
    heapq.heappush(prique, (heuristic[start - 1], start))
    visited[start] = True

    # proses pencarian
    while prique:
        # ambil degngan heuristik terkecil
        curr_h: int
        curr_node: int
        curr_h, curr_node = heapq.heappop(prique)

        if curr_node == goal:
            break

        for neighbor in graph[curr_node]:
            if not visited[neighbor]:
                parent[neighbor] = curr_node
                visited[neighbor] = True
                heapq.heappush(prique, (heuristic[neighbor - 1], neighbor))

    if goal not in parent and start != goal:
        return [] 

    # reconstruct path
    path: list[int] = []
    current: int = goal
    while current != start:
        path.append(current)
        current = parent[current]
    path.append(start)
    path.reverse()

    return path


if __name__ == "__main__":
    n: int
    m: int
    n, m = map(int, input().split())
    heuristic: list[int] = list(map(int, input().split()))

    edges: list[tuple[int, int]] = []

    for _ in range(m):
        u: int
        v: int
        u, v = map(int, input().split())

        edges.append((u, v))

    start: int
    goal: int
    start, goal = map(int, input().split())

    result = gbfs(n, heuristic, edges, start, goal)
    print(*result)

