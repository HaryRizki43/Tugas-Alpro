#include <iostream>
using namespace std;

void hitungHarga(int hargabarang, int jumlahpembelian, int diskon) {
    
    int totalHarga = hargabarang * jumlahpembelian;
    int totalDiskon = totalHarga * diskon / 100;
    int totalAkhir = totalHarga - totalDiskon;
    
    cout <<"==========================================="<< endl;
    cout <<"=========Selamat datang di toko kami======="<< endl;
    cout <<"===========Jumlah Harga Pembelian=========="<< endl;
    cout <<"\nJumlah barang yg dibeli = " << jumlahpembelian << " pcs";
    cout <<"\nHarga perbarang = Rp." << hargabarang;
    cout <<"\nDiskon spesial Hari Raya = " << diskon << "%" <<endl;
    cout <<"\n==========================================="<< endl;
    cout <<"Total Harga = Rp." << totalAkhir<< endl;
    cout <<"==========================================="<< endl;
    cout <<"=======Terima kasih atas kunjungannya======"<< endl;
    cout <<"==========================================="<< endl;
}

int main() {
    hitungHarga(19000, 9, 45);

    return 0;
}
