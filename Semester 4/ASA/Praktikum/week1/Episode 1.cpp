#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, t, i, j, mx = -1;
    cin >> n >> t;
    vector<int> arr(n+1);
    for(i = 1; i <= n; i++){
        cin >> arr[i];
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j<=n; j++){
            if(i != j && arr[i]+arr[j] == t){
                mx = max(mx, arr[i]*arr[j]);
            }
        }
    }
    cout<<mx;
    return 0;
}