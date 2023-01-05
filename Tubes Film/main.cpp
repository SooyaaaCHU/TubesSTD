#include "film.h"
#include "sutradara.h"

#include <iostream>

using namespace std;

int main(){
    listSutradara LS;
    listFilm LF;

    adrSutradara PSutradara;
    adrFilm pFilm;
    adrRelasi pRelasi;

    infoSutradara infoStr;
    infoFilm infoFilm;
    char kembali;

    int menu;
    int angka,i,kodeFilm,karir;

    string namaStr,judul,umur;
    string pilihan;

    createListSutradara(LS);
    createListFilm(LF);

    //input data sutrdara
    infoStr.nama = "Maxwell";
    infoStr.umur = "35";
    infoStr.lamaKarir = 5;
    PSutradara = elementSutradara(infoStr);
    insertLastSutradara(LS,PSutradara);

    infoStr.nama = "Janson";
    infoStr.umur = "40";
    infoStr.lamaKarir = 15;
    PSutradara = elementSutradara(infoStr);
    insertLastSutradara(LS,PSutradara);

    infoStr.nama = "Ali";
    infoStr.umur = "37";
    infoStr.lamaKarir = 3;
    PSutradara = elementSutradara(infoStr);
    insertLastSutradara(LS,PSutradara);


    //input data film
    infoFilm.judul = "Black_Widow";
    infoFilm.kode = 1;
    infoFilm.rate = 9;
    infoFilm.genre = "Super_Hero";
    pFilm = elementFilm(infoFilm);
    insertLastFilm(LF, pFilm);

    infoFilm.judul = "IT";
    infoFilm.kode = 2;
    infoFilm.rate = 8;
    infoFilm.genre = "Horror";
    pFilm = elementFilm(infoFilm);
    insertLastFilm(LF, pFilm);


    infoFilm.judul = "James_Bond";
    infoFilm.kode = 3;
    infoFilm.rate = 10;
    infoFilm.genre = "Action";
    pFilm = elementFilm(infoFilm);
    insertLastFilm(LF, pFilm);


    //input data untuk merelasikan
    PSutradara = cariElmSutradara(LS,"Maxwell","35");
    pFilm = cariElmFilm(LF,1,"Black_Widow");
    pRelasi = elementRelasi(pFilm);
    insertLastRelasi(child(PSutradara),pRelasi);
    pFilm = cariElmFilm(LF,2,"IT");
    pRelasi = elementRelasi(pFilm);
    insertLastRelasi(child(PSutradara),pRelasi);

    PSutradara = cariElmSutradara(LS,"Janson","40");
    pFilm = cariElmFilm(LF,1,"Black_Widow");
    pRelasi = elementRelasi(pFilm);
    insertLastRelasi(child(PSutradara),pRelasi);

    PSutradara = cariElmSutradara(LS,"Ali","37");
    pFilm = cariElmFilm(LF,2,"IT");
    pRelasi = elementRelasi(pFilm);
    insertLastRelasi(child(PSutradara),pRelasi);
    pFilm = cariElmFilm(LF,3,"James_Bond");
    pRelasi = elementRelasi(pFilm);
    insertLastRelasi(child(PSutradara),pRelasi);

    menu = menuPilihan();

    while (menu != 0){
        switch (menu){
            case 1:
                i =1;
                cout<<"Masukan jumlah Sutradara: ";
                cin>> angka;
                cout<<endl;

                while(i<=angka){
                    cout<<"Data Sutradara ke-"<<i<<endl;
                    inputSutradara(infoStr);
                    PSutradara = elementSutradara(infoStr);
                    insertLastSutradara(LS,PSutradara);
                    i++;
                }
                break;

            case 2:
                i=1;
                cout<<"Masukan data film: ";
                cin>> angka;
                cout<<endl;

                while(i<=angka){
                    cout<<"Data Film ke-"<<i<<endl;
                    inputFilm(infoFilm);
                    pFilm = elementFilm(infoFilm);
                    insertLastFilm(LF, pFilm);
                    i++;
                }
                break;
            case 3:
                i=1;
                cout<<"Input jumlah data: ";
                cin>> angka;
                cout<<endl;
                while(i<=angka){
                    cout<<"Data :"<<endl;
                    tambahDataRelasi(namaStr,umur,judul,kodeFilm);
                    PSutradara = cariElmSutradara(LS,namaStr,umur);
                    pFilm = cariElmFilm(LF,kodeFilm,judul);
                    pRelasi = elementRelasi(pFilm);
                    insertLastRelasi(child(PSutradara),pRelasi);
                    i++;
                }
                break;
            case 4:
                cout<<"Cek Data Sutradara"<<endl;
                cout<<"Nama: ";
                cin>>namaStr;
                cout<<"Umur: ";
                cin>>umur;
                cout<<"Lama Karir: ";
                cin>>karir;
                cout<<endl;
                if(cekSutradara(LS,namaStr,umur,karir)){
                    cout<<"Sutradara "<<namaStr<<" Data tersedia"<<endl;
                }else{
                    cout<<"Sutradara "<<namaStr<<" Tidak tersedia"<<endl;
                }
                break;
            case 5:
                cout<<"Hapus Data Sutradara"<<endl;
                cout<<"Nama: ";
                cin>>namaStr;
                cout<<"Umur: ";
                cin>>umur;
                cout<<"Lama karir: ";
                cin>>karir;
                hapusSutradara(LS,namaStr,umur,karir);
                break;
            case 6:
                cout<<"Menghitung Jumlah Sutradara"<<endl;
                cout<<"Nama: ";
                cin>>namaStr;
                cout<<"Umur: ";
                cin>>umur;
                cout<<hitungFilm(LS,namaStr,umur)<<" film telah disutradarai oleh "<<namaStr;
                break;
            case 7:
                cout<<"Tampilkan data(sutradara/film/semua): ";
                cin>> pilihan;
                cout<<endl;
                if(pilihan == "sutradara" || pilihan=="Sutradara"){
                    showSutradara(LS);
                }else if(pilihan == "film" || pilihan == "Film"){
                    showFilm(LF);
                }else if(pilihan == "semua" || pilihan == "Semua"){
                    showSemua(LS);
                }
                break;
            case 8:
                cariMaxSutradara(LS);
                break;
            case 9:
                cariMinSutradara(LS);
                break;
            }
            cout << endl<< "Kembali ke menu utama? (Y/N): ";
            cin >> kembali;

            if (kembali == 'Y' || kembali == 'y'){
                cout << endl;
                menu = menuPilihan();
            }
            else if (kembali == 'N' || kembali == 'n'){
                menu = 0;
            }
        }
        cout << endl<< "Program Telah Berakhir"<<endl;
    return 0;
}
