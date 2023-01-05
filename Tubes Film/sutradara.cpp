#include "sutradara.h"

void createListSutradara(listSutradara &LS){
    first(LS) = nil;
};

adrSutradara elementSutradara(infoSutradara iSutradra){
    adrSutradara adrS;
    adrS = new elmSutrada;
    infoSutradara(adrS) = iSutradra;
    next(adrS) = nil;
    createRelasi(child(adrS));

    return adrS;
};

void insertLastSutradara(listSutradara &LS, adrSutradara iSutradara){
    if(first(LS)== nil){
        first(LS) = iSutradara;
    }else{
        adrSutradara adrS;
        adrS = first(LS);
        while(next(adrS)!=nil){
            adrS = next(adrS);
        }
        next(adrS) = iSutradara;
    }
};

void deleteLastSutradara(listSutradara &LS, adrSutradara &iSutrdara){
    adrSutradara adrS;
    adrS = first(LS);

    while(next(next(adrS))!=nil){
        adrS = next(adrS);
    }
    iSutrdara = next(adrS);
    next(adrS) = nil;
};

void showSutradara(listSutradara LS){
    //menampilkan hanya list sutradara
    if(first(LS)== nil){
        cout<<"List Data Tidak Ada"<<endl;
    }else{
        adrSutradara adrS;
        adrS = first(LS);
        cout<<"Data Sutrada"<<endl;
        while(adrS !=nil){
            cout<<"Nama Sutradara: "<<infoSutradara(adrS).nama<<endl;
            cout<<"Umur Sutradara: "<<infoSutradara(adrS).umur<<endl;
            cout<<"Lama Berkarir: "<<infoSutradara(adrS).lamaKarir<<" Tahun"<<endl<<endl;
            adrS = next(adrS);
        }
    }
};

adrSutradara cariElmSutradara(listSutradara &LS, string nama, string age){
    //mencari elemen sutradara
    adrSutradara adrS;
    adrS = first(LS);
    while (adrS!=nil) {
        if(infoSutradara(adrS).nama == nama && infoSutradara(adrS).umur == age){
            return adrS;
            break;
        }
        adrS = next(adrS);
    }
    return  nil;
};

bool cekSutradara(listSutradara LS, string nama, string age, int karir){
    //mengembalikan true jika sutradara terdapat pada list
    adrSutradara adrS;
    bool status;
    adrS = first(LS);
    while(adrS != nil) {
        if(infoSutradara(adrS).nama == nama && infoSutradara(adrS).umur == age && infoSutradara(adrS).lamaKarir == karir){
            status = true;
            break;
        }else{
            status = false;
        }
        adrS = next(adrS);
    }
    return status;
}

infoSutradara inputSutradara(infoSutradara &input){
    cout<<"Nama Sutradara: ";
    cin>> input.nama;
    cout<<"Umur Sutradara: ";
    cin>> input.umur;
    cout<<"Lama Karir: ";
    cin>> input.lamaKarir;
    cout<<endl;

    return input;
};

void createRelasi(listRelasi &LR){
    first(LR) = nil;
};

adrRelasi elementRelasi(adrFilm elRelasi){
    adrRelasi Rel = new elmRelasi;
    infoFilm(Rel) = elRelasi;
    next(Rel) = nil;

    return Rel;
};

void insertLastRelasi(listRelasi &LR, adrRelasi iRelasi){
    if(first(LR)==nil){
        first(LR) = iRelasi;
    }else{
        adrRelasi rel;
        rel = first(LR);
        while(next(rel)!=nil){
            rel = next(rel);
        }
        next(rel) = iRelasi;
    }
};

void hapusSutradara(listSutradara &LS, string nama, string umur, int karir){
    //hapus sutradara berdasarkan pilihan
    adrSutradara adrS1;
    adrSutradara adrSlast;
    adrS1 = cariElmSutradara(LS, nama, umur);
    adrSutradara adrS2 = first(LS);

    adrSlast = first(LS);
    while(next(adrSlast)!=nil){
        adrSlast = next(adrSlast);
    }

    if(adrS1 != first(LS) && adrS1!=adrSlast){
         while (next(adrS2)!=adrS1){
            adrS2 = next(adrS2);
        }
        next(adrS2) = next(adrS1);
        next(adrS1) = nil;
    }
    if(adrS1 == first(LS)){
        first(LS) = next(adrS1);
        next(adrS1) = nil;
    }
    if (adrS1 == adrSlast){
        while (next(adrS2)!=adrSlast){
            adrS2=next(adrS2);
        }
        next(adrS2)=nil;
        next(adrS1)=nil;
    }

}

