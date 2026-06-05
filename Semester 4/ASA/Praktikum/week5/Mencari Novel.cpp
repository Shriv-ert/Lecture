// NAMA : Shofwan Fikrul Huda
// NIM : 24060124130106

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>

// fungsi menemukan nilai x menggunakan binary search upperbound
ll batasAtas(vector<ll>& v, ll x) {
    ll l = 0, r = sz(v) - 1;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (v[mid] <= x) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return l;
}
// fungsi menemukan nilai x menggunakan binary search lowerbound
ll batasBawah(vector<ll>& v, ll x) {
    ll l = 0, r = sz(v) - 1;
    while (l < r) {
        ll mid = (l + r) / 2;
        if (v[mid] >= x) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
    
int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n;
    cin >> n;
    vc(ll) arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int a;
    cin >> a;

    ll atas = batasAtas(arr, a);
    ll bawah = batasBawah(arr, a);
    if(arr[bawah] == a){
        cout <<bawah << " ";
    }else{
        cout <<-1 << " ";
    }
    if(arr[atas] == a){
        cout <<atas << "\n";
    }else{
        cout <<-1 << "\n";
    }
    
    return 0;
}