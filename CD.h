#ifndef CD_H_INCLUDED
#define CD_H_INCLUDED
#include <iostream>
#include <string>
#include "Media.h"
using namespace std;

class CD:public Media{
private :
    std::string maisonProduction;
    int duree;
    int nombrePistes;

public :
    CD();
    void load2Media(int quantiteMedia, ifstream& infile);
    void afficheMedia();
    void add2Media(int quantiteMedia);
    void saveMedia(ofstream& MonFlux);
    int searchMedia(string chaine);
    ~CD();
};

#endif // CD_H_INCLUDED
