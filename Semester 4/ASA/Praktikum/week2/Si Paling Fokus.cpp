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
    int n, t, i, j, k;
    //bool isUse;
    cin >> n >> t;
    vector<pair<int, int>> a(n);
    for (i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    for(i = 0; i < n; i++){
        if(a[i].fi >= 5){
            a.erase(a.begin() + i);
            i--;
            n--;
        }
    }
    vector<vector<int>> dp((t + 1), vector<int>(n, -1));
    for(i = 0; i < n; i++){
        dp[a[i].fi][i] = max(dp[a[i].fi][i], a[i].se);
    }
    for(i = 1; i <= t; i++){
        for(j = 0; j < n; j++){
            if(dp[i][j] == -1){
                continue;
            }
            for(k = 0; k < n; k++){
                if(j!=k && a[k].fi + i <= t ){
                    dp[i + a[k].fi][k] = max(dp[i + a[k].fi][k], dp[i][j] + a[k].se);
                }
            }
            // for(int x = 0; x <= t; x++){
            //     for(int y = 0; y < n; y++){
            //         cout << dp[x][y] << "\t";
            //     }
            //     cout << endl;
            // }
            // cout << endl;
        }
    }
    int ans = 0;
    for(i = 0; i <= t; i++){
        for(j = 0; j < n; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    

    return 0;
}