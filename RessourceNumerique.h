#ifndef RESSOURCENUMERIQUE_H_INCLUDED
#define RESSOURCENUMERIQUE_H_INCLUDED
#include <iostream>
#include <string>
#include "Media.h"

using namespace std;

class RessourceNumerique:public Media{
private :
    std::string cheminAcces;
    int taille;
    std::string typeRN;

public :
    RessourceNumerique();
    void load2Media(int quantiteMedia, ifstream& infile);
    void afficheMedia();
    void add2media(int quantiteMedia);
    void saveMedia(ofstream& MonFlux);
    int searchMedia(string chaine);
    ~RessourceNumerique();
};



#endif // RESSOURCENUMERIQUE_H_INCLUDED
