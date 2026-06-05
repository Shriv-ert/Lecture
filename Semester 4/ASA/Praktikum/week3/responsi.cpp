#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>
vector<vector<int>> res;
void solve(vector<int> arr, int l, int r){
    if (l == r){
        bool pass = true;

        // for(auto &val: arr){
        //     cout<<val;
        // }cout<<endl;
        for(int i = 1; i < r; i++){
            if(!((arr[i-1] < arr[i] && arr[i] > arr[i + 1]) || (arr[i-1] > arr[i] && arr[i] < arr[i + 1]))){
                pass = false;
            }
        }
        if(pass){
            res.push_back(arr);
        }
    }else{
        for(int i = l; i <= r; i++){
            swap(arr[l], arr[i]);
            solve(arr, l + 1, r);
            swap(arr[l], arr[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n, i;
    cin >> n;
    if(n ==1){
        cout<<1;
        return 0;
    }
    if(n == 2){
        cout<<12<<endl;
        cout<<21<<endl;
        return 0;
    }
    vc(int) a(n);
    for(i = 0; i < n; i++){
        a[i] = i+1;
    }
    solve(a, 0, n-1);
    sort(res.begin(), res.end());
    for(auto &vali : res){
        for(auto &valj : vali){
            cout<<valj;
        }
        cout<<endl;
    }
    return 0;
}