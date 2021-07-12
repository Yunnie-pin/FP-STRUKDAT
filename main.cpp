#include <iostream>

using namespace std;

struct Tanah
{
    string kode_tanah;
    float harga_tanah;
    float ukuran_tanah;
};

struct Pembeli
{
    string nama_pembeli;
    string alamat;
    string nomor_telepon;
    string NIK;
    string kode_tanah;

    bool sold = false;
};

const int SIZE_TANAH = 20;
const int SIZE_PEMBELI = 100;
int counter = 0;
int input;

Pembeli pembeli[SIZE_PEMBELI];
Tanah tanah[20];

char menu();
void denah();
void pembelian_tanah();
void status_pembelian();
void sidebar();
bool check(string kode);
void mencocokan();

int main()
{
    while (true)
    {
        char select = menu();
        if (select == '1') //1. Pembelian tanah
        {
            pembelian_tanah();
        }
        else if (select == '2') //2. Show denah tanah
        {
            denah();
        }
        else if (select == '3') //3. Detail status pembelian
        {
        }
        else if (select == '4') //4. Keluar
        {
            break;
        }
        else
        {
            cout << "Maaf, menu tidak ditemukan";
        }
    }
}

char menu()
{
    string option;

    system("cls");
    cout << "Pembelian Tanah Sumber Maju" << endl;
    cout << "Silahkan masukkan kode angka untuk menampilkan menu" << endl;
    cout << " [1] Pembelian tanah" << endl;
    cout << " [2] Show denah tanah" << endl;
    cout << " [3] Detail status pembelian" << endl;
    cout << " [4] Keluar" << endl;
    cout << "Masukkan pilihan [1-4]: ";
    getline(cin, option);

    return option[0];
}

void denah()
{
    system("clear");

    cout << "DENAH KAPLING" << endl;

    for (int i = 0; i < SIZE_PEMBELI; i++)      //fungsi pengecheckan 
    {
        check(pembeli[i].kode_tanah);
    }



    for (int i = 1; i <= SIZE_TANAH; i++)   //fungsi output denah
    {
        if(pembeli[i].sold==true){

            system("printf '\033[31m'"); //warna merah 

            cout << "[" << i << "]";

            if (i % 4 == 0)
            {
                   cout << endl;
            }
            system("printf '\033[37m'"); //warna putih
            
        } else if (pembeli[i].sold==false){
            system("printf '\033[32m'"); //warna hijau

            cout << "[" << i << "]";
            cout << pembeli[i].sold;
            if (i % 4 == 0)
            {
            cout << endl;
            }
            system("printf '\033[37m'"); //warna putih
        }


        tanah[i].kode_tanah = "0" + i;
        tanah[i].ukuran_tanah = 100;
        tanah[i].harga_tanah = 1000000;
    }
    system("printf '\033[37m'"); //warna putih

}

void pembelian_tanah()
{
    string kode_tanah;
    string nama;
    string alamat;
    string nomor_telepon;
    string NIK;

    system("cls");
    denah();
    cout << "Masukkan kode petak tanah yang diinginkan: ";
    getline(cin, kode_tanah);
    cout << "Masukkan data diri Anda: " << endl;
    cout << "Nama: ";
    getline(cin, nama);
    cout << "Alamat: ";
    getline(cin, alamat);
    cout << "Nomor telepon: ";
    getline(cin, nomor_telepon);
    cout << "NIK: ";
    getline(cin, NIK);

    pembeli[counter].nama_pembeli = nama;
    pembeli[counter].alamat = alamat;
    pembeli[counter].nomor_telepon = nomor_telepon;
    pembeli[counter].NIK = NIK;
    pembeli[counter].kode_tanah = kode_tanah;

    counter++;
}

void sidebar()
{
    cout << "0/kembali kemenu utama" << endl;
    cout << "1/keluar" << endl;
    cout << "Masukkan nomor";
    cin >> input;
    if (input == 0)
    {
        main();
    }
    else if (input == 1)
    {
    }
}

bool check(string kode)
{
    for (int i = 1; i <= SIZE_TANAH; i++)
    {
        if (tanah[i].kode_tanah == kode)
        {
            return true;
        }
    }
    return false;

    for (int j = 0; j <= SIZE_PEMBELI; j++)
    {
        if (tanah[j].kode_tanah == kode)
        {
            pembeli[j].sold = true;
        }
    }
}

void mencocokan()
{
}
