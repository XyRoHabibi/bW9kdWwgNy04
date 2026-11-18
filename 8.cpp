#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double hitungNilaiAkhir(double tugas, double uts, double uas)
{
    return (tugas * 0.3) + (uts * 0.3) + (uas * 0.4);
}

char tentukanGrade(double nilaiAkhir)
{
    if (nilaiAkhir >= 80)
        return 'A';
    else if (nilaiAkhir >= 70)
        return 'B';
    else if (nilaiAkhir >= 60)
        return 'C';
    else if (nilaiAkhir >= 50)
        return 'D';
    else
        return 'E';
}

bool cekLulus(char grade)
{
    if (grade == 'A' || grade == 'B' || grade == 'C')
        return true;
    else
        return false;
}

void tampilHasil(string nama, double nilaiAkhir, char grade, bool lulus)
{
    cout << endl;
    cout << "================================" << endl;
    cout << "Nama        : " << nama << endl;
    cout << fixed << setprecision(2);
    cout << "Nilai Akhir : " << nilaiAkhir << endl;
    cout << "Grade       : " << grade << endl;
    if (lulus)
        cout << "Status      : LULUS" << endl;
    else
        cout << "Status      : TIDAK LULUS" << endl;
    cout << "================================" << endl;
}

int main()
{
    int n, jumlahLulus = 0, jumlahTidak = 0;
    string nama;
    double tugas, uts, uas;

    cout << "Masukkan jumlah mahasiswa : ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << endl;
        cout << "Mahasiswa ke-" << i << endl;
        cout << "Nama        : ";
        cin.ignore();
        getline(cin, nama);
        cout << "Nilai Tugas : ";
        cin >> tugas;
        cout << "Nilai UTS   : ";
        cin >> uts;
        cout << "Nilai UAS   : ";
        cin >> uas;

        double nilaiAkhir = hitungNilaiAkhir(tugas, uts, uas);
        char grade = tentukanGrade(nilaiAkhir);
        bool lulus = cekLulus(grade);

        tampilHasil(nama, nilaiAkhir, grade, lulus);

        if (lulus)
            jumlahLulus++;
        else
            jumlahTidak++;
    }

    cout << endl;
    cout << "Jumlah Lulus       : " << jumlahLulus << endl;
    cout << "Jumlah Tidak Lulus : " << jumlahTidak << endl;

    return 0;
}



	///////// studi kasus 2
	
	
	#include <iostream>
#include <string>
using namespace std;

double tambah(double a, double b)
{
    return a + b;
}

double kurang(double a, double b)
{
    return a - b;
}

double kali(double a, double b)
{
    return a * b;
}

double bagi(double a, double b)
{
    return a / b;
}

int faktorial(int n)
{
    if (n <= 1)
        return 1;
    return n * faktorial(n - 1);
}

string rapikan(double x)
{
    string s = to_string(x);
    while (s.back() == '0')
        s.pop_back();
    if (s.back() == '.')
        s.pop_back();
    return s;
}

string hitung(int pilihan, string a, string b)
{
    switch (pilihan)
    {
    case 1:
        return a + " + " + b + " = " + rapikan(tambah(stod(a), stod(b)));
    case 2:
        return a + " - " + b + " = " + rapikan(kurang(stod(a), stod(b)));
    case 3:
        return a + " x " + b + " = " + rapikan(kali(stod(a), stod(b)));
    case 4:
        if (stod(b) == 0)
            return "Pembagian dengan 0 tidak bisa diproses";
        return a + " / " + b + " = " + rapikan(bagi(stod(a), stod(b)));
    case 5:
        if (stoi(a) < 0)
            return "Faktorial hanya untuk bilangan tidak negatif";
        if (stoi(a) > 12)
            return "Angka terlalu besar (maksimal 12)";
        return a + "! = " + to_string(faktorial(stoi(a)));
    }
    return "";
}

int main()
{
    int pilihan;
    string a, b;

    do
    {
        cout << "================================" << endl;
        cout << "          KALKULATOR" << endl;
        cout << "================================" << endl;
        cout << "1. Penjumlahan" << endl;
        cout << "2. Pengurangan" << endl;
        cout << "3. Perkalian" << endl;
        cout << "4. Pembagian" << endl;
        cout << "5. Faktorial" << endl;
        cout << "6. Keluar" << endl;
        cout << "================================" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        if (pilihan >= 1 && pilihan <= 4)
        {
            cout << "Masukkan angka pertama : ";
            cin >> a;
            cout << "Masukkan angka kedua   : ";
            cin >> b;
            cout << "Hasil : " << hitung(pilihan, a, b) << endl;
        }
        else if (pilihan == 5)
        {
            cout << "Masukkan angka : ";
            cin >> a;
            cout << "Hasil : " << hitung(pilihan, a, "") << endl;
        }
        else if (pilihan == 6)
        {
            cout << "Program selesai" << endl;
        }
        else
        {
            cout << "Pilihan tidak tersedia!" << endl;
        }

        cout << endl;
    } while (pilihan != 6);

    return 0;
}


	///////////////// studi kasus 3
	
	
	#include <iostream>
#include <iomanip>
using namespace std;

