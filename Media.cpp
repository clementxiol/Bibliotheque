#include <charconv>
#include "Media.h"


using namespace std;

Media::Media()
{
}

Media::Media(string _auteur, string _titre, int _ID, string _type)
{
    type = _type;
    auteur = _auteur;
    titre = _titre;
    ID = _ID;
}

Media::~Media()
{

}

void Media::load2Media(int quantiteMedia, ifstream& infile)
{
        ID = quantiteMedia;
        getline(infile,auteur);
        getline(infile,titre);
}

string Media::ecritureMedia(int quantiteMedia, std::string data) {
    ID = quantiteMedia;
    size_t found = data.find(",");
    titre = data.substr(0,found);
    data = data.erase(0,(found+1));
    found = data.find(",");
    auteur = data.substr(0,found);
    data = data.erase(0,(found+1));
    return data;
}

void Media::saveMedia(ofstream& MonFlux)
{
    MonFlux << type << endl;
    MonFlux << auteur << endl;
    MonFlux << titre << endl;
}

int Media::searchMedia(string chaine)
{
    if ((chaine == type ) ||(chaine == auteur ) || (chaine == titre)){
        return 1;
    }
}

void Media::showMedia(int _ID, Media* M)
{
    M->afficheMedia();
}

void Media::deleteMedia(int a)
{

}

void Media::afficheMedia()
{
    cout << "Mon type est: " << type << endl;
    cout << "Mon ID est: " << ID << endl;
    cout << "Mon titre est: " << titre << endl;
    cout << "Mon auteur est: " << auteur << endl;
}

void Media::add2Media(int quantiteMedia) {
    ID = quantiteMedia;
    cout<<"Quel est l'auteur?"<<endl;
    getline(cin,auteur);
    cout<<"Quel est le titre?"<<endl;
    getline(cin,titre);
}

void Media::changeID(int i) {
    ID = i;
}