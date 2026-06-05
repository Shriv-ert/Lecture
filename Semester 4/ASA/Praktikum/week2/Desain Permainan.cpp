#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>
const int mod = 1e9 + 7;

vector<ll> fac, inv, facInv;
void precompute(int size) {
    fac.assign(size, 0);
    inv.assign(size, 0);
    facInv.assign(size, 0);
    
    fac[0] = fac[1] = inv[0] = inv[1] = facInv[0] = facInv[1] = 1;
    
    for (int i = 2; i < size; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
        inv[i] = mod - (mod / i) * inv[mod % i] % mod;
        facInv[i] = (facInv[i - 1] * inv[i]) % mod;
    }
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    ll n, k, i, target;
    cin >> n >> k;
    vector<int> nums(n);
    vector<int> prefS(n + 1, 0);
    for(i = 0; i < n; i++){
        cin >> nums[i];
    }
    prefS[0] = nums[0];
    for(i = 1; i < n; i++){
        prefS[i] = prefS[i - 1] + nums[i];
    }
    if(prefS[n - 1] % k != 0){
        cout << 0 << "\n";
        return 0;
    }else{
        target = prefS[n - 1] / k;
    }
    // for(i = 0; i < n; i++){
    //     cout << prefS[i] << " ";
    // }
    ll ans;
    ll res, temp = 0, flag;
    if(target == 0){
        ans = 0;
        for(i = 0; i < n - 1; i++){
            if(prefS[i] == 0){
                ans++;
            }
        }
        if(ans < k - 1){
            cout << 0 << "\n";
            return 0;
        }
        precompute(n);
        res = 1;
        res = (res * fac[ans]) % mod;
        res = (res * facInv[k - 1]) % mod;
        res = (res * facInv[ans - (k - 1)]) % mod;
        cout << res << "\n";
        return 0;
    }else {
        vector<ll> dp(k, 0); 
        dp[0] = 1; 

        for(int i = 0; i < n - 1; i++) {
            ll currentP = prefS[i];
            
            if (currentP % target == 0) {
                ll m = currentP / target;
                if (m >= 1 && m < k) {
                    dp[m] = (dp[m] + dp[m-1]) % mod;
                }
            }
        }
        cout << dp[k-1] << "\n";
        return 0;
    }

    return 0;
}
