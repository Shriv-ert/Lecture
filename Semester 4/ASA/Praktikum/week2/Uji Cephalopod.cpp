#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>

int cnt(string s, int n, int i = 0){
    if(n-i<2) return 0;
    else if(s[i] == 'X' && s[i+1] == 'Y'){
        //cout << "yay" << endl;
        return 1 + cnt(s, n, i + 1);
    }else{
        return cnt(s, n, i + 1);
    }
}
int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    string s;
    cin >> s;
    int n = sz(s);
    if(cnt(s, n) % 2 == 0 && cnt(s, n) > 0){
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}