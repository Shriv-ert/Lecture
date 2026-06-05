#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>
int const mod =  1000000007;
ll power(ll n, ll k){
    if (k == 0) return 1;
    if (k == 1) return (n % mod);
    ll x = power(n, k / 2);
    if (k % 2 == 0) {
        return (x * x) % mod;
    } else {
        return ((x * x) % mod * n) % mod;
    }
}
int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    ll n, k;
    cin >> n >> k;
    cout << power(n, k);
    return 0;
}