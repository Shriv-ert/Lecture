import java.time.LocalDate;

public class Insidental extends LPK{
    private LocalDate tanggalMulai;
    private boolean isOnline;
    public Insidental(String informasiKode, String nama, String namaInfrastruktur, int kuota, int harga, int pajak, LocalDate tanggalMulai, boolean isOnline) {
        super(informasiKode, nama, namaInfrastruktur, kuota, harga, pajak);
        this.tanggalMulai = tanggalMulai;
        this.isOnline = isOnline;
    }
    // Getter methods
    public LocalDate getTanggalMulai() {
        return tanggalMulai;
    }
    public boolean isOnline() {
        return isOnline;
    }
    // Setter methods
    public void setTanggalMulai(LocalDate tanggalMulai) {
        this.tanggalMulai = tanggalMulai;
    }
    public void setOnline(boolean isOnline) {
        this.isOnline = isOnline;
    }
    
    @Override
    public void tampilkanInfo() {
        System.out.println("Informasi Kode      : " + getInformasiKode());
        System.out.println("Nama Jenis          : " + this.getClass().getSimpleName());
        System.out.println("Kuota               : " + getKuota());
        System.out.println("Harga               : " + getHarga());
        System.out.println("Pajak               : " + getPajak() + "%");
        System.out.println("Harga Kursus setelah Pajak : " + hitungPajak());
        System.out.println("Tanggal Mulai       : " + getTanggalMulai());
        System.out.println("Metode Kursus       : " + (isOnline ? "Online" : "Offline"));
    }
}
