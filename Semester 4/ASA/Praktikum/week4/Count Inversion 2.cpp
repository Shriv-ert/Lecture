
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>
int cnt = 0;
void merge(vc(ll) &v, int l, int m, int r) {
    int i = l, j = m + 1;
    vc(ll) temp;
        for (int i = l; i <= r; i++){
        cout << v[i] << " | ";
    }
    cout<<endl;
    while (i <= m && j <= r) {
        cout << v[i] << " " <<v[j] << endl;
        if (v[i] > v[j]){
            cnt++;
            temp.pb(v[j]);
            
            j++; 
        }
        else {
            //cout << v[i] << " " <<v[j] << endl;
            temp.pb(v[i]);
            i++;
        }
    }
    cout << endl;
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
        cout << v[i] << " : ";
    }
    cout<<endl;
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
    int n; cin >> n;
    vc(ll) v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    mergeSort(v, 0, n-1);
    cout << cnt;
    
    return 0;
}