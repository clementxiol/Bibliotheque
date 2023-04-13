
#include "DVD.h"
#include <charconv>

using namespace std;

DVD::DVD():VHS()
{
    nombrePistes = 0;
}

DVD::~DVD()
{
    VHS::~VHS();
}

void DVD::add2Media(int quantiteMedia){
    VHS::add2Media(quantiteMedia);
    type = "DVD";
    string _nombrePistes;
    cout<<"Combien de pistes je possede?"<<endl;
    getline(cin,_nombrePistes);
    from_chars(_nombrePistes.c_str(), _nombrePistes.c_str() + _nombrePistes.length(), nombrePistes);
}

void DVD::load2Media(int quantiteMedia, ifstream& infile) {
    VHS::load2Media(quantiteMedia, infile);
    string _nombrePistes;
    getline(infile,_nombrePistes);
    from_chars(_nombrePistes.c_str(), _nombrePistes.c_str() + _nombrePistes.length(), nombrePistes );
}

void DVD::add(std::string _type) {

}

void DVD::afficheMedia()
{
    VHS::afficheMedia();
    cout <<"Mon nombre de piste est" << nombrePistes << endl;
}

void DVD::saveMedia(ofstream& MonFlux){
    VHS::saveMedia(MonFlux);
    MonFlux << nombrePistes << endl;
}

int DVD::searchMedia(std::string chaine) {
    VHS::searchMedia(chaine);
    string _nombrePistes = to_string(nombrePistes);
    if((chaine == _nombrePistes)){
        return 1;
    }
}