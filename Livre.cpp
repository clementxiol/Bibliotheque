
#include <charconv>
#include "Livre.h"


using namespace std;

Livre::Livre():Media()
{
}

Livre::Livre(string _auteur,string _titre, int _ID, string _type,int _date, int _nombrePages,string _collection, string _resume ):Media(_auteur,_titre,_ID,_type)
{
    date = _date;
    nombrePages = _nombrePages;
    collection = _collection;
    resume = _resume;
}

Livre::~Livre()
{
    cout << "Tout est detruit " <<endl;
}

void Livre::load2Media(int quantiteMedia, ifstream& infile)
{
        Media::load2Media(quantiteMedia, infile);
        type = "Livre";
        string _date;
        getline(infile,_date);
        from_chars(_date.c_str(), _date.c_str() + _date.length(), date );
        string _nombrePages;
        getline(infile,_nombrePages);
        from_chars(_nombrePages.c_str(), _nombrePages.c_str() + _nombrePages.length(), nombrePages );
        getline(infile,collection);
        getline(infile,resume);
}




void Livre::getResume(std::string const){
  
}


void Livre::afficheMedia()
{
    Media::afficheMedia();
    cout << "Ma date est: " << date << endl;
    cout << "Mon nombre de page est: " << nombrePages << endl;
    cout << "Ma collection est: " << collection << endl;
    cout << "Mon resume est: " << resume << endl;
}

void Livre::add2Media(int quantiteMedia) {
    Media::add2Media(quantiteMedia);
    type = "Livre";
    string _date;
    string _nombrePages;
    cout<<"En quelle annee ai-je ete publie?"<<endl;
    getline(cin,_date);
    from_chars(_date.c_str(), _date.c_str() + _date.length(), date );
    cout<<"Combien ai-je de pages?"<<endl;
    getline(cin,_nombrePages);
    from_chars(_nombrePages.c_str(), _nombrePages.c_str() + _nombrePages.length(), nombrePages );
    cout<<"De quel collection je proviens?"<<endl;
    getline(cin,collection);
    cout<<"Quel est mon resume?"<<endl;
    getline(cin,resume);

}


string Livre::ecritureMedia(int quantiteMedia, std::string data) {
    type = "Livre";
    string dataN = Media::ecritureMedia(quantiteMedia, data);
    size_t found = dataN.find(",");
    string _date = dataN.substr(0,found);
    from_chars(_date.c_str(),_date.c_str() + _date.length(), date);
    dataN = dataN.erase(0,found+1);
    found = dataN.find(",");
    string _nombrePages = dataN.substr(0,found);
    from_chars(_nombrePages.c_str(), _nombrePages.c_str() + _nombrePages.length(), nombrePages );
    dataN = dataN.erase(0,found+1);
    found = dataN.find(",");
    collection = dataN.substr(0,found);
    dataN = dataN.erase(0,found+1);
    found = dataN.find(",");
    resume = dataN.substr(0,found);
    dataN = dataN.erase(0,found+1);
    return dataN;
}

void Livre::saveMedia(ofstream& MonFlux){
    Media::saveMedia(MonFlux);
    MonFlux << date << endl;
    MonFlux << nombrePages << endl;
    MonFlux << collection << endl;
    MonFlux << resume << endl;
}

int Livre::searchMedia(std::string chaine) {
    Media::searchMedia(chaine);
    string _date = to_string(date);
    string _nombrePages = to_string(nombrePages);
    if ((chaine == collection) || (chaine == resume) || (chaine == _date) || (chaine == _nombrePages) ){
        return 1;
    }
}