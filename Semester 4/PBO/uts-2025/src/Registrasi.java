import java.time.LocalDate;

public class Registrasi {
    private LocalDate tanggalRegistrasi;
    private LocalDate tanggalPembayaran;
    private String metodePembayaran;
    public Registrasi(LocalDate tanggalRegistrasi, LocalDate tanggalPembayaran, String metodePembayaran) {
        this.tanggalRegistrasi = tanggalRegistrasi;
        this.tanggalPembayaran = tanggalPembayaran;
        this.metodePembayaran = metodePembayaran;
    }
    // Getter methods
    public LocalDate getTanggalRegistrasi() {
        return tanggalRegistrasi;
    }
    public LocalDate getTanggalPembayaran() {
        return tanggalPembayaran;
    }
    public String getMetodePembayaran() {
        return metodePembayaran;
    }
    // Setter methods
    public void setTanggalRegistrasi(LocalDate tanggalRegistrasi) {
        this.tanggalRegistrasi = tanggalRegistrasi;
    }
    public void setTanggalPembayaran(LocalDate tanggalPembayaran) {
        this.tanggalPembayaran = tanggalPembayaran;
    }
    public void setMetodePembayaran(String metodePembayaran) {
        this.metodePembayaran = metodePembayaran;
    }
    //
    public void tampilkanInfo() {
        System.out.println("Tanggal Registrasi  : " + tanggalRegistrasi);
        System.out.println("Tanggal Pembayaran  : " + tanggalPembayaran);
        System.out.println("Metode Pembayaran   : " + metodePembayaran);
    }
}
