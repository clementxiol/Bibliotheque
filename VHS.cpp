#include "VHS.h"
#include <charconv>
using namespace std;

VHS::VHS():Media()
{
    duree = 0;
    maisonProduction = "Unknown";
}

VHS::~VHS()
{
    Media::~Media();
}

void VHS::load2Media(int quantiteMedia, ifstream& infile){
    Media::load2Media(quantiteMedia,infile);
    string _duree;
    getline(infile,_duree);
    from_chars(_duree.c_str(), _duree.c_str() + _duree.length(), duree );
    getline(infile,maisonProduction);

}

void VHS::addMedia(std::string _type) {

}

void VHS::add2Media(int quantiteMedia) {
    Media::add2Media(quantiteMedia);
    string _duree;
    type = "VHS";
    cout<<"Quelle est ma duree?"<<endl;
    getline(cin,_duree);
    from_chars(_duree.c_str(),_duree.c_str() + _duree.length(), duree);
    cout<<"Dans quelle maison de production ai-je ete produit ?"<<endl;
    getline(cin,maisonProduction);
}

void VHS::afficheMedia()
{
    Media::afficheMedia();
    cout << "Ma duree est: " << duree << endl;
    cout << "Ma maison du production est: " << maisonProduction << endl;
}

void VHS::saveMedia(ofstream& MonFlux){
    Media::saveMedia(MonFlux);
    MonFlux << duree << endl;
    MonFlux << maisonProduction << endl;
}

int VHS::searchMedia(std::string chaine) {
    Media::searchMedia(chaine);
    string _duree = to_string(duree);
    if ((chaine ==_duree) || (chaine == maisonProduction)){
        return 1;
    }
}