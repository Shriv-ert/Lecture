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
    int t;
    cin >> t;
    while(t--){
        int n, m, temp1, temp2;
        cin >> n >> m;
        for(ll i = 1; i < m; i*=2){
            temp1 = i;
        }for(ll i = 1; i < n; i*=2){
            temp2 = i;
        }
        cout << temp1 << " " << temp2 << "\n";
        cout << temp1 - temp2 * 4 << "\n";
    }
    return 0;
}