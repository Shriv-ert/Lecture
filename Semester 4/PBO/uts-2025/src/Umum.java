import java.time.LocalDate;
import java.util.ArrayList;

public class Umum extends Peserta {

    
    public Umum(String noKTP, String nama, String email) {
        super(noKTP, nama, email);
    }

        // Implementasi method hitungTotalPembayaran dari interface HitungPembayaran
    @Override
    public double hitungTotalPembayaran(ArrayList<LPK> daftarLPK) {
        double totalPembayaran = 0;
        for (LPK kursus : daftarLPK) {
            totalPembayaran += (kursus.getHarga()) + kursus.hitungPajak();
        }
        return totalPembayaran;
    }

    @Override
    public void tambahKursus(LPK kursus, LocalDate tanggalRegistrasi, LocalDate tanggalPembayaran, String metodePembayaran) 
                throws IllegalArgumentException {
        if(daftarKursus.size() >= 3) {
            throw new IllegalArgumentException("Maaf, member hanya dapat mendaftar maksimal 3 kursus.");
        }else{
            daftarKursus.add(kursus);
            Registrasi registrasi = new Registrasi(tanggalRegistrasi, tanggalPembayaran, metodePembayaran);
            daftarRegistrasi.add(registrasi);
        }
    }

    @Override
    public void tampilkanInfo() {
        System.out.println("Informasi Peserta Umum:");
        System.out.println("No KTP              : " + getNoKTP());
        System.out.println("Nama                : " + getNama());
        System.out.println("Email               : " + getEmail());
        for(Registrasi reg : daftarRegistrasi) {
            reg.tampilkanInfo();
        }
    }
}
