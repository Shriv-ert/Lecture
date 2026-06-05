#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>
void merge(vc(ll) &v, int l, int m, int r) {
    int i = l, j = m + 1;
    vc(ll) temp;
    while (i <= m && j <= r) {
        if (v[i] < v[j]){
            temp.pb(v[i]);
            i++;
        }
        else {
            temp.pb(v[j]);
            j++;
        }
    }
    while (i <= m){
        temp.pb(v[i]);
        i++;
    }
    while (j <= r){
        temp.pb(v[j]);
        j++;
    }
    for (int i = l; i <= r; i++){
        v[i] = temp[i - l];
    }
}
void mergeSort(vc(ll) &v, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    mergeSort(v, l, m);
    mergeSort(v, m + 1, r);
    merge(v, l, m, r);
}
//pivot = v[len/2]
int partition(vector<int>& arr, int low, int high) {
  
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
  
    if (low < high) {
      
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n; cin >> n;
    vc(ll) v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    mergeSort(v, 0, n - 1);
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    
    return 0;
}