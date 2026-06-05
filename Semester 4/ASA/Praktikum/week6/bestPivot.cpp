#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define sz(a) (int)a.size()
#define fi first
#define se second
#define vc(ll) vector<ll>
int counter = 0;

int Partition(vector<ll>& arr, int low, int high,int pivotFirstIdx, bool isFirst) {
    ll pivot;
    if(isFirst){
    swap(arr[high], arr[pivotFirstIdx]);
    }
    pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void QuickSort(vector<ll>& arr, int low, int high,int pivotFirstIdx, bool isFirst){
    counter++;
    if(low < high){
        int pivot = Partition(arr, low, high, pivotFirstIdx, isFirst);
        QuickSort(arr, low, pivot - 1, pivotFirstIdx, false);
        QuickSort(arr, pivot + 1, high, pivotFirstIdx, false);
    }
}
int main() {
    ios::sync_with_stdio(0); cout.tie(0); cin.tie(0);
    int n, idx = -1, min = INT_MAX; cin >> n;
    vc(ll) a(n);
    vc(ll) b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        b = a;
        counter = 0;
        QuickSort(b, 0, n - 1, i, true);
        if(counter < min) {
            min = counter;
            idx = i;
        }
        //cout << i << " " << counter << "\n";
    }
    cout << idx << " " << min << "\n";
    return 0;
}