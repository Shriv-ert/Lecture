public class Regular extends LPK {
    private int durasiKursus;
    private String jenisLevel;
    private String metodeKursus;

    public Regular(String informasiKode, String nama, String namaInfrastruktur, int kuota, int harga, int pajak, int durasiKursus, String jenisLevel, String metodeKursus) 
            throws IllegalArgumentException {
        super(informasiKode, nama, namaInfrastruktur, kuota, harga, pajak);
        if(durasiKursus == 3 || durasiKursus == 6) {
            this.durasiKursus = durasiKursus;
        }else {
            throw new IllegalArgumentException("Durasi kursus harus antara 3 hingga 6 bulan.");
        }
        this.jenisLevel = jenisLevel;
        this.metodeKursus = metodeKursus;
    }
    // Getter methods
    public int getDurasiKursus() {
        return durasiKursus;
    }
    public String getJenisLevel() {
        return jenisLevel;
    }
    public String getMetodeKursus() {
        return metodeKursus;
    }
    // Setter methods
    public void setDurasiKursus(int durasiKursus) {
        this.durasiKursus = durasiKursus;
    }
    public void setJenisLevel(String jenisLevel) {  
        this.jenisLevel = jenisLevel;
    }
    public void setMetodeKursus(String metodeKursus) {
        this.metodeKursus = metodeKursus;
    }

    @Override
    public void tampilkanInfo() {
        System.out.println("Informasi Kode      : " + getInformasiKode());
        System.out.println("Nama Jenis          : " + this.getClass().getSimpleName());
        System.out.println("Kuota               : " + getKuota());
        System.out.println("Harga               : " + getHarga());
        System.out.println("Pajak               : " + getPajak() + "%");
        System.out.println("Harga Kursus setelah Pajak : " + hitungPajak());
        System.out.println("Durasi Kursus       : " + getDurasiKursus() + " bulan");
        System.out.println("Jenis Level         : " + getJenisLevel());
        System.out.println("Metode Kursus       : " + getMetodeKursus());
    }

}
