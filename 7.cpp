#include <iostream>
#include <string>
using namespace std;

string nama, stambuk, kelas, prodi;
int umur;

void inputBiodata()
{
    cout << "Nama          : ";
    getline(cin, nama);
    cout << "Stambuk       : ";
    getline(cin, stambuk);
    cout << "Kelas         : ";
    getline(cin, kelas);
    cout << "Program Studi : ";
    getline(cin, prodi);
    cout << "Umur          : ";
    cin >> umur;
    cin.ignore();
}

void tampilBiodata(string n, string s, string k, string p, int u)
{
    cout << "==============================" << endl;
    cout << "       BIODATA MAHASISWA" << endl;
    cout << "==============================" << endl;
    cout << "Nama          : " << n << endl;
    cout << "Stambuk       : " << s << endl;
    cout << "Kelas         : " << k << endl;
    cout << "Program Studi : " << p << endl;
    cout << "Umur          : " << u << " Tahun" << endl;
    cout << "==============================" << endl;
}

void menu()
{
    cout << "==============================" << endl;
    cout << "         MENU BIODATA" << endl;
    cout << "==============================" << endl;
    cout << "1. Input Biodata" << endl;
    cout << "2. Tampilkan Biodata" << endl;
    cout << "3. Keluar" << endl;
    cout << "==============================" << endl;
    cout << "Pilihan : ";
}

int main()
{
    int pilih;

    do
    {
        menu();
        cin >> pilih;
        cin.ignore();

        if (pilih == 1)
        {
            inputBiodata();
        }
        else if (pilih == 2)
        {
            tampilBiodata(nama, stambuk, kelas, prodi, umur);
        }
        else if (pilih == 3)
        {
            cout << "Program selesai" << endl;
        }
        else
        {
            cout << "Pilihan tidak tersedia!" << endl;
        }

        cout << endl;
    } while (pilih != 3);

    return 0;
}



	////////// studi kasus 2
	
	#include <iostream>
#include <string>
using namespace std;

string kata;
string kalimat = "";
int jumlah = 0;

void inputKata()
{
    cout << "Masukkan kata : ";
    cin >> kata;
}

void tambahKata()
{
    if (jumlah > 0)
    {
        kalimat = kalimat + " ";
    }
    kalimat = kalimat + kata;
    jumlah++;
}

int main()
{
    int pilih;

    do
    {
        cout << "1 = Tambah kata" << endl;
        cout << "0 = Selesai" << endl;
        cout << "Pilihan : ";
        cin >> pilih;

        if (pilih == 1)
        {
            inputKata();
            tambahKata();
        }
        else if (pilih != 0)
        {
            cout << "Pilihan tidak tersedia!" << endl;
        }

        cout << endl;
    } while (pilih != 0);

    string info = "Jumlah kata yang dimasukkan: " + to_string(jumlah);

    cout << "Kalimat     : " << kalimat << endl;
    cout << "Jumlah Kata : " << jumlah << endl;
    cout << info << endl;

    cout << endl << "Pola:" << endl;
    for (int i = 1; i <= jumlah; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}


 	/////////////// studi kasus 3
 	
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

string nama, status;
int tugas, uts, uas;
double akhir;
char grade;

void inputNilai()
{
    cout << "Nilai Tugas : ";
    cin >> tugas;
    cout << "Nilai UTS   : ";
    cin >> uts;
    cout << "Nilai UAS   : ";
    cin >> uas;
}

void hitungNilai()
{
    akhir = (tugas * 0.3) + (uts * 0.3) + (uas * 0.4);

    if (akhir >= 80)
        grade = 'A';
    else if (akhir >= 70)
        grade = 'B';
    else if (akhir >= 60)
        grade = 'C';
    else if (akhir >= 50)
        grade = 'D';
    else
        grade = 'E';

    if (grade == 'A' || grade == 'B' || grade == 'C')
        status = "LULUS";
    else
        status = "TIDAK LULUS";
}

void tampilHasil(int ke)
{
    cout << endl;
    cout << "================================" << endl;
    cout << "DATA MAHASISWA KE-" << ke << endl;
    cout << "================================" << endl;
    cout << "Nama        : " << nama << endl;
    cout << "Nilai Tugas : " << tugas << endl;
    cout << "Nilai UTS   : " << uts << endl;
    cout << "Nilai UAS   : " << uas << endl;
    cout << endl;
    cout << "HASIL PENILAIAN" << endl;
    cout << fixed << setprecision(2);
    cout << "Nilai Akhir : " << akhir << endl;
    cout << "Grade       : " << grade << endl;
    cout << "Status      : " << status << endl;
    cout << "================================" << endl;
}

int main()
{
    int n, lulus = 0, tidak = 0;

    cout << "Masukkan jumlah mahasiswa : ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << endl;
        cout << "Mahasiswa ke-" << i << endl;
        cout << "Nama        : ";
        cin.ignore();
        getline(cin, nama);

        inputNilai();
        hitungNilai();
        tampilHasil(i);

        if (status == "LULUS")
            lulus++;
        else
            tidak++;
    }

    cout << endl;
    cout << "================================" << endl;
    cout << "        REKAP KELULUSAN" << endl;
    cout << "================================" << endl;
    cout << "Jumlah Mahasiswa    : " << n << endl;
    cout << "Jumlah Lulus        : " << lulus << endl;
    cout << "Jumlah Tidak Lulus  : " << tidak << endl;
    cout << "================================" << endl;

    return 0;
}
