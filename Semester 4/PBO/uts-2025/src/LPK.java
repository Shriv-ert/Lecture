public abstract class LPK implements HitungPajak {
    private String informasiKode;
    private String nama;
    private String namaInstruktur;
    private int kuota;
    private int harga;
    private int pajak;
    public LPK(String informasiKode, String nama, String namaInstruktur, int kuota, int harga, int pajak) {
        this.informasiKode = informasiKode;
        this.nama = nama;
        this.namaInstruktur = namaInstruktur;
        this.kuota = kuota;
        this.harga = harga;
        this.pajak = pajak;
    }
    // Getter methods
    public String getInformasiKode() {
        return informasiKode;
    }
    public String getNama() {
        return nama;
    }
    public String getNamaInstruktur() {
        return namaInstruktur;
    }
    public int getKuota() {
        return kuota;
    }
    public int getHarga() {
        return harga;
    }
    public int getPajak() {
        return pajak;
    }
    // Setter methods
    public void setInformasiKode(String informasiKode) {
        this.informasiKode = informasiKode;
    }
    public void setNama(String nama) {
        this.nama = nama;
    }
    public void setNamaInstruktur(String namaInstruktur) {
        this.namaInstruktur = namaInstruktur;
    }
    public void setHarga(int harga) {
        this.harga = harga;
    }
    public void setPajak(int pajak) {
        this.pajak = pajak;
    }
        // implementasi method hitungPajak dari interface HitungPajak
    @Override
    public double hitungPajak() {
        return getHarga() + (getHarga() * getPajak()) / 100.0;
    }
    // Abstract method to be implemented by subclasses
    public abstract void tampilkanInfo();
}