int hitungTotal(int data[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
        total += data[i];
    return total;
}

int hitungMinimum(int data[], int n)
{
    int min = data[0];
    for (int i = 1; i < n; i++)
    {
        if (data[i] < min)
            min = data[i];
    }
    return min;
}

int hitungMaksimum(int data[], int n)
{
    int max = data[0];
    for (int i = 1; i < n; i++)
    {
        if (data[i] > max)
            max = data[i];
    }
    return max;
}

double hitungRataRata(int data[], int n)
{
    return (double)hitungTotal(data, n) / n;
}

bool cekGenap(int angka)
{
    return angka % 2 == 0;
}

int hitungGenap(int data[], int n)
{
    int jumlah = 0;
    for (int i = 0; i < n; i++)
    {
        if (cekGenap(data[i]))
            jumlah++;
    }
    return jumlah;
}

int hitungGanjil(int data[], int n)
{
    int jumlah = 0;
    for (int i = 0; i < n; i++)
    {
        if (!cekGenap(data[i]))
            jumlah++;
    }
    return jumlah;
}

void tampilRekap(int n, int total, int min, int max, double rata, int genap, int ganjil)
{
    cout << endl;
    cout << "================================" << endl;
    cout << "             REKAP" << endl;
    cout << "================================" << endl;
    cout << "Jumlah Data   : " << n << endl;
    cout << "Total         : " << total << endl;
    cout << "Minimum       : " << min << endl;
    cout << "Maksimum      : " << max << endl;
    cout << fixed << setprecision(2);
    cout << "Rata-rata     : " << rata << endl;
    cout << "Jumlah Genap  : " << genap << endl;
    cout << "Jumlah Ganjil : " << ganjil << endl;
    cout << "================================" << endl;
}

int main()
{
    int n;
    int data[100];

    cout << "Masukkan jumlah data : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Bilangan ke-" << i + 1 << " : ";
        cin >> data[i];
    }

    tampilRekap(n,
                hitungTotal(data, n),
                hitungMinimum(data, n),
                hitungMaksimum(data, n),
                hitungRataRata(data, n),
                hitungGenap(data, n),
                hitungGanjil(data, n));

    return 0;
}


	/////////////// studi kasus 4
	
	
	#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool kodeValid(int kode)
{
    return kode >= 1 && kode <= 4;
}

string namaBarang(int kode)
{
    switch (kode)
    {
    case 1: return "Buku";
    case 2: return "Pensil";
    case 3: return "Pulpen";
    case 4: return "Penghapus";
    }
    return "";
}

double hargaBeli(int kode)
{
    switch (kode)
    {
    case 1: return 8000;
    case 2: return 1500;
    case 3: return 2500;
    case 4: return 1000;
    }
    return 0;
}

double hargaJual(int kode)
{
    switch (kode)
    {
    case 1: return 10000;
    case 2: return 2000;
    case 3: return 3500;
    case 4: return 1500;
    }
    return 0;
}

double hitungSubtotal(int kode, int jumlah)
{
    return hargaJual(kode) * jumlah;
}

double hitungModal(int kode, int jumlah)
{
    return hargaBeli(kode) * jumlah;
}

double hitungKeuntungan(int kode, int jumlah)
{
    return hitungSubtotal(kode, jumlah) - hitungModal(kode, jumlah);
}

void tampilTransaksi(int kode, int jumlah)
{
    cout << fixed << setprecision(0);
    cout << "--------------------------------" << endl;
    cout << "Barang      : " << namaBarang(kode) << endl;
    cout << "Jumlah      : " << jumlah << endl;
    cout << "Subtotal    : Rp" << hitungSubtotal(kode, jumlah) << endl;
    cout << "Modal       : Rp" << hitungModal(kode, jumlah) << endl;
    cout << "Keuntungan  : Rp" << hitungKeuntungan(kode, jumlah) << endl;
    cout << "--------------------------------" << endl;
}

int main()
{
    int kode, jumlah;
    int jumlahTransaksi = 0, totalBarang = 0;
    double totalOmzet = 0, totalModal = 0, totalUntung = 0;

    do
    {
        cout << "================================" << endl;
        cout << "          MENU BARANG" << endl;
        cout << "================================" << endl;
        cout << "1. Buku" << endl;
        cout << "2. Pensil" << endl;
        cout << "3. Pulpen" << endl;
        cout << "4. Penghapus" << endl;
        cout << "5. Selesai" << endl;
        cout << "================================" << endl;
        cout << "Pilihan : ";
        cin >> kode;

        if (kodeValid(kode))
        {
            cout << "Jumlah  : ";
            cin >> jumlah;

            tampilTransaksi(kode, jumlah);

            jumlahTransaksi++;
            totalBarang += jumlah;
            totalOmzet += hitungSubtotal(kode, jumlah);
            totalModal += hitungModal(kode, jumlah);
            totalUntung += hitungKeuntungan(kode, jumlah);
        }
        else if (kode != 5)
        {
            cout << "Pilihan tidak tersedia!" << endl;
        }

        cout << endl;
    } while (kode != 5);

    cout << "================================" << endl;
    cout << "        REKAP TRANSAKSI" << endl;
    cout << "================================" << endl;
    cout << "Jumlah Transaksi : " << jumlahTransaksi << endl;
    cout << "Total Barang     : " << totalBarang << endl;
    cout << fixed << setprecision(0);
    cout << "Total Omzet      : Rp" << totalOmzet << endl;
    cout << "Total Modal      : Rp" << totalModal << endl;
    cout << "Total Keuntungan : Rp" << totalUntung << endl;
    cout << "================================" << endl;

    return 0;
}

	


	
	
	


