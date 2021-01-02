#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
using namespace std;

struct titik
{
    char kode[4];
    char nama[15];
    int harga;
    int satuan;
    struct titik *berikut;
};
struct barang
{
    char kode[4];
    char nama[15];
    int harga;
    int satuan;
};
struct titik *awal = NULL, *akhir = NULL;
void tambahlist(struct barang x);
void isilist();
void tampillist();
void hapuslist();

int main()
{
    system("cls");
    int pilih;
    do
    {
        system("cls");
        cout << "Menu\n";
        cout << "1. Input Data \n";
        cout << "2. Cetak Data\n";
        cout << "3. Hapus Data\n";
        cout << "4. Exit\n";
        cout << "Tentukan Pilihan : ";
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            isilist();
            break;
        case 2:
            tampillist();
            break;
        case 3:
            hapuslist();
            break;
        case 4:
            cout << "Terimakasih Telah menggunakan Program ini";
            break;
        default:
            cout << "Inputan salah";
            break;
        }
        getch();
    } while (pilih != 4);
    getch();
}

void tambahlist(struct barang x)
{
    struct titik *baru;
    baru = new titik;
    strcpy(baru->kode, x.kode);
    strcpy(baru->nama, x.nama);
    baru->harga = x.harga;
    baru->satuan = x.satuan;
    if (awal == NULL)
    {
        awal = baru;
    }
    else
    {
        akhir->berikut = baru;
    }

    akhir = baru;
    akhir->berikut = NULL;
}

void isilist()
{
    char jawab;
    struct barang data;
    do
    {
        system("cls");
        cout << "Masukkan Kode Barang : ";
        cin >> data.kode;
        cout << "Masukkan Nama Barang : ";
        cin >> data.nama;
        cout << "Masukkan Harga : ";
        cin >> data.harga;
        cout << "Masukkan Jumlah Barang : ";
        cin >> data.satuan;
        tambahlist(data);
        cout << "\nTambah Data (Y/T) : ";
        cin >> jawab;
    } while ((jawab) != 't');
    cout << "\nKembali ke menu?  (Y/T) : ";
    cin >> jawab;
}

void tampillist()
{
    struct titik *baca;
    char jawab;
    int i;
    int a[100];
    int maks, harga, cari, ada, barang, kode;
    int b, ketemu;
    int total = 0;
    int bayar, kembalian;
    baca = awal;
    i = 1;
    while (baca != NULL)
    {
        cout << "\n\nData yang dibaca ke-" << i << endl;
        cout << "\nKode Barang : " << baca->kode;
        cout << "\nNama Barang : " << baca->nama;
        cout << "\nHarga : " << baca->harga;
        cout << "\nJumlah Barang : " << baca->satuan;
        i++;
        cout << "\n===================================\n";
        baca = baca->berikut;
    }
    total = total + harga;
    cout << "\nTotal Pembelian = Rp. " << total << endl;
    cout << "Total Bayar     = Rp. ";
    cin >> bayar;
    kembalian = bayar - total;
    cout << "\nUang Kembalian   = " << kembalian << endl;

    cout << "======================================\n";
    cout << endl;
    cout << "\nInput bilangan yang dicari : ";
    cin >> cari;

    ketemu = 0;
    for (i = 0; i <= maks; i++)
    {
        if (a[i] == cari)
        {
            cout << "\nData yang dicari = " << a[i];
            cout << "\nData ditemukan pada indeks ke-" << i;
            ketemu = 1;
        }
    }

    if (ketemu == 0)
    {
        cout << "Data tidak ditemukan";
    }
    cout << "\nKembali ke menu?  (Y/T) : ";
    cin >> jawab;
}

void hapuslist()
{
    struct titik *hapus;
    char jawab;
    hapus = awal;
    while (hapus != NULL)
    {
        hapus = hapus->berikut;
        free(hapus);
        hapus = awal;
        cout << "\nKembali ke menu?  (Y/T) : ";
        cin >> jawab;
    }
}