#include <iostream>
using namespace std;

int angka[100];
int jumlah;

void tampilSemua()
{
    cout << "Semua Data : ";
    for (int i = 0; i < jumlah; i++)
    {
        cout << angka[i] << " ";
    }
    cout << endl;
}

void tampilGenap()
{
    cout << "Bilangan Genap : ";
    for (int i = 0; i < jumlah; i++)
    {
        if (angka[i] % 2 == 0)
        {
            cout << angka[i] << " ";
        }
    }
    cout << endl;
}

void tampilGanjil()
{
    cout << "Bilangan Ganjil : ";
    for (int i = 0; i < jumlah; i++)
    {
        if (angka[i] % 2 != 0)
        {
            cout << angka[i] << " ";
        }
    }
    cout << endl;
}

int hitungTotal()
{
    int total = 0;

    for (int i = 0; i < jumlah; i++)
    {
        total += angka[i];
    }

    return total;
}

int main()
{
    int pilihan;

    do
    {
        cout << "Masukkan jumlah data (maks 100): ";
        cin >> jumlah;

        if (jumlah < 1 || jumlah > 100)
        {
            cout << "Jumlah data harus 1 sampai 100!" << endl;
        }
    } while (jumlah < 1 || jumlah > 100);

    for (int i = 0; i < jumlah; i++)
    {
        cout << "Masukkan data ke-" << i + 1 << " : ";
        cin >> angka[i];
    }

    do
    {
        cout << "\n==============================" << endl;
        cout << "     MENU PENGOLAHAN DATA" << endl;
        cout << "==============================" << endl;
        cout << "1. Tampilkan Semua Data" << endl;
        cout << "2. Tampilkan Bilangan Genap" << endl;
        cout << "3. Tampilkan Bilangan Ganjil" << endl;
        cout << "4. Hitung Total Data" << endl;
        cout << "5. Keluar" << endl;
        cout << "==============================" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan)
        {
        case 1:
            tampilSemua();
            break;
        case 2:
            tampilGenap();
            break;
        case 3:
            tampilGanjil();
            break;
        case 4:
            cout << "Total Data : " << hitungTotal() << endl;
            break;
        case 5:
            cout << "Program selesai. Terima kasih." << endl;
            break;
        default:
            cout << "Menu tidak tersedia!" << endl;
        }
    } while (pilihan != 5);

    return 0;
}
