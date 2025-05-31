//Nama : z

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Barang {
	string namaBarang;
	int jumlah;
	int harga;
};

class Marketplace {
	private:
	string namaUser, nim, alamat, ekspedisi;
	int saldo = 0;
	int pilih;
	vector<Barang>keranjang;
	bool pakaiVoucher;
	bool pakaiAsuransi;
	bool gratisOngkir;
		
	public:
		void login() {
			cout << "===Login Akun===\n";
			cout << "Masukkan Nama: ";
			getline (cin, namaUser);
			cout << "Masukkan NIM: ";
			getline(cin, nim);
			cout << "Berhasil Login\n";
		}
		
		void tambahSaldo(int jumlah){
			saldo += jumlah;
			cout << "saldo anda berhasil ditambahkan. Saldo sekarang Rp " << saldo << endl;
		}
		
		void tambahBarang () {
			Barang b;
			cout << "Masukkan Nama Barang: ";
			getline(cin, b.namaBarang);
			cin.ignore();
			cout << "Masukkan Harga Barang: ";
			cin >> b.harga;
			cout << "Masukkan jumlah barang: ";
			cin >> b.jumlah;
			cout << "Anda berhasil menambahkan barang\n";
		}
		
		void hapusBarang() {
			if(keranjang.empty()) {
				cout << "Keranjang Kosong";
			}
			
			cout << "Pilih Nomor barang yang ingin dihapus: ";
			for(int i=0; i < keranjang.size(); i++) {
				cout << i+1 << ". " << keranjang[i].namaBarang << endl;
			}
			int pilih;
			cin >> pilih;
			if(pilih <=1 && pilih >= keranjang.size() + (pilih - 1)) {
				keranjang.erase(keranjang.begin() - 1);
					cout << "Barang berhasil dihapus";
				}else{
					cout << "barang gagal dihapus";
				}
			}
		
		void setAlamat() {
			cout << "Masukkan Alamat pengiriman: ";
			cin >> alamat;
		}
		
		void pilihVoucher() {
			cout << "Menggunakan voucher 10%? (y/n)";
			if(pilih == 'y'|| pilih =='Y'){
				pakaiVoucher = true;
			}else{
				pakaiVoucher = false;
			}
		}
		
		void pilihAsuransi() {
			cout << "Menggunakan asuransi sebesar Rp.5000? (y/n)";
			if(pilih == 'y'|| pilih =='Y'){
				pakaiAsuransi = true;
			}else{
				pakaiAsuransi = false;
			}
		}
		
		void pilihgratisOngkir() {
			cout << "mrnggunakan gratis ongkir maks 10.000? ";
			if(pilih == 'y'|| pilih =='Y'){
				gratisOngkir = true;
			}else{
				gratisOngkir = false;
			}
		}
		
		void Ekspedisi() {
			cout << "Masukkan Alamat Ekspedisi: ";
			cin >> ekspedisi;
		}
		void checkout(int total){
			if(pakaiVoucher) {
				total = 90/100;
			}
			
			if(pakaiAsuransi) {
				total += 5000;
			}
			
			int ongkir = 15000;
			if(gratisOngkir) {
				ongkir += saldo;
				
			}
			int jumlah;
			saldo -= jumlah;
		}
		
		void strukPembayaran() {
			ofstream file << ("struct_pembayaran.txt");
			file << "===Struk Pembayaran===\n";
			file << "Nama: " << namaUser << endl;
			file << "NIM: " << nim << endl;
			file << "Saldo: " << saldo << endl;
			file << "Barang: " << keranjang[i].namaBarang << endl;
			file.close();
		}
		
		void menu(){
			
			do {
				cout << "===Menu Akun==\n";
				cout << "1. Tambah Saldo\n";
				cout << "2. Tambah Barang\n";
				cout << "3. Hapus Barng\n";
				cout << "4. Alamat\n";
				cout << "5. Voucher: Diskon 10%\n";
				cout << "6. Tambah Asuransi Rp5000: \n";
				cout << "7. Memilih Ekspedisi (JNE, JNT, SIcepat)\n";
				cout << "8. Gratis Ongkir: Maks 10.000 \n";
				cout << "9. struck pembayaran\n";
				cout << "10. keluar\n";
				cout << "Pilihan\n";
				cin >> pilih;
				
				switc (pilih) {
					case 1: cout << "Berhasil Tambah Saldo\n"; break;
					case 2: tambahBarang; break;
					case 3: hapusBarang; break;
					case 4: setAlamat; break;
					case 5: pilihVoucher; break;
					case 6: pilihasuransi; break;
					case 7: Ekspedisi; break;
					case 8: gratisOngkir; break;
					case 9: strukPembayaran; break;
					case 10: keluar; break;
					default: cout << "Tidak valid" << endl;
				}
			}while (pilih !=1) 
		}
		
};

int main () {
	Marketplace mk;
	mk.login();
	mk.menu();
	
	return 0;
	}


