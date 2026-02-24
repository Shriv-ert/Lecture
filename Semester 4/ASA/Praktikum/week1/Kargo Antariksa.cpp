#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, i, cnt = 0, max1 = -1, max2 = -1, max3 = -1, idx;
    cin >> n;
    vector <int> w(n);
    for(i = 0; i < n; i++){
        cin >> w[i];
        if(w[i]%2==1)cnt++;
    }
    if(cnt>1){
        for(i = 0; i < n; i++){
            if(w[i]%2==1){
                max1 = max(max1,w[i]);
                if(max1 == w[i]) idx = i;
            }
        }
        w.erase(w.begin()+idx);
         cout << endl;
        for(i = 0; i < n-1; i++){
            if(w[i]%2==1){
                max2 = max(max2,w[i]);
                if(max2 == w[i]) idx = i;
            }
        }
        w.erase(w.begin()+idx);
        for(i = 0; i < n-2; i++){
            max3 = max(max3,w[i]);
        }
        cout << max1+max2+max3;
    }else{
        cout<<-1;
    }


    return 0;
}