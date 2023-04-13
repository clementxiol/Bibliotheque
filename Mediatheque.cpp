//
// Created by Xiol and Paris on 03/04/2023.
//
#include <algorithm>
#include "Mediatheque.h"
using namespace std;

Mediatheque::Mediatheque() {

}

Mediatheque::~Mediatheque() {

}

int Mediatheque::getID() {
    return ((int)listeMedia.size());
}


void Mediatheque::loadMedia(string filename) {
    const string fichier = filename.c_str();
    ifstream infile(fichier);
    string _type;
    string buffer;
    if (infile){
        getline(infile,buffer);
        while(!infile.eof()){
            getline(infile,_type);
            _type.erase(_type.find_last_not_of("\r\n") + 1);
            if(_type.compare("Livre")==0){
                Livre *L = new Livre();
                L->load2Media(((int)listeMedia.size()+1), infile);
                listeMedia.push_back(L);
                rechercheMedia.push_back(L);
            }
            if(_type.compare("CD")==0){
                CD *cd = new CD();
                cd->load2Media(((int)listeMedia.size()+1), infile);
                listeMedia.push_back(cd);
                rechercheMedia.push_back(cd);
            }
            if(_type.compare("Revue")==0){
                Revue *R = new Revue();
                R->load2Media(((int)listeMedia.size()+1), infile);
                listeMedia.push_back(R);
                rechercheMedia.push_back(R);
            }
            if(_type.compare("VHS")==0){
                VHS *vhs = new VHS();
                vhs->load2Media(((int)listeMedia.size()+1), infile);
                listeMedia.push_back(vhs);
                rechercheMedia.push_back(vhs);
            }
            if(_type.compare("DVD")==0){
                DVD *dvd = new DVD();
                dvd->load2Media(((int)listeMedia.size()+1), infile);
                listeMedia.push_back(dvd);
                rechercheMedia.push_back(dvd);
            }
            if(_type.compare("RessourceNumerique")==0){
                RessourceNumerique *rn = new RessourceNumerique();
                rn->load2Media(((int)listeMedia.size()+1), infile);
                listeMedia.push_back(rn);
                rechercheMedia.push_back(rn);
            }
        }
    }
    else
        cout << "Ne rentre pas" << endl;
}


void Mediatheque::add(string _type, string data){
    if (_type == "Livre"){
        Livre *L = new Livre();
        L->ecritureMedia(((int)listeMedia.size()+1),data);
        listeMedia.push_back(L);
        rechercheMedia.push_back(L);
    }

}

void Mediatheque::addMedia() {
    string _type;
    cout << "Quel est le type?"<< endl;
    getline(cin,_type);
    if(_type == "Livre"){
        Livre *L = new Livre();
        L->add2Media((int)listeMedia.size()+1);
        listeMedia.push_back(L);
        rechercheMedia.push_back(L);
    }
    if(_type.compare("CD")==0){
        CD *cd = new CD();
        cd->add2Media((int)listeMedia.size()+1);
        listeMedia.push_back(cd);
        rechercheMedia.push_back(cd);
    }
    if(_type.compare("Revue")==0){
        Revue *R = new Revue();
        R->add2Media((int)listeMedia.size()+1);
        listeMedia.push_back(R);
        rechercheMedia.push_back(R);
    }
    if(_type.compare("VHS")==0){
        VHS *vhs = new VHS();
        vhs->add2Media((int)listeMedia.size()+1);
        listeMedia.push_back(vhs);
        rechercheMedia.push_back(vhs);
    }
    if(_type.compare("DVD")==0){
        DVD *dvd = new DVD();
        dvd->add2Media((int)listeMedia.size()+1);
        listeMedia.push_back(dvd);
        rechercheMedia.push_back(dvd);
    }
    if(_type.compare("RessourceNumerique")==0){
        RessourceNumerique *rn = new RessourceNumerique();
        rn->add2Media((int)listeMedia.size()+1);
        listeMedia.push_back(rn);
        rechercheMedia.push_back(rn);
    }
    // Else pour gestion d'erreur sur la casse d'un media pour ex: "LIVRE" n'est pas un type valide donc resaisir le bon type avec la bonne casse

}

void Mediatheque::save(std::string filename) {
    const string fichier = filename.c_str();
    ofstream MonFlux(fichier);
    if(MonFlux) {
        MonFlux << "Buffer" << endl;
        for (int k = 0; k < listeMedia.size(); k++) {
            Media *M = listeMedia[k];
            M->saveMedia(MonFlux);
        }
        MonFlux.close();
    }
    else
        cout << "Impossible d'ouvrir le fichier" << endl;
}

void Mediatheque::show(int _ID) {
    Media* M = listeMedia[_ID-1];
    M->showMedia(_ID,M);
}

void Mediatheque::deleteID(int _ID) {
    listeMedia.erase(listeMedia.begin()+_ID-1);
    for (int i = _ID; i<(listeMedia.size()+1);i++){
        listeMedia[i-1]->Media::changeID(i); //ID -1
    }
}

void Mediatheque::bye() {
    for (int i = 0; i < (listeMedia.size()+1); i++) {
        delete listeMedia[i];
    }

    cout << "Merci d'avoir utilise notre application ! A bientot !" << endl;
}

void Mediatheque::searchM(std::string chaine) {
    for (int k = 0; k < rechercheMedia.size()+1; k++){
        if(!rechercheMedia[k]->searchMedia(chaine)){
            rechercheMedia.erase(rechercheMedia.begin()+k);
            k--;
        }
    }
}
