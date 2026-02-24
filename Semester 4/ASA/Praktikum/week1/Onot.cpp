#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int main() {
    clock_t start_time = clock();
    long long count = 0;
    while (double(clock() - start_time) / CLOCKS_PER_SEC < 1) {
        count++;
    }
    cout << "Count operations in 1 second: " << count << endl;
    return 0;
}