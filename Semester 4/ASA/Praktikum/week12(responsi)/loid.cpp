#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, cap;
    cin >> n >> cap;
    vector<ll> oil(n), cost(n);
    for (ll i = 0; i < n; i++) {
        cin >> oil[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> cost[i];
    }
    ll count = 0;
    for (ll i = 0; i < n; i++) {
        ll tank = 0;
        bool save = true;
        for (ll step = 0; step < n; step++) {
            ll idx = (i + step) % n;
            tank = min(cap, tank + oil[idx]);
            if (tank < cost[idx]) {
                save = false;
                break;
            }
            tank -= cost[idx];
        }
        if (save) count++;
    }
    cout << count << endl;
    return 0;
}