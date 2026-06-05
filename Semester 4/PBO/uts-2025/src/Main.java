import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Date;

public class Main {
    public static void main(String[] args) {

        // ============================================================
        // 1. Membuat data kursus (LPK)
        // ============================================================

        // Kursus Regular
        Regular kursusRegular1 = new Regular(
                "REG-001", "Pemrograman Java", "Budi Santoso",
                30, 1500000, 11, 3, "Beginner", "Online"
        );

        Regular kursusRegular2 = new Regular(
                "REG-002", "Data Science dengan Python", "Siti Rahayu",
                20, 2000000, 11, 6, "Intermediate", "Offline"
        );

        // Kursus Insidental
        Insidental kursusInsidental1 = new Insidental(
                "INS-001", "Workshop UI/UX Design", "Ahmad Fauzi",
                50, 500000, 11,
                LocalDate.of(2025, 5, 10), true
        );

        Insidental kursusInsidental2 = new Insidental(
                "INS-002", "Seminar Cyber Security", "Dewi Lestari",
                100, 750000, 11,
                LocalDate.of(2025, 6, 20), false
        );

        // ============================================================
        // 2. Menampilkan informasi kursus
        // ============================================================

        System.out.println("========================================");
        System.out.println("       DAFTAR KURSUS TERSEDIA           ");
        System.out.println("========================================");

        System.out.println("\n--- Kursus Regular 1 ---");
        kursusRegular1.tampilkanInfo();

        System.out.println("\n--- Kursus Regular 2 ---");
        kursusRegular2.tampilkanInfo();

        System.out.println("\n--- Kursus Insidental 1 ---");
        kursusInsidental1.tampilkanInfo();

        System.out.println("\n--- Kursus Insidental 2 ---");
        kursusInsidental2.tampilkanInfo();

        // ============================================================
        // 3. Membuat peserta: Umum dan Member
        // ============================================================

        Umum pesertaUmum = new Umum(
                "3374012501990001", "Rina Kusuma", "rina.kusuma@email.com"
        );

        Member pesertaMember = new Member(
                "3374025501850002", "Doni Prasetyo", "doni.prasetyo@email.com",
                "MBR-2024-001", new Date()
        );

        // ============================================================
        // 4. Pendaftaran kursus untuk peserta Umum
        // ============================================================

        System.out.println("\n========================================");
        System.out.println("       PENDAFTARAN KURSUS               ");
        System.out.println("========================================");

        try {
            pesertaUmum.tambahKursus(
                    kursusRegular1,
                    LocalDate.of(2025, 4, 1),
                    LocalDate.of(2025, 4, 5),
                    "Transfer Bank"
            );
            System.out.println("[Umum] Berhasil mendaftar kursus: " + kursusRegular1.getNama());

            pesertaUmum.tambahKursus(
                    kursusInsidental1,
                    LocalDate.of(2025, 4, 2),
                    LocalDate.of(2025, 4, 6),
                    "QRIS"
            );
            System.out.println("[Umum] Berhasil mendaftar kursus: " + kursusInsidental1.getNama());

        } catch (IllegalArgumentException e) {
            System.out.println("[Umum] Gagal mendaftar: " + e.getMessage());
        }

        // ============================================================
        // 5. Pendaftaran kursus untuk peserta Member
        // ============================================================

        try {
            pesertaMember.tambahKursus(
                    kursusRegular1,
                    LocalDate.of(2025, 4, 1),
                    LocalDate.of(2025, 4, 3),
                    "Kartu Kredit"
            );
            System.out.println("[Member] Berhasil mendaftar kursus: " + kursusRegular1.getNama());

            pesertaMember.tambahKursus(
                    kursusRegular2,
                    LocalDate.of(2025, 4, 2),
                    LocalDate.of(2025, 4, 4),
                    "Transfer Bank"
            );
            System.out.println("[Member] Berhasil mendaftar kursus: " + kursusRegular2.getNama());

            pesertaMember.tambahKursus(
                    kursusInsidental2,
                    LocalDate.of(2025, 4, 3),
                    LocalDate.of(2025, 4, 5),
                    "QRIS"
            );
            System.out.println("[Member] Berhasil mendaftar kursus: " + kursusInsidental2.getNama());

            // Uji coba melampaui batas maksimal 3 kursus
            pesertaMember.tambahKursus(
                    kursusInsidental1,
                    LocalDate.of(2025, 4, 4),
                    LocalDate.of(2025, 4, 6),
                    "Transfer Bank"
            );

        } catch (IllegalArgumentException e) {
            System.out.println("[Member] Gagal mendaftar: " + e.getMessage());
        }

        // ============================================================
        // 6. Menampilkan informasi peserta
        // ============================================================

        System.out.println("\n========================================");
        System.out.println("       INFORMASI PESERTA                ");
        System.out.println("========================================");

        System.out.println("\n--- Peserta Umum ---");
        pesertaUmum.tampilkanInfo();

        System.out.println("\n--- Peserta Member ---");
        pesertaMember.tampilkanInfo();

        // ============================================================
        // 7. Menghitung total pembayaran
        // ============================================================

        System.out.println("\n========================================");
        System.out.println("       TOTAL PEMBAYARAN                 ");
        System.out.println("========================================");

        ArrayList<LPK> kursusUmum = new ArrayList<>(pesertaUmum.daftarKursus);
        double totalUmum = pesertaUmum.hitungTotalPembayaran(kursusUmum);
        System.out.printf("[Peserta Umum] %s - Total Pembayaran : Rp %.2f%n",
                pesertaUmum.getNama(), totalUmum);

        ArrayList<LPK> kursusMember = new ArrayList<>(pesertaMember.daftarKursus);
        double totalMember = pesertaMember.hitungTotalPembayaran(kursusMember);
        System.out.printf("[Peserta Member] %s - Total Pembayaran (diskon %d%%) : Rp %.2f%n",
                pesertaMember.getNama(), Member.getDiskon(), totalMember);

        // ============================================================
        // 8. Uji coba exception: durasi kursus Regular tidak valid
        // ============================================================

        System.out.println("\n========================================");
        System.out.println("       UJI EXCEPTION                    ");
        System.out.println("========================================");

        try {
            Regular kursusInvalid = new Regular(
                    "REG-ERR", "Kursus Tidak Valid", "Instruktur X",
                    10, 1000000, 11, 5, "Advanced", "Online"
            );
        } catch (IllegalArgumentException e) {
            System.out.println("Exception tertangkap (Regular durasi tidak valid): " + e.getMessage());
        }

        System.out.println("\nSelesai.");
    }
}