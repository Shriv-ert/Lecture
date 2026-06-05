#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>
int maxTree(vector<pair<pair<char, int> , pair<char, int>>> a, int i, int n, int res){
    cout << i;
    if(i >= n){
        if(a[i].fi.fi == '+' && a[i].se.fi == '+'){
            return max(res + a[i].fi.se, res + a[i].se.se);
        }else if(a[i].fi.fi == '*' && a[i].se.fi == '+'){
            return max(res * a[i].fi.se, res + a[i].se.se);
        }else if(a[i].fi.fi == '+' && a[i].se.fi == '*'){
            return max(res + a[i].fi.se, res * a[i].se.se);
        }else if(a[i].fi.fi == '*' && a[i].se.fi == '*'){
            return max(res * a[i].fi.se, res * a[i].se.se);
        }
    }else{
        //mencari maksimum dari 2 operasi
        if(a[i].fi.fi == '+' && a[i].se.fi == '+'){
            return max(maxTree(a, i+1, n, res + a[i].fi.se), maxTree(a, i++, n, res + a[i].se.se));
        }else if(a[i].fi.fi == '*' && a[i].se.fi == '+'){
            return max(maxTree(a, i+1, n, res * a[i].fi.se), maxTree(a, i++, n, res + a[i].se.se));
        }else if(a[i].fi.fi == '+' && a[i].se.fi == '*'){
            return max(maxTree(a, i+1, n, res + a[i].fi.se), maxTree(a, i++, n, res * a[i].se.se));
        }else if(a[i].fi.fi == '*' && a[i].se.fi == '*'){
            return max(maxTree(a, i+1, n, res * a[i].fi.se), maxTree(a, i++, n, res * a[i].se.se));
        }
    }
    return res;
}
int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<pair<pair<char, int>, pair<char, int>>> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i].fi.fi>>arr[i].fi.se>>arr[i].se.fi>>arr[i].se.se;
    }
    // for(int i = 0; i < n; i++){
    //     cout<<arr[i].fi.fi<<arr[i].fi.se<<arr[i].se.fi<<arr[i].se.se;
    // }
    cout<<maxTree(arr, 0, n-1, k);
    return 0;
}