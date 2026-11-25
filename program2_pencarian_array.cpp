#include <iostream>
using namespace std;

int hitungKemunculan(int data[], int jumlah, int cari)
{
    int muncul = 0;

    for (int i = 0; i < jumlah; i++)
    {
        if (data[i] == cari)
        {
            muncul++;
        }
    }

    return muncul;
}

int main()
{
    int data[15];
    int jumlah;
    int cari;

    do
    {
        cout << "Masukkan jumlah data (maks 15): ";
        cin >> jumlah;

        if (jumlah < 1 || jumlah > 15)
        {
            cout << "Jumlah data harus 1 sampai 15!" << endl;
        }
    } while (jumlah < 1 || jumlah > 15);

    for (int i = 0; i < jumlah; i++)
    {
        cout << "Masukkan data ke-" << i + 1 << " : ";
        cin >> data[i];
    }

    cout << "\nData : ";
    for (int i = 0; i < jumlah; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;

    cout << "\nCari nilai : ";
    cin >> cari;

    int muncul = hitungKemunculan(data, jumlah, cari);

    if (muncul > 0)
    {
        cout << "\nData ditemukan." << endl;
        cout << "Nilai dicari      : " << cari << endl;
        cout << "Indeks            : ";

        for (int i = 0; i < jumlah; i++)
        {
            if (data[i] == cari)
            {
                cout << i << " ";
            }
        }
        cout << endl;

        cout << "Jumlah kemunculan : " << muncul << endl;
    }
    else
    {
        cout << "\nData tidak ditemukan" << endl;
    }

    return 0;
}
