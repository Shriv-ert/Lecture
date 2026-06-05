#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>

void test(vector<vector<ll>>& a, vector<vector<ll>>& b, vector<vector<ll>>& c, ll n) {
    for(int i = 0; i < 5; i++) {

        vc(ll) r(n);
        for (int i = 0; i < n; i++) {
            r[i] = rand() % 2;
        }
        // // debug nilai r
        // cout << "r: ";
        // for (int i = 0; i < n; i++) {
        //     cout << r[i] << " ";
        // }
        // cout << "\n";
        vc(ll) x(n, 0);
        // x = B * r
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                x[i] += b[i][j] * r[j];
            }
        }

        // // debug nilai x
        // cout << "x: ";
        // for (int i = 0; i < n; i++) {
        //     cout << x[i] << " ";
        // }
        // cout << "\n";
        vc(ll) y(n, 0);
        // y = A * x
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                y[i] += a[i][j] * x[j];
            }
        }
        // // debug nilai y
        // cout << "y: ";
        // for (int i = 0; i < n; i++) {
        //     cout << y[i] << " ";
        // }
        vc(ll) z(n, 0);
        // matriks C * r
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                z[i] += c[i][j] * r[j];
            }
        }
        // // debug nilai z
        // cout << "z: ";
        // for (int i = 0; i < n; i++) {
        //     cout << z[i] << " ";
        // }
        // cout << "\n";
        for (int i = 0; i < n; i++) {
            if (y[i] != z[i]) {
                cout << "TIDAK\n";
                return;
            }
        }
    }
    cout << "YA\n";
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    vector<vector<ll>> b(n, vector<ll>(n));
    vector<vector<ll>> c(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }
    test(a, b, c, n);
    return 0;
}