#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n; cin>>n;
    double a;
    for (int i=1 ; i<=n ; i++){
        cin>>a;
        cout<<(1.0/a)<<'\n';
    }
    return 0;
}