#include "RessourceNumerique.h"
#include <iostream>
#include <charconv>

using namespace std;

RessourceNumerique::RessourceNumerique():Media()
{
    typeRN = "Unknown";
    taille = 0;
    cheminAcces = "Unknown";
}

RessourceNumerique::~RessourceNumerique()
{
    Media::~Media();
}

void RessourceNumerique::load2Media(int quantiteMedia, std::ifstream &infile) {
    Media::load2Media(quantiteMedia, infile);
    getline(infile, typeRN);
    string _taille;
    getline(infile,_taille);
    from_chars(_taille.c_str(), _taille.c_str() + _taille.length(), taille );
    getline(infile,cheminAcces);
}

void RessourceNumerique::add2media(int quantiteMedia) {
    Media::add2Media(quantiteMedia);
    type = "RessourceNumerique";
    cout<<"Quel est mon genre de ressource numérique?"<<endl;
    getline(cin,typeRN);
    string _taille;
    cout<<"Quelle est ma taille (en Mo)";
    getline(cin,_taille);
    from_chars(_taille.c_str(), _taille.c_str() + _taille.length(), taille );
    cout<<"Quel est mon chemin d'accès?"<<endl;
    getline(cin,cheminAcces);
}

void RessourceNumerique::afficheMedia()
{
    Media::afficheMedia();
    cout << "Mon genre de ressource numérique est: " << typeRN << endl;
    cout << "Ma taille est de : " << taille << "en " << endl;
    cout << "Mon chemin d'accès est: " << cheminAcces << endl;
}

void RessourceNumerique::saveMedia(std::ofstream &MonFlux) {
    Media::saveMedia(MonFlux);
    MonFlux << typeRN << endl;
    MonFlux << taille << endl;
    MonFlux << cheminAcces << endl;
}

int RessourceNumerique::searchMedia(std::string chaine) {
    Media::searchMedia(chaine);
    string _taille = to_string(taille);
    if((chaine == _taille ) || (chaine == typeRN) || (chaine == cheminAcces)){
        return 1;
    }
}