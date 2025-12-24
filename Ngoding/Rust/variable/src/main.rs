fn main() {
    let umur: i32 = 14; // integer 32 bit
    let tinggi: f64 = 1.73; // float 64 bit
    let name: &str = "Polym";
    println!("Nama saya {}", name);
    print!("Umur saya {} tahun\n", umur);
    println!("Tinggi saya {} meter", tinggi);
    // umur = 20; //error karena umur adalah immutable( tidak bisa diubah nilainya )
    println!("Umur saya sekarang {} tahun", umur);
    let mut nilai: i32 = 65; // mutable variable
    println!("Nilai saya adalah {}", nilai);
    nilai = 80;
    println!("Nilai setelah remidial adalah {}", nilai);
    let lulus: bool = nilai >= 75; // boolean
    println!("Apakah saya lulus? {}", lulus);
    let rank: char = 'B'; // character
    println!("Peringkat saya adalah {}", rank);
}
