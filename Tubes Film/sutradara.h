#ifndef SUTRADARA_H_INCLUDED
#define SUTRADARA_H_INCLUDED

#include <iostream>
using namespace std;
#include "film.h"

#define first(L) ((L).first)
#define next(P) P->next
#define infoSutradara(P) P->infoSutradara
#define child(P) P->child
#define nil NULL


struct sutradara{
    string nama, umur;
    int lamaKarir;
};
typedef sutradara infoSutradara;
typedef struct elmSutrada *adrSutradara;
typedef struct elmRelasi *adrRelasi;

struct listRelasi{
    adrRelasi first;
};

struct elmSutrada{
    infoSutradara infoSutradara;
    adrSutradara next;
    listRelasi child;
};

struct elmRelasi{
    adrRelasi next;
    adrFilm infoFilm;
};


struct listSutradara{
    adrSutradara first;
};

void createListSutradara(listSutradara &LS);
adrSutradara elementSutradara(infoSutradara iSutradra);
void insertLastSutradara(listSutradara &LS, adrSutradara iSutradara);
void deleteLastSutradara(listSutradara &LS, adrSutradara &iSutrdara);
void showSutradara(listSutradara LS);
adrSutradara cariElmSutradara(listSutradara &LS, string nama, string age);
infoSutradara inputSutradara(infoSutradara &input);
void showSemua(listSutradara Lstr);
void hapusSutradara(listSutradara &LS, string nama, string umur, int karir);
bool cekSutradara(listSutradara LS, string nama, string age, int karir);
int hitungFilm(listSutradara LS, string namaStr,string umur);

void createRelasi(listRelasi &LR);
adrRelasi elementRelasi(adrFilm elRelasi);
void insertLastRelasi(listRelasi &LR, adrRelasi iRelasi);
void tambahDataRelasi(string &namaStr,string &umur, string &judul, int &kodeFilm);
void cariMaxSutradara(listSutradara LS);
void cariMinSutradara(listSutradara LS);

int menuPilihan();

#endif // SUTRADARA_H_INCLUDED
