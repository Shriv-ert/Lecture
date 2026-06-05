import heapq

def djikstra(graph, start, finish, max_stop):
    distances = {node: float('inf') for node in graph}
    distances[start] = 0
    queue = [()]
    while queue:
        current_distance, current_stop, current_node = heapq.heappop(queue)
        if current_stop > max_stop:
            continue
        if current_distance > distances[current_node]:
            continue
        
        for neighbor, weight in graph[current_node]:
            distance = current_distance + weight
            stops = current_stop + 1
            
            if distance < distances[neighbor] and stops <= max_stop:
                distances[neighbor] = distance
                heapq.heappush(queue, (distance, neighbor))
    
    return distances


n = int(input())  # jumlah node
m = int(input())  # jumlah edge
graph = {i: [] for i in range(n)}

for _ in range(m):
    u, v, w = map(int, input().split())
    graph[u].append((v, w))

start, finish, max_stop = map(int, input().split())
print(djikstra(graph, start))