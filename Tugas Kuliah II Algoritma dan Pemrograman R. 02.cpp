#include <iostream>
using namespace std;

/*
Kelas: Algoritma dan Pemrograman R. 02
Kode Mata Kuliah: 22080302101
Nama Dosen: Dhieka Avrilia Lantana, S.Kom., M.Kom. .

Nama Anggota Kelompok:
- Arya Yusuf Karan (NPM: 227064516066)
- Aldan Rafa Akilah (NPM: 227064516043)
- Ali Imron (NPM: 227064516078)
- Abimanyu Liwa Al Shidqi Hardianto (NPM: 227064516079)
- Gilang Rangga Aditya (NPM: 227064516085)
*/

int sequentialsearch(string nb[], int jumlahelemen, string key){
	bool status=false;
	for (int a=0; a<jumlahelemen; a++){
		if (key==nb[a]){
			status=true;
			return a;
			break;
		}
	}
	if (status==false){
	return -1;
	}
}

int main(){
	int menu;
	char pilihan;
	string daftarbarang[]={"T-Shirt", "Celana", "Rok", "Sweater", "Hoodie"};
	float daftarharga[]={50000, 75000, 75000, 100000, 125000};
	int jumlahelemen=sizeof(daftarbarang)/sizeof(daftarbarang[0]);
	string key;
	int pilihanbarang[100], hargabarang[100], jumlahbarang[100], subtotal[100];
	string namabarang[100];
	int totalbayar=0;
	int a=0;
	bool selesai=false;
	int jumpembayaran;
	int kembalian;
	
do{
	
	cout<<"Toko Pakaian Gokil"<<endl;
	cout<<"========================="<<endl;
	cout<<"1. Pricelist"<<endl;
	cout<<"2. Cari Harga Barang"<<endl;
	cout<<"3. Order"<<endl;
	cout<<"4. Bayar"<<endl;
	cout<<"5. Cetak Receipt"<<endl;
	cout<<"Pilih Menu: ";
	cin>>menu;
	
	switch (menu){
		case 1: {
			cout<<"==========Daftar Harga Barang=========="<<endl;
			cout<<"1. T-Shirt: Rp. 50.000"<<endl;
			cout<<"2. Celana: Rp. 75.000"<<endl;
			cout<<"3. Rok: Rp. 75.000"<<endl;
			cout<<"4. Sweater: Rp. 100.000"<<endl;
			cout<<"5. Hoodie: Rp. 125.000"<<endl;
		break; }
		
		case 2: {
			cout<<"Masukan nama barang yang ingin dicari: ";
			cin>>key;
			
			int indeksbarang=sequentialsearch(daftarbarang, jumlahelemen, key);
			if (indeksbarang==-1){
			cout<<"Barang yang anda cari tidak tersedia"<<endl;	
			}
			else {
			cout<<"Harga barang yang dicari adalah: Rp. "<<daftarharga[indeksbarang]<<endl;	
			}
		break; }
		
		case 3: {
			cout<<"==========Daftar Harga Barang=========="<<endl;
			cout<<"1. T-Shirt: Rp. 50.000"<<endl;
			cout<<"2. Celana: Rp. 75.000"<<endl;
			cout<<"3. Rok: Rp. 75.000"<<endl;
			cout<<"4. Sweater: Rp. 100.000"<<endl;
			cout<<"5. Hoodie: Rp. 125.000"<<endl;
			cout<<"========================================"<<endl;
			cout<<"Tekan 0 jika telah selesai melakukan pemesanan"<<endl;
			
			while (selesai==false){
				cout<<endl;
				cout<<"Masukan nomor barang: ";
				cin>>pilihanbarang[a];
				
				if (pilihanbarang[a]<=5){
					if (pilihanbarang[a]==0){
						selesai=true;
					}
					else {
						switch (pilihanbarang[a]){
							case 1: namabarang[a]="T-Shirt";hargabarang[a]=50000; break;
							case 2: namabarang[a]="Celana";hargabarang[a]=75000; break;
							case 3: namabarang[a]="Rok";hargabarang[a]=75000; break;
							case 4: namabarang[a]="Sweater";hargabarang[a]=100000; break;
							case 5: namabarang[a]="Hoodie";hargabarang[a]=125000; break;
							default: namabarang[a]=" ";hargabarang[a]=0; break;
						}
						
						cout<<"("<<namabarang[a]<<") "<<"Jumlah: ";
						cin>>jumlahbarang[a];
						cout<<endl;
						
						subtotal[a]=jumlahbarang[a]*hargabarang[a];
						totalbayar+=subtotal[a];
						a++;
					}
				}
				
				else {
					cout<<"Barang yang anda pilih tidak sesuai"<<endl;
					cout<<endl;
				}
			}
		break; }
		
		case 4: {
			cout<<"Total yang harus dibayar: Rp. "<<totalbayar<<endl;
			cout<<"Masukan jumlah pembayaran: Rp. ";
			cin>>jumpembayaran;
			kembalian=jumpembayaran-totalbayar;
			if (kembalian>=0){
				cout<<"Kembalian anda: Rp. "<<kembalian<<endl;
			}
			else {
				cout<<"Jumlah uang yang anda masukkan tidak cukup"<<endl;
			}
		break; }
		
		case 5: {
			if (jumpembayaran==0){
				cout<<"Harap melakukan pembayaran terlebih dahulu"<<endl;
			}
			
			else {
			cout<<"			Invoice Pembelian			"<<endl;
			cout<<"--------------------------------------------------------------------------------"<<endl;
			cout<<"No	Nama Barang	Harga		Jumlah		Sub Total		"<<endl;
			cout<<"--------------------------------------------------------------------------------"<<endl;
			for (int b=0; b<a; b++){
				cout<<b+1<<"	"<<namabarang[b]<<"		"<<"Rp. "<<hargabarang[b]<<"	"<<jumlahbarang[b]<<"		"<<"Rp. "<<subtotal[b]<<endl;
			}
			cout<<"--------------------------------------------------------------------------------"<<endl;
			cout<<"Total Harga: Rp. "<<totalbayar<<endl;
			cout<<"Uang anda: Rp. "<<jumpembayaran<<endl;
			cout<<"Kembalian: Rp. "<<kembalian<<endl;
			cout<<endl;
		}
		break; }
		
		default:
			cout<<"Menu tidak tersedia"<<endl;
	}
	
	cout<<"Apakah anda ingin memilih menu lain (Y/N): ";
	cin>>pilihan;
	cout<<endl;
}

while (pilihan=='Y');{
	cout<<"========== Terima Kasih =========="<<endl;
}

return 0;
}