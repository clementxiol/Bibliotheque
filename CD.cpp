#include "CD.h"
#include <charconv>

using namespace std;

CD::CD():Media()
{
    duree = 0;
    nombrePistes = 0;
    maisonProduction = "Unknown";
}

CD::~CD()
{
    Media::~Media();
}

void CD::load2Media(int quantiteMedia, ifstream& infile)
{
    Media::load2Media(quantiteMedia, infile);
    type = "CD";
    string _duree;
    getline(infile,_duree);
    from_chars(_duree.c_str(), _duree.c_str() + _duree.length(), duree );
    string _nombrePistes;
    getline(infile,_nombrePistes);
    from_chars(_nombrePistes.c_str(), _nombrePistes.c_str() + _nombrePistes.length(), nombrePistes );
    getline(infile,maisonProduction);
}


void CD::add2Media(int quantiteMedia){
    Media::add2Media(quantiteMedia);
    string _duree;
    string _nombrePistes;
    type = "CD";
    cout<<"Quelle est ma duree est de?"<<endl;
    getline(cin,_duree);
    from_chars(_duree.c_str(),_duree.c_str() + _duree.length(), duree);
    cout<<"Combien de pistes je possede?"<<endl;
    getline(cin,_nombrePistes);
    from_chars(_nombrePistes.c_str(), _nombrePistes.c_str() + _nombrePistes.length(), nombrePistes);
    cout<<"Dans quelle maison de production ai-je ete produit?"<<endl;
    getline(cin,maisonProduction);
}

void CD::afficheMedia()
{
    Media::afficheMedia();
    cout << "Mon nombre de pistes est: " << nombrePistes << endl;
    cout << "Ma maison du production est: " << maisonProduction << endl;
}

void CD::saveMedia(ofstream& MonFlux){
    Media::saveMedia(MonFlux);
    MonFlux << duree << endl;
    MonFlux << nombrePistes << endl;
    MonFlux << maisonProduction << endl;
}

int CD::searchMedia(std::string chaine) {
    Media::searchMedia(chaine);
    string _duree = to_string(duree);
    string _nombrePistes = to_string(nombrePistes);
    if((chaine == _duree) || (chaine == _nombrePistes) || (chaine == maisonProduction)){
        return 1;
    }
}