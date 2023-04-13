#ifndef REVUE_H_INCLUDED
#define REVUE_H_INCLUDED
#include <iostream>
#include <string>
#include "Livre.h"

using namespace std;

class Revue:public Livre{
private :
    int nombreArticles;
    std::string editeur;

public :
    Revue();
    void load2Media(int quantiteMedia,std::ifstream& infile);
    void add2Media(int quantiteMedia);
    void afficheMedia();
    void saveMedia(ofstream& MonFlux);
    int searchMedia(string chaine);
    ~Revue();

};


#endif // REVUE_H_INCLUDED
