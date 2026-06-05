import heapq
import math

def euclidean_distance(p1, p2):
    lat1, lon1 = p1
    lat2, lon2 = p2
    return math.sqrt((lat1 - lat2) ** 2 + (lon1 - lon2) ** 2)

def a_star(start, goal, graph):
    open_set = [(0 + euclidean_distance(city_coords[start], city_coords[goal]), 0, start)]
    came_from = {}
    g_score = {start: 0}
    
    while open_set:
        _, current_g, current = heapq.heappop(open_set)
        
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            return path[::-1]
        
        for neighbor, weight in graph[current]:
            tentative_g = g_score[current] + weight
            
            if neighbor not in g_score or tentative_g < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g
                f_score = tentative_g + euclidean_distance(city_coords[neighbor], city_coords[goal])
                heapq.heappush(open_set, (f_score, tentative_g, neighbor))
    
    return None

city_coords = {
    'A': (0, 0),
    'B': (1, 1),
    'C': (2, 2),
    'D': (3, 3),
    'E': (4, 4)
}
graph = {
    'A': [('B', 1.5), ('C', 2.5)],
    'B': [('A', 1.5), ('D', 2.0)],
    'C': [('A', 2.5), ('D', 1.0)],
    'D': [('B', 2.0), ('C', 1.0), ('E', 1.5)],
    'E': [('D', 1.5)]
}
