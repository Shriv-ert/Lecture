// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define pb push_back
// #define all(v) v.begin(), v.end()
// #define sz(a) (int)a.size()
// #define fi first
// #define se second
// #define vc(ll) vector<ll> 



// int main() {
//     ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
//     int n, x, y, cnt = 0, i;
//     bool can = false;
//     cin >> n >> x >> y;
//     vector<int> arr(n);
//     for(int i = 0; i < n; i++){
//         cin >> arr[i];
//     }
//     i = 0;
//     while (x>0 && i < n) {
//         //debug all
        

//         x--;
//         if(arr[i] == 7) cnt++;
//         else if(arr[i] <= 6)x+=arr[i];
//         if(cnt == y) can = true;
//         //cout << "x: " << x << " y: " << y << " cnt: " << cnt << " arr[i]: " << arr[i] << " can: " << can << endl;
//         if(x == 0 && cnt > 0 && i < n-1){
//             x+= 7;
//             cnt--;
//         }else if(x == 0 && cnt == 0){
//             can = false;
//             break;
//         }
//         //cout << "x: " << x << " y: " << y << " cnt: " << cnt << " arr[i]: " << arr[i] << endl;
//         i++;
//     }
//     if(can && cnt > y) cout << cnt;
//     else if(can && cnt <= y) cout << y;
//     else cout << -1;
//     return 0;
// }
/* Mohon untuk Mengisi identitas berikut sebelum mengerjakan
 Nama : Rio Setiawan Hastanu Putra
 NIM  : 24060124130068
 Lab  : C1
*/

#include <bits/stdc++.h>
using namespace std;


int main() {
    int N, Q, Ni, Mi, SumUp, SumDown;
    long long Xi;
    cin >> N;
    int A[N];
    int up[N];
    int down[N];
    
    up[0] = 0;
    down[N-1] = 0;
    
    SumUp = 0;
    SumDown = 0;
    
    cin >> A[0];
    for(int i = 1; i < N; i++){
        cin >> A[i];
        if(A[i] > A[i-1])
        {
            SumUp += A[i] - A[i-1];
            up[i] = SumUp;
        }
        else
        {
            up[i] = SumUp;
        }
    }
    for(int i = N-2; i >= 0; i--){
        if(A[i] > A[i+1])
        {
            SumDown += A[i] - A[i+1];
            down[i] = SumDown;
        }
        else
        {
            down[i] = SumDown;
        }
    }
    cin >> Q;
    for(int j = 0; j < Q; j++){
        cin >> Ni >> Mi >> Xi;
        Ni -= 1;
        Mi -= 1;
        if(Ni < Mi){
            Xi = Xi - (up[Mi] - up[Ni]);
        }
        else{
            Xi = Xi - (down[Mi] - down[Ni]);
        }
        if(Xi < 0){
            Xi = -1;
        }
        cout << Xi << endl;
    }
    return 0;
}


/*Gimana, Aman ?
Tinggalkan saran di sini : 

*/