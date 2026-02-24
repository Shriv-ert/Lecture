#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll> 



int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n, i, j;
    cin >> n;
    vector<int> arr(n + 1);
    for(i = 1; i <= n; i++){
        cin >> arr[i];
    }int t;
    vector<int> up(n + 1, 0), down(n + 1, 0);
    for(i = 1; i < n; i++){
        if(arr[i] < arr[i+1]) up[i+1] = up[i] + arr[i+1] - arr[i];
        else up[i+1] = up[i];
    }

    for(i = n; i > 0; i--){
        if(arr[i] < arr[i-1]) down[i-1] = down[i] + arr[i-1] - arr[i];
        else down[i-1] = down[i];
    }
    for (i = 1; i <= n; i++){
        cout << up[i] << " ";
    }
    cout << "\n";
    for (i = 1; i <= n; i++){
        cout << down[i] << " ";
    }
    cout << "\n";
    cin >> t;
    for (i = 0; i < t; i++){
        long long sumUp = 0, sumDown = 0, a, b, x;
        cin >> a >> b >> x;
        if(a < b){
            sumUp = up[b] - up[a];
            if(sumUp <= x) cout << x - sumUp <<"\n";
            else cout << -1 << "\n";
        }else if(a > b){
            sumDown = down[a] - down[b];
            if(sumDown <= x) cout << x - sumDown <<"\n";
            else cout << -1 << "\n";
        }else{
            cout << x << "\n";
        }
    }
    return 0;
}