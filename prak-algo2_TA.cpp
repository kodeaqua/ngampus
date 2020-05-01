#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct data_input{
    int tipe, normal, cpu, memory, disk, hdd, ssd, os, graphic, sewa;
    char checkout;
} input;

struct data_harga{
    int variant, disk, os, graphic, sewa;
    long int checkout;
} harga;

struct data_user{
    string nama, pass, tipe, variant, disk, os, graphic, discount;
} user;

void separator(){
    cout << "*******************************************" << endl;
}

void header(){
    system("CLS");
    separator();
    cout << "*                                         *" << endl;
    cout << "* Virtual Private Server & Cloud Platform *" << endl;
    cout << "*            by: Kelompok X               *" << endl;
    cout << "*                                         *" << endl;
    separator();
}

void splash(){
    header();
    cout << " Selamat datang! " << endl;
    cout << " Kami adalah penyedia cloud terbaik~" << endl;
    separator();
    cout << " Tekan enter untuk melanjutkan...";
    getch();
}

void menu_id(){
    header();
    cout << " Nama     : ";
    cin >> user.nama;
    cout << " Password : ";
    cin >> user.pass;
}

void menu_tipe(){
    header();
    cout << " Tipe VM yang kamu butuhkan?" << endl;
    cout << " 1. Normal" << endl;
    cout << " 2. CPU Teroptimisasi" << endl;
    cout << " 3. Memory Teroptimisasi" << endl;
    separator();
    cout << " > ";
    cin >> input.tipe;
}

void menu_tipe_normal(){
    header();
    cout << " Pilih varian VM Normal:" << endl;
    cout << " 1. 2 vCPU, 4G Memory" << endl;
    cout << " 2. 4 vCPU, 8G Memory" << endl;
    cout << " 3. 8 vCPU, 16G Memory" << endl;
    cout << " 4. 16 vCPU, 32G Memory" << endl;
    separator();
    cout << " > ";
    cin >> input.normal;
}

void menu_tipe_cpu(){
    header();
    cout << " Pilih varian VM CPU Teroptmisiasi:" << endl;
    cout << " 1. 8 vCPU, 4G Memory" << endl;
    cout << " 2. 16 vCPU, 8G Memory" << endl;
    cout << " 3. 32 vCPU, 16G Memory" << endl;
    cout << " 4. 64 vCPU, 32G Memory" << endl;
    separator();
    cout << " > ";
    cin >> input.cpu;
}

void menu_tipe_memory(){
    header();
    cout << " Pilih varian VM Memory Teroptimisasi:" << endl;
    cout << " 1. 2 vCPU, 16G Memory" << endl;
    cout << " 2. 4 vCPU, 32G Memory" << endl;
    cout << " 3. 8 vCPU, 64G Memory" << endl;
    cout << " 4. 16 vCPU, 128G Memory" << endl;
    separator();
    cout << " > ";
    cin >> input.memory;
}

void menu_disk(){
    header();
    cout << " Pilih tipe disk yang digunakan:" << endl;
    cout << " 1. Harddisk (HDD)" << endl;
    cout << " 2. Solid State Drive (SSD)" << endl;
    separator();
    cout << " > ";
    cin >> input.disk;
}

void menu_hdd(){
    header();
    cout << " Masukan ukuran HDD [Rp.500/GB]:" << endl;
    cout << " > ";
    cin >> input.hdd;
}

void menu_ssd(){
    header();
    cout << " Masukan ukuran SSD [Rp.4000/GB]:" << endl;
    cout << " > ";
    cin >> input.ssd;
}

void menu_os(){
    header();
    cout << " Pilih sistem operasi untuk VM:" << endl;
    cout << " 1. Windows 10     [Paid]" << endl;
    cout << " 2. Ubuntu 18.04.4 [Free]" << endl;
    cout << " 3. Ubuntu 20.04   [Free]" << endl;
    cout << " > ";
    cin >> input.os;
}

void menu_graphic(){
    header();
    cout << " Pilih graphic card untuk VM:" << endl;
    cout << " 1. Standard" << endl;
    cout << " 2. GTX 1070" << endl;
    cout << " 3. Vega 4" << endl;
    cout << " 4. GTX 2080" << endl;
    cout << " 5. RX 580" << endl;
    cout << " > ";
    cin >> input.graphic;
}

void menu_sewa(){
    header();
    cout << " Berapa lama Anda akan menyewa? [hari]: " << endl;
    cout << " > ";
    cin >> input.sewa;
}

long int CheckOut(long int x){
    x = (harga.variant + harga.disk + harga.os + harga.graphic);
    if(input.sewa >= 7){
        x = ((x * input.sewa) / 100) * 70;
        user.discount = "30% OFF";
    } else if(input.sewa >= 30){
        x = ((x * input.sewa) / 100) * 50;
        user.discount = "50% OFF";
    } else {
        x = x * input.sewa;
        user.discount = "Tidak mendapat discount :(";
    }
    return x;
}

