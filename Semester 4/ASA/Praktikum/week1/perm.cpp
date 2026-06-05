#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>

void ubah(int &a) {
    a = 10;
}
int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    //nyoba buat fungsi mengubah variable a
    int a = 5;
    cout << "Sebelum diubah: " << a << endl;
    ubah(a);
    cout << "Setelah diubah: " << a << endl;
    return 0;
}