#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(int) vector<int>

int mn = INT_MAX;
vector<vector<int>> perm;
void solve(vector<int> arr, int l, int r){
    if (l == r){
        int cnt = 0;
        for(int i = 1; i < r; i++){
            cnt += perm[arr[i]][arr[i + 1]];
        }
        //cout << cnt << "\n";
        mn = min(mn, cnt);
    }else{
        for(int i = l; i <= r; i++){
            swap(arr[l], arr[i]);
            solve(arr, l + 1, r);
            swap(arr[l], arr[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n, sum = 0, x;
    cin >> n;
    vector<int> arr(n + 1);
    perm.resize(n + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        cin >> x;
        sum = sum + x;
        arr[i] = i;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> perm[i][j];
        }
    }
    solve(arr, 1, n);
    cout << mn + sum << "\n";
    
    return 0;
}