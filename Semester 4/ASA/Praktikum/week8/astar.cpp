#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second

using Point = pair<int, int>;

struct PointHash {
    size_t operator()(const Point& p) const {
        return (static_cast<size_t>(p.fi) << 32) ^ static_cast<unsigned int>(p.se);
    }
};

double euclidean_distance(Point p1, Point p2) {
    int lat1 = p1.first, lon1 = p1.second;
    int lat2 = p2.first, lon2 = p2.second;
    return sqrt(pow(lat1 - lat2, 2) + pow(lon1 - lon2, 2));
}

// Fungsi A* mencari jalur terpendek
vector<Point> a_star(Point start, Point goal, map<Point, vector<pair<Point, double>>>& graph) {
    priority_queue<pair<double, Point>, vector<pair<double, Point>>, greater<pair<double, Point>>> open_set;
    map<Point, Point> came_from;
    map<Point, double> g_score;
    
    g_score[start] = 0;
    open_set.push({euclidean_distance(start, goal), start});
    
    while (!open_set.empty()) {
        auto [current_f, current] = open_set.top();
        open_set.pop();
        
        if (current == goal) {
            vector<Point> path;
            Point node = current;
            while (came_from.count(node)) {
                path.push_back(node);
                node = came_from[node];
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }
        
        if (graph.count(current)) {
            for (auto& [neighbor, weight] : graph[current]) {
                double new_g = g_score[current] + weight;
                
                if (!g_score.count(neighbor) || new_g < g_score[neighbor]) {
                    came_from[neighbor] = current;
                    g_score[neighbor] = new_g;
                    double f = new_g + euclidean_distance(neighbor, goal);
                    open_set.push({f, neighbor});
                }
            }
        }
    }
    
    return {}; // tidak ada jalur
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    return 0;
}