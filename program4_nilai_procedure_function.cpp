#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int tugas[100];
int uts[100];
int uas[100];
double nilaiAkhir[100];
char grade[100];
string status[100];

double hitungNilaiAkhir(int t, int ut, int ua)
{
    return (t * 0.30) + (ut * 0.30) + (ua * 0.40);
}

char tentukanGrade(double na)
{
    if (na >= 80)
    {
        return 'A';
    }
    else if (na >= 70)
    {
        return 'B';
    }
    else if (na >= 60)
    {
        return 'C';
    }
    else if (na >= 50)
    {
        return 'D';
    }
    else
    {
        return 'E';
    }
}

string cekLulus(char g)
{
    if (g == 'A' || g == 'B' || g == 'C')
    {
        return "Lulus";
    }
    else
    {
        return "Tidak Lulus";
    }
}

void tampilHasil(int jumlahMhs)
{
    int jumlahLulus = 0;
    int jumlahTidakLulus = 0;

    cout << "\n=====================================================" << endl;
    cout << left << setw(4) << "No"
         << setw(7) << "Tugas"
         << setw(5) << "UTS"
         << setw(5) << "UAS"
         << setw(13) << "Nilai Akhir"
         << setw(7) << "Grade"
         << "Status" << endl;
    cout << "=====================================================" << endl;

    cout << fixed << setprecision(2);

    for (int i = 0; i < jumlahMhs; i++)
    {
        cout << left << setw(4) << i + 1
             << setw(7) << tugas[i]
             << setw(5) << uts[i]
             << setw(5) << uas[i]
             << setw(13) << nilaiAkhir[i]
             << setw(7) << grade[i]
             << status[i] << endl;

        if (status[i] == "Lulus")
        {
            jumlahLulus++;
        }
        else
        {
            jumlahTidakLulus++;
        }
    }

    cout << "=====================================================" << endl;
    cout << "\nJumlah Lulus       : " << jumlahLulus << endl;
    cout << "Jumlah Tidak Lulus : " << jumlahTidakLulus << endl;
}

int main()
{
    int jumlahMhs;

    do
    {
        cout << "Masukkan jumlah mahasiswa (maks 100): ";
        cin >> jumlahMhs;

        if (jumlahMhs < 1 || jumlahMhs > 100)
        {
            cout << "Jumlah mahasiswa harus 1 sampai 100!" << endl;
        }
    } while (jumlahMhs < 1 || jumlahMhs > 100);

    for (int i = 0; i < jumlahMhs; i++)
    {
        cout << "\nMahasiswa ke-" << i + 1 << endl;
        cout << "Nilai Tugas : ";
        cin >> tugas[i];
        cout << "Nilai UTS   : ";
        cin >> uts[i];
        cout << "Nilai UAS   : ";
        cin >> uas[i];

        nilaiAkhir[i] = hitungNilaiAkhir(tugas[i], uts[i], uas[i]);
        grade[i] = tentukanGrade(nilaiAkhir[i]);
        status[i] = cekLulus(grade[i]);
    }

    tampilHasil(jumlahMhs);

    return 0;
}
