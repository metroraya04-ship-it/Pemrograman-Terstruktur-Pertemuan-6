#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

int main() {
    cout << fixed << setprecision(2);

    int jumlah_mahasiswa = 0;

    cout << "Masukkan jumlah mahasiswa: ";
    cin >> jumlah_mahasiswa;

    if (jumlah_mahasiswa <= 0) {
        cout << "Jumlah mahasiswa harus lebih dari 0.\n";
        return 1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    double total_nilai = 0.0;

    int jumlah_A = 0;
    int jumlah_B = 0;
    int jumlah_C = 0;
    int jumlah_D = 0;
    int jumlah_E = 0;

    double nilai_tertinggi = -1.0;
    string nama_tertinggi = "";

    int lulus = 0;
    int belum_lulus = 0;

    cout << "\n";
    cout << "DAFTAR NILAI MAHASISWA\n";

    cout << left << setw(20) << "Nama"
         << right << setw(7) << "Nilai"
         << setw(3) << " "
         << setw(3) << "HM"
         << "  Status\n";

    cout << string(45, '-') << '\n';

    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama;
        double nilai = 0.0;
        string huruf_mutu;
        string status;

        cout << "\nMahasiswa ke-" << i << '\n';

        cout << "Nama  : ";
        getline(cin, nama);

        cout << "Nilai : ";

        if (!(cin >> nilai)) {
            cout << "Input nilai tidak valid.\n";
            return 1;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (nilai < 0.0 || nilai > 100.0) {
            cout << "Nilai harus berada antara 0 dan 100.\n";
            return 1;
        }

        if (nilai >= 85.0) {
            huruf_mutu = "A";
        } else if (nilai >= 80.0) {
            huruf_mutu = "B+";
        } else if (nilai >= 70.0) {
            huruf_mutu = "B";
        } else if (nilai >= 60.0) {
            huruf_mutu = "C";
        } else if (nilai >= 50.0) {
            huruf_mutu = "D";
        } else {
            huruf_mutu = "E";
        }

        if (nilai >= 60.0) {
            status = "Lulus";
        } else {
            status = "Belum lulus";
        }

        cout << left << setw(20) << nama
             << right << setw(7) << nilai
             << setw(3) << " "
             << setw(3) << huruf_mutu
             << "  " << status << '\n';

        total_nilai += nilai;

        switch (huruf_mutu[0]) {
            case 'A':
                jumlah_A++;
                break;

            case 'B':
                jumlah_B++;
                break;

            case 'C':
                jumlah_C++;
                break;

            case 'D':
                jumlah_D++;
                break;

            case 'E':
                jumlah_E++;
                break;

            default:
                break;
        }

        if (nilai >= 60.0) {
            lulus++;
        } else {
            belum_lulus++;
        }

        if (nilai > nilai_tertinggi) {
            nilai_tertinggi = nilai;
            nama_tertinggi = nama;
        }
    }

    double rata_rata = total_nilai / jumlah_mahasiswa;

    cout << "\n";
    cout << "Laporan Kelas\n";

    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << '\n';
    cout << "Lulus            : " << lulus << '\n';
    cout << "Belum lulus      : " << belum_lulus << '\n';

    cout << "Rata-rata kelas : " << rata_rata << '\n';

    cout << "Tertinggi        : "
         << nama_tertinggi
         << " (" << nilai_tertinggi << ")\n";

    cout << "\nSebaran huruf mutu:\n";

    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int jumlah_huruf = 0;

        if (huruf == 'A') {
            jumlah_huruf = jumlah_A;
        } else if (huruf == 'B') {
            jumlah_huruf = jumlah_B;
        } else if (huruf == 'C') {
            jumlah_huruf = jumlah_C;
        } else if (huruf == 'D') {
            jumlah_huruf = jumlah_D;
        } else if (huruf == 'E') {
            jumlah_huruf = jumlah_E;
        }

        cout << huruf << " | ";

        for (int j = 0; j < jumlah_huruf; j++) {
            cout << '#';
        }

        cout << ' ' << jumlah_huruf << '\n';
    }

    return 0;
}