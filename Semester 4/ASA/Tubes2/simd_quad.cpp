
#pragma GCC optimize("O3")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
#include <immintrin.h>
      // Untuk clock(), clock_t, dan CLOCKS_PER_SEC
using namespace std;

// ==========================================
// 1. STANDARD BINARY SEARCH
// ==========================================
int binary_search_standard(const uint16_t* arr, size_t size, uint16_t target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

// ==========================================
// 2. INTERPOLATION SEARCH
// ==========================================
int interpolation_search(const uint16_t* arr, size_t size, uint16_t target) {
    int left = 0;
    int right = size - 1;

    // Syarat loop: target harus berada di dalam rentang nilai array saat ini
    while (left <= right && target >= arr[left] && target <= arr[right]) {
        // PENCEGAHAN ERROR: Jika nilai ujung sama, hindari pembagian dengan nol
        if (arr[right] == arr[left]) {
            if (arr[left] == target) return left;
            return -1;
        }

        // Rumus Interpolasi (menebak posisi)
        // Menggunakan double untuk akurasi presisi sebelum di-cast kembali ke int
        int pos = left + (((double)(right - left) / (arr[right] - arr[left])) * (target - arr[left]));

        if (arr[pos] == target) return pos;

        if (arr[pos] < target) left = pos + 1;
        else right = pos - 1;
    }
    return -1;
}

// ==========================================
// 3. SIMD QUAD SEARCH (Versi Aman)
// ==========================================
int simd_quad_search(const uint16_t* array, size_t size, uint16_t target) {
    size_t left = 0;
    size_t n = size / 16;

    while (n > 3) {
        size_t quarter = n / 4;
        size_t k1 = (left + quarter) * 16 - 1;
        size_t k2 = (left + 2 * quarter) * 16 - 1;
        size_t k3 = (left + 3 * quarter) * 16 - 1;

        if (target <= array[k1]) { n = quarter; } 
        else if (target <= array[k2]) { left += quarter; n = quarter; } 
        else if (target <= array[k3]) { left += 2 * quarter; n = quarter; } 
        else { left += 3 * quarter; n -= 3 * quarter; }
    }

    while (n > 0) {
        if (target <= array[(left + 1) * 16 - 1]) break;
        left++;
        n--;
    }

    if (n == 0) return -1;

    __m256i target_vec = _mm256_set1_epi16(target);
    __m256i array_vec = _mm256_loadu_si256((__m256i*)&array[left * 16]);
    __m256i cmp_result = _mm256_cmpeq_epi16(target_vec, array_vec);
    int mask = _mm256_movemask_epi8(cmp_result);

    if (mask != 0) {
        int offset = __builtin_ctz(mask) / 2;
        return left * 16 + offset;
    }
    return -1;
}

// ==========================================
// MAIN FUNCTION & BENCHMARKING
// ==========================================
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, Q;
    if (!(cin >> N >> Q)) return 0;

    vector<uint16_t> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    vector<uint16_t> targets(Q);
    for (int i = 0; i < Q; i++) {
        cin >> targets[i];
    }

    const int ITERATIONS = 4096; 
    volatile long long dummy_sum = 0; 

    cout << "Mulai Benchmarking (" << ITERATIONS << " iterasi untuk " << Q << " query)...\n\n";

    // --- TEST 1: BINARY SEARCH ---
    clock_t start_bin = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        for (uint16_t target : targets) dummy_sum += binary_search_standard(arr.data(), N, target);
    }
    clock_t end_bin = clock();
    double time_bin = double(end_bin - start_bin) / CLOCKS_PER_SEC;

    // --- TEST 2: INTERPOLATION SEARCH ---
    clock_t start_intp = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        for (uint16_t target : targets) dummy_sum += interpolation_search(arr.data(), N, target);
    }
    clock_t end_intp = clock();
    double time_intp = double(end_intp - start_intp) / CLOCKS_PER_SEC;

    // --- TEST 3: SIMD QUAD SEARCH ---
    clock_t start_simd = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        for (uint16_t target : targets) dummy_sum += simd_quad_search(arr.data(), N, target);
    }
    clock_t end_simd = clock();
    double time_simd = double(end_simd - start_simd) / CLOCKS_PER_SEC;

    // --- HASIL ---
    cout << "1. Waktu Binary Search \t\t: " << time_bin << " detik\n";
    cout << "2. Waktu Interpolation Search \t: " << time_intp << " detik\n";
    cout << "3. Waktu SIMD Quad Search \t: " << time_simd << " detik\n\n";

    return 0;
}