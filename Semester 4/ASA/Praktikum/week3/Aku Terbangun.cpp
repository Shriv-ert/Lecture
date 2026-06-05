#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>
//iterasi dengan cara rekursif depan belakang jika beda sesuaikan dengan biaya
int biaya(string s, string t, int i, int n){
    if(i >= n){
        return 0;
    }else{
        if(s[i] != t[i]){
            return 2 + biaya(s, t, i+1, n);
        }else{
            return biaya(s, t, i+1, n);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    string s, t;
    cin >> s >> t;
    int n = s.size();
    cout<< biaya(s, t, 0, n);
    return 0;
}