import random

# Karakter DNA valid
DNA_CHARS = ['A', 'C', 'G', 'T']

def generate_dna_string(length):
    return ''.join(random.choices(DNA_CHARS, k=length))

# Konstanta batas
N = 1000
X = 1000
Xi = 1000

# Tulis ke file
with open("big_input.txt", "w") as f:
    f.write(f"{N} {X}\n")
    f.write(generate_dna_string(N) + "\n")
    
    for _ in range(X):
        f.write(f"{Xi} {generate_dna_string(Xi)}\n")
