#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int nilai[10];
    int jumlah;
    int total = 0;
    int lulus = 0;
    int tidakLulus = 0;

    do
    {
        cout << "Masukkan jumlah mahasiswa (maks 10): ";
        cin >> jumlah;

        if (jumlah < 1 || jumlah > 10)
        {
            cout << "Jumlah mahasiswa harus 1 sampai 10!" << endl;
        }
    } while (jumlah < 1 || jumlah > 10);

    for (int i = 0; i < jumlah; i++)
    {
        cout << "Masukkan nilai ke-" << i + 1 << " : ";
        cin >> nilai[i];
    }

    int tertinggi = nilai[0];
    int terendah = nilai[0];

    for (int i = 0; i < jumlah; i++)
    {
        total += nilai[i];

        if (nilai[i] > tertinggi)
        {
            tertinggi = nilai[i];
        }

        if (nilai[i] < terendah)
        {
            terendah = nilai[i];
        }

        if (nilai[i] >= 60)
        {
            lulus++;
        }
        else
        {
            tidakLulus++;
        }
    }

    double rataRata = static_cast<double>(total) / jumlah;

    cout << "\n==============================" << endl;
    cout << "       HASIL PENGOLAHAN" << endl;
    cout << "==============================" << endl;

    cout << "Nilai : ";
    for (int i = 0; i < jumlah; i++)
    {
        cout << nilai[i] << " ";
    }
    cout << endl;

    cout << fixed << setprecision(2);

    cout << "\nTotal Nilai        : " << total << endl;
    cout << "Rata-rata          : " << rataRata << endl;
    cout << "Nilai Tertinggi    : " << tertinggi << endl;
    cout << "Nilai Terendah     : " << terendah << endl;
    cout << "Jumlah Lulus       : " << lulus << endl;
    cout << "Jumlah Tidak Lulus : " << tidakLulus << endl;

    return 0;
}
