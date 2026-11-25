#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int kodeBarang[10];
int jumlahBarang[10];
double arrHargaBeli[10];
double arrHargaJual[10];
double subtotal[10];
double modal[10];
double keuntungan[10];

string namaBarang(int kode)
{
    switch (kode)
    {
    case 1:
        return "Buku";
    case 2:
        return "Pensil";
    case 3:
        return "Pulpen";
    case 4:
        return "Penghapus";
    default:
        return "Tidak Ada";
    }
}

double hargaBeli(int kode)
{
    switch (kode)
    {
    case 1:
        return 7000;
    case 2:
        return 3000;
    case 3:
        return 5000;
    case 4:
        return 2500;
    default:
        return 0;
    }
}

double hargaJual(int kode)
{
    switch (kode)
    {
    case 1:
        return 10000;
    case 2:
        return 5000;
    case 3:
        return 7500;
    case 4:
        return 4000;
    default:
        return 0;
    }
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

int main()
{
    int jumlahTransaksi;

    cout << "=============================================================" << endl;
    cout << "                     DAFTAR BARANG" << endl;
    cout << "=============================================================" << endl;
    cout << "1. Buku       Harga Beli Rp7.000   Harga Jual Rp10.000" << endl;
    cout << "2. Pensil     Harga Beli Rp3.000   Harga Jual Rp5.000" << endl;
    cout << "3. Pulpen     Harga Beli Rp5.000   Harga Jual Rp7.500" << endl;
    cout << "4. Penghapus  Harga Beli Rp2.500   Harga Jual Rp4.000" << endl;
    cout << "=============================================================" << endl;

    do
    {
        cout << "Masukkan jumlah transaksi (maks 10): ";
        cin >> jumlahTransaksi;

        if (jumlahTransaksi < 1 || jumlahTransaksi > 10)
        {
            cout << "Jumlah transaksi harus 1 sampai 10!" << endl;
        }
    } while (jumlahTransaksi < 1 || jumlahTransaksi > 10);

    for (int i = 0; i < jumlahTransaksi; i++)
    {
        cout << "\nTransaksi ke-" << i + 1 << endl;

        do
        {
            cout << "Kode barang (1-4) : ";
            cin >> kodeBarang[i];

            if (kodeBarang[i] < 1 || kodeBarang[i] > 4)
            {
                cout << "Kode barang tidak tersedia!" << endl;
            }
        } while (kodeBarang[i] < 1 || kodeBarang[i] > 4);

        do
        {
            cout << "Jumlah barang     : ";
            cin >> jumlahBarang[i];

            if (jumlahBarang[i] < 1)
            {
                cout << "Jumlah barang minimal 1!" << endl;
            }
        } while (jumlahBarang[i] < 1);

        arrHargaBeli[i] = hargaBeli(kodeBarang[i]);
        arrHargaJual[i] = hargaJual(kodeBarang[i]);
        subtotal[i] = hitungSubtotal(kodeBarang[i], jumlahBarang[i]);
        modal[i] = hitungModal(kodeBarang[i], jumlahBarang[i]);
        keuntungan[i] = hitungKeuntungan(kodeBarang[i], jumlahBarang[i]);
    }

    int totalBarang = 0;
    double totalOmzet = 0;
    double totalModal = 0;
    double totalKeuntungan = 0;
    double penjualanTerbesar = subtotal[0];
    int indeksTerbesar = 0;

    for (int i = 0; i < jumlahTransaksi; i++)
    {
        totalBarang += jumlahBarang[i];
        totalOmzet += subtotal[i];
        totalModal += modal[i];
        totalKeuntungan += keuntungan[i];

        if (subtotal[i] > penjualanTerbesar)
        {
            penjualanTerbesar = subtotal[i];
            indeksTerbesar = i;
        }
    }

    cout << fixed << setprecision(0);

    cout << "\n=========================================================================" << endl;
    cout << "                          DATA TRANSAKSI" << endl;
    cout << "=========================================================================" << endl;
    cout << left << setw(4) << "No"
         << setw(12) << "Barang"
         << setw(7) << "Jml"
         << setw(11) << "H.Beli"
         << setw(11) << "H.Jual"
         << setw(11) << "Subtotal"
         << setw(10) << "Modal"
         << "Untung" << endl;
    cout << "=========================================================================" << endl;

    for (int i = 0; i < jumlahTransaksi; i++)
    {
        cout << left << setw(4) << i + 1
             << setw(12) << namaBarang(kodeBarang[i])
             << setw(7) << jumlahBarang[i]
             << setw(11) << arrHargaBeli[i]
             << setw(11) << arrHargaJual[i]
             << setw(11) << subtotal[i]
             << setw(10) << modal[i]
             << keuntungan[i] << endl;
    }

    cout << "=========================================================================" << endl;

    cout << "\n================== REKAP AKHIR ==================" << endl;
    cout << "Jumlah Transaksi      : " << jumlahTransaksi << endl;
    cout << "Total Barang Terjual  : " << totalBarang << endl;
    cout << "Total Omzet           : Rp" << totalOmzet << endl;
    cout << "Total Modal           : Rp" << totalModal << endl;
    cout << "Total Keuntungan      : Rp" << totalKeuntungan << endl;
    cout << "Penjualan Terbesar    : Rp" << penjualanTerbesar
         << " (Transaksi ke-" << indeksTerbesar + 1 << ", "
         << namaBarang(kodeBarang[indeksTerbesar]) << ")" << endl;
    cout << "=================================================" << endl;

    return 0;
}
