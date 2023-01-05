#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include <iostream>
using namespace std;

#define first(L) ((L).first)
#define nextFilm(P) P->nextFilm
#define infoFilm(P) P->infoFilm
#define nil NULL

struct film{
    string judul, genre;
    int rate;
    int kode;
};
typedef film infoFilm;
typedef struct elmFilm *adrFilm;

struct elmFilm{
    infoFilm infoFilm;
    adrFilm nextFilm;
};

struct listFilm{
    adrFilm first;
};

void createListFilm(listFilm &LF);
adrFilm elementFilm(infoFilm iFilm);
void insertLastFilm(listFilm &LF, adrFilm iFilm);
void deleteLastFilm(listFilm &LF, adrFilm &iFilm);
void showFilm(listFilm LF);
adrFilm cariElmFilm(listFilm &LF, int kode, string title);
infoFilm inputFilm(infoFilm &input);

#endif // FILM_H_INCLUDED
