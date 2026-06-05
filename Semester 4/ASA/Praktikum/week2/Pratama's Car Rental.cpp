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
    int n, m, x, a, b, c, mn = INT16_MAX, Spi, Svi, Sci, i, j;
    cin >> n >> m >> x;
    vector<pair<int,pair<int,int>>> arr(n);
    for (i = 0; i < n; i++) {
        cin >> a >> b >> c;
        arr[i] = {a, {b, c}};
    }
    for(i = 0; i < (1 << n); i++){
        Spi = 0, Svi = 0, Sci = 0;
        for(j = 0; j < n; j++){
            if(i & (1 << j)){
                Spi += arr[j].fi;
                Svi += arr[j].se.fi;
                Sci += arr[j].se.se;
            }
            if(Spi >= m && Svi >= x){
                mn = min(mn, Sci);
            }
        }
    }
    if(mn == INT16_MAX) cout << -1 << endl;
    else cout << mn << endl;

    return 0;
}