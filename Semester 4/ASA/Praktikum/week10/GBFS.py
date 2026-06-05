import heapq
from collections import defaultdict

def gbfs(n, heuristic, edges, start, goal):
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)

    pq = []
    visited = set()
    parent = {}

    heapq.heappush(pq, (heuristic[start-1], start))
    visited.add(start)

    found = False
    while pq:
        current_h, current_node = heapq.heappop(pq)

        if current_node == goal:
            found = True
            break

        for neighbor in graph[current_node]:
            if neighbor not in visited:
                visited.add(neighbor)
                parent[neighbor] = current_node
                heapq.heappush(pq, (heuristic[neighbor-1], neighbor))

    if not found:
        return "Path Not Found"

    path = []
    curr = goal
    while curr != start:
        path.append(curr)
        curr = parent[curr]
    path.append(start)
    
    path.reverse()
    
    return " ".join(map(str, path))


n, m = map(int, input().split())
heuristic = list(map(int, input().split()))
edges = []
for _ in range(m):
    u, v = map(int, input().split())
    edges.append((u, v))
start, goal = map(int, input().split())


print(gbfs(n, heuristic, edges, start, goal))
