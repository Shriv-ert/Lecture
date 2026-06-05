#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>

bool isValid(vector<ll>& arr, int x, ll t) {
    ll sum = 0;
    for (ll val : arr) {
        if (val == 0){
            cout << 0;
            exit(0);
        }
        sum += floor(sqrt(t / val));
        if (sum >= x) return true; // Jika sudah melebihi x, tidak perlu lanjut
    }
    return sum >= x;
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n;
    cin >> n;
    vc(ll) arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    // mencari nilai x dengan modifikasi rumus jadi floor(sqrt(t/arr[i])) dijumlahkan semua hingga sum == x. 
    // menggunakan pendekatan binaru search.
    int l = 0, r = 100 * x * x;
    while (l < r) {
        int mid = (l + r) / 2;
        if (isValid(arr, x, mid)) {
            r = mid; // Cari di kiri
        } else {
            l = mid + 1; // Cari di kanan
        }
    }
    cout << l << "\n";


    return 0;
}