void menu_checkout(){
    header();
    cout << " Tipe VM : " << user.tipe << endl;
    cout << " Variant : " << user.variant << endl;
    cout << " Storage : " << user.disk << endl;
    cout << " OS      : " << user.os << endl;
    cout << " Grapchic: " << user.graphic << endl;
    cout << " Sewa    : " << input.sewa << " hari" << endl;
    cout << " Total   : " << CheckOut(harga.checkout) << " " << user.discount <<  endl;
    separator();
    cout << " Apa kamu yakin ingin melanjutkan? [Y/T]:" << endl;
    cout << " > ";
    cin >> input.checkout;
}

void menu_va(){
    header();
    cout << " Kamu dapat mengakses cloud servermu" << endl;
    cout << " setelah melakukan pembayaran." << endl;
    cout << " " << endl;
    cout << " Virtual Account: " << input.tipe << input.memory << input.disk << input.os << input.graphic << input.sewa << CheckOut(harga.checkout) << endl;
    cout << " " << endl;
    cout << " Login menggunakan username dan password" << endl;
    cout << " yang sama ke:" << endl;
    cout << " " << endl;
    cout << " https://ssh.cloud.kelompok3.com/login " << endl;
    cout << " " << endl;
    cout << " Terima kasih telah menggunakan cloud server kami :)" << endl;
    separator();
}

int main(){
    splash();

    id:
    menu_id();

    tipe:
    menu_tipe();
    if(input.tipe == 1){
        user.tipe = "Normal";
        tipe_normal:
        menu_tipe_normal();
        if(input.normal == 1){
            user.variant = "2 vCPU, 4G Memory";
            harga.variant = 30000;
        } else if(input.normal == 2){
            user.variant = "4 vCPU, 8G Memory";
            harga.variant = 60000;
        } else if(input.normal == 3){
            user.variant = "8 vCPU, 16G Memory";
            harga.variant = 120000;
        } else if(input.normal == 4){
            user.variant = "16 vCPU, 32G Memory";
            harga.variant = 240000;
        } else {
            goto tipe_normal;
        }
    } else if(input.tipe == 2){
        user.tipe = "CPU Teroptimisasi";
        tipe_cpu:
        menu_tipe_cpu();
        if(input.cpu == 1){
            user.variant = "8 vCPU, 4G Memory";
            harga.variant = 35000;
        } else if(input.cpu == 2){
            user.variant = "16 vCPU, 4G Memory";
            harga.variant = 70000;
        } else if(input.cpu == 3){
            user.variant = "32 vCPU, 16G Memory";
            harga.variant = 140000;
        } else if(input.cpu == 4){
            user.variant = "64 vCPU, 32G Memory";
            harga.variant = 280000;
        } else {
            goto tipe_cpu;
        }
    } else if(input.tipe == 3){
        user.tipe = "Memory Teroptimisasi";
        tipe_memory:
        menu_tipe_memory();
        if(input.memory == 1){
            user.variant = "2 vCPU, 16G Memory";
            harga.variant = 30000;
        } else if(input.memory == 2){
            user.variant = "4 vCPU, 32G Memory";
            harga.variant = 60000;
        } else if(input.memory == 3){
            user.variant = "8 vCPU, 64G Memory";
            harga.variant = 120000;
        } else if(input.memory == 4){
            user.variant = "16 vCPU, 128G Memory";
            harga.variant = 240000;
        } else {
            goto tipe_memory;
        }
    }
    else {
        goto tipe;
    }

    disk:
    menu_disk();
    if(input.disk == 1){
        user.disk = "Harddisk [HDD]";
        menu_hdd();
        harga.disk = 500 * input.hdd;
    } else if(input.disk == 2){
        user.disk = "Solid State Drive [SSD]";
        menu_ssd();
        harga.disk = 4000 * input.ssd;
    } else {
        goto disk;
    }

    os:
    menu_os();
    if(input.os == 1){
        user.os = "Windows 10";
        harga.os = 600000;
    } else if(input.os == 2){
        user.os = "Ubuntu 18.04.4";
        harga.os = 0;
    } else if(input.os == 3){
        user.os = "Ubuntu 20.04";
        harga.os = 0;
    } else{
        goto os;
    }

    graphic:
    menu_graphic();
    if(input.graphic == 1){
        user.graphic = "Standard";
        harga.graphic = 0;
    } else if(input.graphic == 2){
        user.graphic = "GTX 1070";
        harga.graphic = 70000;
    } else if(input.graphic == 3){
        user.graphic = "Vega 4";
        harga.graphic = 70000;
    } else if(input.graphic == 4){
        user.graphic = "GTX 2080";
        harga.graphic = 100000;
    } else if(input.graphic == 5){
        user.graphic = "RX 580";
        harga.graphic = 100000;
    } else {
        goto graphic;
    }

    sewa:
    menu_sewa();

    checkout:
    menu_checkout();
    if(input.checkout == 'Y' || input.checkout == 'y'){
        menu_va();
    } else if(input.checkout == 'T' || input.checkout == 't'){
        goto tipe;
    } else {
        goto checkout;
    }
}
