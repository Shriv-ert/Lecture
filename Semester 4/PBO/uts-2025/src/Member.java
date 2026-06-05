import java.util.Date;
import java.time.LocalDate;
import java.util.ArrayList;
public class Member extends Peserta{
    private String noAnggota;
    private Date tanggalBergabung;
    private static int diskon = 10; // Diskon 10% untuk member default
     

    public Member(String noKTP, String nama, String email, String noAnggota, Date tanggalBergabung) {
        super(noKTP, nama, email);
        this.noAnggota = noAnggota;
        this.tanggalBergabung = tanggalBergabung;
    }
    
    // Getter methods
    public String getNoAnggota() {
        return noAnggota;
    }
    public Date getTanggalBergabung() {
        return tanggalBergabung;
    }
    public static int getDiskon() {
        return diskon;
    }
    // Setter methods
    public void setNoAnggota(String noAnggota) {
        this.noAnggota = noAnggota;
    }
    public void setTanggalBergabung(Date tanggalBergabung) {
        this.tanggalBergabung = tanggalBergabung;
    }
    public static void setDiskon(int diskon) {
        Member.diskon = diskon;
    }

    // Implementasi method hitungTotalPembayaran dari interface HitungPembayaran
    @Override
    public double hitungTotalPembayaran(ArrayList<LPK> daftarLPK) {
        double totalPembayaran = 0;
        for (LPK kursus : daftarLPK) {
            totalPembayaran += (kursus.getHarga() - (kursus.getHarga() * diskon / 100.0)) + kursus.hitungPajak();
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
        System.out.println("No KTP              : " + getNoKTP());
        System.out.println("Nama                : " + getNama());
        System.out.println("Email               : " + getEmail());
        System.out.println("No Anggota          : " + noAnggota);
        System.out.println("Tanggal Bergabung   : " + tanggalBergabung);
        for(Registrasi reg : daftarRegistrasi) {
            reg.tampilkanInfo();
        }
    }
}
