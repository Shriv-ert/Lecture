#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, t;
    cin >> n >> t;
    vector<int> arr(n+1);
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }for(int i = 0; i < t; i++){
        unordered_map<int, long long> kel;
        int a,b;
        cin>>a>>b;
        for(int j = a; j<=b; j++){
            if(kel.count(arr[j])){
                kel[arr[j]]++;
            }else{
                kel[arr[j]] = 1;
            }
        }
        long long mx = LLONG_MIN;
        int idx = -1;
        for (auto i = kel.begin(); i != kel.end(); i++) {
            mx = max(mx, i->second);
            if(mx == i->second) idx = i->first;
        }
        cout << "mx: " << mx << " idx: " << idx << endl;
        if(mx > (b-a+1)/2){
            cout<<idx<<'\n';
        }else{
            cout<<-1<<'\n';
        }
    }
    return 0;
}