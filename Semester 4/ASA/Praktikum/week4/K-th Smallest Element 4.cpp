#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>
void merge(vc(ll) &v, int l, int m, int r) {
    int i = l, j = m + 1;
    vc(ll) temp;
    while (i <= m && j <= r) {
        if (v[i] < v[j]){
            temp.pb(v[i]);
            i++;
        }
        else {
            temp.pb(v[j]);
            j++;
        }
    }
    while (i <= m){
        temp.pb(v[i]);
        i++;
    }
    while (j <= r){
        temp.pb(v[j]);
        j++;
    }
    for (int i = l; i <= r; i++){
        v[i] = temp[i - l];
    }
}
void mergeSort(vc(ll) &v, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);
    merge(v, l, m, r);
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vc(ll) v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    mergeSort(v, 0, n-1);
    cout<< v[k-1];
    return 0;
}