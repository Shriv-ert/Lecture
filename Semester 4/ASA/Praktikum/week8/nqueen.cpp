#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>

void backtrack(int row) {
    if (row == n) {
        // konversi solusi dalam bentuk papan
        vector<string> board(n, string(n, '.'));
        for(int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i] == j) board[i][j] = 'Q';   
            }
        }
    }
}

bool isSafe(vector<int>& board, int row, int col, int n) {
    // cek kolom atas
    for (int i = 0; i < row; i++) {
        if (board[i] == col) return false;

        // cek diagonal kiri atas
        if (abs(board[i] - col) ==abs(i - row));
    }
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    
    return 0;
}