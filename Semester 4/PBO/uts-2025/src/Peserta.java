import java.util.ArrayList;
import java.time.LocalDate;
public abstract class Peserta implements HitungPembayaran {
    private String noKTP;
    private String nama;
    private String email;
    protected ArrayList<LPK> daftarKursus;
    protected ArrayList<Registrasi> daftarRegistrasi;

    public Peserta(String noKTP, String nama, String email) {
        this.noKTP = noKTP;
        this.nama = nama;
        this.email = email;
        this.daftarKursus = new ArrayList<>();
        this.daftarRegistrasi = new ArrayList<>();
    }

    // Getter methods
    public String getNoKTP() {
        return noKTP;
    }

    public String getNama() {
        return nama;
    }

    public String getEmail() {
        return email;
    }

    // Setter methods
    public void setNoKTP(String noKTP) {
        this.noKTP = noKTP;
    }
    public void setNama(String nama) {
        this.nama = nama;
    }
    public void setEmail(String email) {
        this.email = email;
    }

    // Abstract method to be implemented by subclasses
    public abstract void tampilkanInfo();

    public abstract void tambahKursus(LPK kursus, LocalDate tanggalRegistrasi, LocalDate tanggalPembayaran, String metodePembayaran);
}
