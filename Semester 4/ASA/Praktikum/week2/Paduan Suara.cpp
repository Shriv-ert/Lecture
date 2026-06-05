#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>

void bubblesort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int m;
    cin >> m;
    vector<int> nums(m + 1);
    for(int i = 1; i <= m; i++){
        cin >> nums[i];
    }
    int n;
    cin >> n;
    int grup = m/n;
    int cnt = 0;
    bubblesort(nums);
    for(int i = 1; i <= m && cnt < n; i++){
        if(i > (grup) && (i%(grup) == 1 || grup == 1)){
            cout << nums[i] << " ";
            cnt++;
        }
    }
    return 0;
}
