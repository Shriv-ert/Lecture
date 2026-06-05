#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>

void dfs(int i, int j, vector<vector<int>>& graph, vector<vector<bool>>& visited) {
    visited[i][j] = true;
    
    // Mengunjungi tetangga (atas, bawah, kiri, kanan)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        // cek batasan dan apakah sudah dikunjungi atau tidak
        if (ni >= 0 && ni < graph.size() && nj >= 0 && nj < graph[0].size() && !visited[ni][nj] && graph[ni][nj] == 1) {
            dfs(ni, nj, graph, visited); 
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int m, n, counter = 0;
    cin >> m >> n;
    vector<vector<int>>matriks_tetangga(m, vector<int>(n, 0));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for(int i = 0; i < m; i++){
        string baris;
        cin >> baris;
        for(int j = 0; j < n; j++){
            matriks_tetangga[i][j] = baris[j] - '0'; //char ke int
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matriks_tetangga[i][j] == 1 && !visited[i][j]){
                dfs(i, j, matriks_tetangga, visited);
                counter++;
            }
        }
    }

    cout << counter << endl;
    return 0;
}