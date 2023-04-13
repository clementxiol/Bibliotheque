#include "Revue.h"
#include <charconv>

using namespace std;

Revue::Revue():Livre()
{
    editeur = "Unknown";
    nombreArticles = 0;
}

Revue::~Revue()
{
    Livre::~Livre();
}

void Revue::load2Media(int quantiteMedia, std::ifstream &infile) {
    Livre::load2Media(quantiteMedia,infile);
    getline(infile,editeur);
    string _nombreArticles;
    getline(infile,_nombreArticles);
    from_chars(_nombreArticles.c_str(), _nombreArticles.c_str() + _nombreArticles.length(), nombreArticles );
}

void Revue::add2Media(int quantiteMedia) {
    Livre::add2Media(quantiteMedia);
    type = "Revue";
    cout<<"Quel est mon editeur?"<<endl;
    getline(cin,editeur);
    string _nombreArticles;
    cout<<"Combien y a-t-il d'articles?"<<endl;
    getline(cin,_nombreArticles);
    from_chars(_nombreArticles.c_str(), _nombreArticles.c_str() + _nombreArticles.length(), nombreArticles );
}

void Revue::afficheMedia()
{
    Livre::afficheMedia();
    cout << "Mon editeur est:" << editeur <<endl;
    cout << "Mon nombre d'article est de:" << nombreArticles << endl;
}

void Revue::saveMedia(ofstream& MonFlux){
    Livre::saveMedia(MonFlux);
    MonFlux << editeur << endl;
    MonFlux << nombreArticles << endl;
}

int Revue::searchMedia(std::string chaine) {
    Livre::searchMedia(chaine);
    string _nombreArticles;
    if((chaine == editeur) || (chaine == _nombreArticles)){
        return 1;
    }
}