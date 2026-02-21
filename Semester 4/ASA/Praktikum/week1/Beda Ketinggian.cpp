#include <bits/stdc++.h>
using namespace std;



int main() {
    int n, i;
    bool isNaik = false;
    cin >> n;
    vector<int> arr(n);
    vector<int> res;
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }
    int max_diff = -1;
    for(i = 0; i < n-1; i++){
        if(arr[i]<arr[i+1]){
            isNaik = true;
            break;
        }else if(arr[i]>arr[i+1]){
            isNaik = false;
            break;
        }
        if(i == n-2 && arr[i]==arr[i+1]){
            cout << 0;
            return 0;
        }
    }
    res.push_back(arr[0]);
    for(i = 1; i < n-1; i++){
        if(isNaik && arr[i]>arr[i+1]){
            res.push_back(arr[i]);
            isNaik = !isNaik;
        }else if(!isNaik && arr[i]<arr[i+1]){
            res.push_back(arr[i]);
            isNaik = !isNaik;
        }
    }
    res.push_back(arr[n-1]);
    for(i = 0; i< res.size()-1; i++){
        max_diff = max(max_diff, abs(res[i]-res[i+1]));
    }
    cout<<max_diff;

    
    return 0;
}