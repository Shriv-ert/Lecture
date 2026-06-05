// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define pb push_back
// #define all(v) v.begin(), v.end()
// #define sz(a) (int)a.size()
// #define fi first
// #define se second
// #define vc(ll) vector<ll>

// int main() {
//     ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
//     int n, i, j; cin >> n;
//     if(n == 1){
//         cout << "Q" << '\n';
//         return 0;
//     }
//     if(n == 2 || n == 3){
//         cout << "Kerajaan tidak dapat dilindungi!" << '\n';
//         return 0;
//     }if(n%2==1){
//         for(i = 1; i <= n; i++){
//             for(j = 1; j <= n; j++){
//                 if((((n/2 +1) >= i) && (i*2 -1 == j)) || (((n/2 +1) < i) && (i*2 - n-1 == j))){
//                     cout<<'Q';
//                 }else {
//                     cout<<'.';
//                 }
//             }
//             cout<<'\n';
//         }
//     }else{
//         for(i = 1; i <= n; i++){
//             for(j = 1; j <= n; j++){
//                 if((((n/2 +1) > i) && (i*2 == j)) || (((n/2 +1) <= i) && (i*2 - n-1 == j))){
//                     cout<<'Q';
//                 }else {
//                     cout<<'.';
//                 }
//             }
//             cout<<'\n';
//         }
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> board;
bool col[20], diag1[40], diag2[40];
bool solved = false;

void solve(int r){
    if(r == n){
        solved = true;
        return;
    }
    
    for(int c = 0; c < n; c++){
        if(!col[c] && !diag1[r-c+n] && !diag2[r+c]){
            board[r][c] = 'Q';
            col[c] = diag1[r-c+n] = diag2[r+c] = true;
            
            solve(r+1);
            if(solved) return;
            
            board[r][c] = '.';
            col[c] = diag1[r-c+n] = diag2[r+c] = false;
        }
    }
}

int main(){
    cin >> n;
    
    if(n == 2 || n == 3){
        cout << "Kerajaan tidak dapat dilindungi!\n";
        return 0;
    }
    
    board.assign(n, string(n, '.'));
    
    solve(0);
    
    if(!solved){
        cout << "Kerajaan tidak dapat dilindungi!\n";
    } else {
        for(auto &row : board)
            cout << row << "\n";
    }
}
