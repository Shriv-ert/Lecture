import random

# Pastikan N kelipatan 16 sesuai asumsi fungsi SIMD kita
N = 4096  
Q = 10      # Jumlah query pencarian

# Generate array yang sudah terurut (ascending)
print("Sedang membuat array terurut...")
arr = sorted([random.randint(0, 60000) for _ in range(N)]) # Tambahkan angka besar untuk memastikan ada nilai yang lebih besar dari 60000
# Generate queries
# Kita ambil 8 angka acak yang PASTI ADA di dalam array
queries = [random.choice(arr) for _ in range(Q - 2)]
# Kita tambahkan 2 angka spesifik yang KEMUNGKINAN BESAR TIDAK ADA di array
queries.extend([65000, 65001]) 

# Tulis ke dalam file testcase.txt
with open("testcase.txt", "w") as f:
    f.write(f"{N} {Q}\n")
    f.write(" ".join(map(str, arr)) + "\n")
    f.write(" ".join(map(str, queries)) + "\n")

print("File 'testcase.txt' berhasil dibuat!")