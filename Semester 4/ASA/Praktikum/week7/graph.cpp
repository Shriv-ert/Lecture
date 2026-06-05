#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>

void bfs_list(int start, vector<vector<int>>& graph, int finish) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == finish) {
            cout << "True" <<endl;
            return;
        }

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << "False" <<endl;
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n;
    cin >> n;
    char start, finish;
    cin >> start >> finish;
    vector<vector<int>> graph(255);// karena char, jadi maksimal 255(ASCII)
    string line;
    getline(cin, line); // buang newline setelah n
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        if (line.size() >= 3) {
            char u = line[0], v = line[2];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
    }
    

    bfs_list(start, graph, finish);
    return 0;
}