int hitungFilm(listSutradara LS, string namaStr,string umur){
    //menghitung child dari elemen sutradara yang dicari
    adrSutradara adrS;

    adrS = cariElmSutradara(LS,namaStr,umur);
    listRelasi LR = child(adrS);

    adrRelasi adrR;
    int hitung = 0;
    adrR = first(LR);
    while(adrR!=nil){
        hitung = hitung + 1;
        adrR=next(adrR);
    }
    return hitung;
}

void showSemua(listSutradara Lstr){
    //menampilkan data sutradara beserta filmnya
    adrSutradara p;
    adrRelasi pF;
    int count;

    if (first(Lstr) == nil){
        cout<<"Tidak Ada List"<<endl;
    }else{
        p = first(Lstr);
        while(p!=nil){
            cout<<endl;
            cout<<"Sutradara "<<infoSutradara(p).nama<<endl;
            cout<<"Umur: "<<infoSutradara(p).umur<<endl;
            cout<<"Lama Karir: "<<infoSutradara(p).lamaKarir<<endl;
            pF = first(child(p));
            while(pF!=nil){
                cout<<endl<<"Judul Film "<<infoFilm(infoFilm(pF)).judul<<endl;
                cout<<"Genre: "<<infoFilm(infoFilm(pF)).genre<<endl;
                cout<<"Rate: "<<infoFilm(infoFilm(pF)).rate<<endl;
                cout<<"Kode: "<<infoFilm(infoFilm(pF)).kode<<endl;
                pF = next(pF);
            }
            p = next(p);
        }
    }
};

void tambahDataRelasi(string &namaStr,string &umur, string &judul, int &kodeFilm){
    //buat input di main
    cout<<"Nama Sutradara: ";
    cin>>namaStr;
    cout<<"Umur: ";
    cin>>umur;
    cout<<"Judul Film: ";
    cin>>judul;
    cout<<"Kode Film: ";
    cin>>kodeFilm;
    cout<<endl;
}

void cariMaxSutradara(listSutradara LS){
    //mencari sutradara dengan film terbanyak
    int jumlah;
    int maxx=0;
    adrSutradara pSutradara,pSimpan;
    pSutradara = first(LS);

    while(pSutradara!=nil){
       jumlah = hitungFilm(LS,infoSutradara(pSutradara).nama,infoSutradara(pSutradara).umur);
       if (maxx<jumlah){
            maxx=jumlah;
            pSimpan=pSutradara;
       }
       pSutradara=next(pSutradara);
    }
    cout<<infoSutradara(pSimpan).nama<<" dengan "<<maxx<<" film"<<endl;
};

void cariMinSutradara(listSutradara LS){
    //mencari sutradara dengan film paling sedikit
    int jumlah;
    adrSutradara pSutradara,pSimpan;
    pSutradara = first(LS);
    int minn = hitungFilm(LS,infoSutradara(first(LS)).nama,infoSutradara(first(LS)).umur);

    while(pSutradara!=nil){
       jumlah = hitungFilm(LS,infoSutradara(pSutradara).nama,infoSutradara(pSutradara).umur);
       if (minn>jumlah){
            minn=jumlah;
            pSimpan=pSutradara;
       }
       pSutradara=next(pSutradara);
    }
    cout<<infoSutradara(pSimpan).nama<<" dengan "<<minn<<" film"<<endl;
};

int menuPilihan(){
    cout<<"===FITUR MENU====" << endl;
    cout<<"1.Menambah data Sutradara" << endl;
    cout<<"2.Menambah data Film" << endl;
    cout<<"3.Merelasikan data Film yang di sutradarai" << endl;
    cout<<"4.Mencari/Cek data sutradara" << endl;
    cout<<"5.Menghapus data di list Sutradara" << endl;
    cout<<"6.Menampilkan jumlah film yang di Sutradarai oleh" << endl;
    cout<<"7.Menampilkan data(sutradara/film/semua)" << endl;
    cout<<"8.Menampilkan data sutradara yang memegang film terbanyak" << endl;
    cout<<"9.Menampilkan data sutradara yang memegang film paling sedikit" << endl;
    cout<<"0.Exit" << endl;
    cout<<"Masukkan menu : ";

    int menu = 0;
    cin >> menu;
    return menu;
};
