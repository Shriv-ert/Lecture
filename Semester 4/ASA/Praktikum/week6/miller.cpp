#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>

bool millerRabin(ll n, ll k = 5) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0) return false;
    // tulis n-1 as d * 2^r
    ll r = 0, d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }
    // witness loop
    for (int i = 0; i < k; i++) {
        ll a = 2 + rand() % (n - 4); // random [2, n-2]
        // hitung a^d % n
        ll x = 1, p = d;
        ll base = a % n;
        while (p > 0) {
            if (p % 2 == 1) x = (x * base) % n;
            base = (base * base) % n;
            p /= 2;
        }
        if (x != 1 && x != n - 1) {
            bool komposit = true;
            for (int j = 0; j < r - 1; j++) {
                x = (x * x) % n;
                if (x == n - 1) {
                    komposit = false;
                    break;
                }
            }
            if (komposit) return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int t; cin >> t;
    if (millerRabin(t)) {
        cout << "SELAMAT ULANG TAHUN\n";
    } else {
        cout << "KODE SALAH\n";
    }
    return 0;
}