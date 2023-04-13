#ifndef MEDIATHQUE_H_INCLUDED
#define MEDIATHQUE_H_INCLUDED
#include <iostream>
#include <string>
#include <vector>
#include "Media.h"
#include "Livre.h"
#include "Revue.h"
#include "RessourceNumerique.h"
#include "VHS.h"
#include "DVD.h"
#include "CD.h"
#include <fstream>
#include <sstream>

using namespace std;

class Mediatheque{

public :
    std::vector<Media*> listeMedia;
    std::vector<Media*> rechercheMedia;

public :
    Mediatheque();
    ~Mediatheque();
    void add(string _type, string data);
    void loadMedia(string filename); // un fichier contient toutes les données
    int getID();
    void save(string filename); // on stock les données dans un fichier
    void searchM(string chaine); // on recherche les chaines de caractères
    void listM();
    void clearM();
    void show(int _ID);
    void deleteID(int _ID);
    void reset();
    void bye();
    void addMedia();
    void reloadMedia(string filename);
};


#endif // MEDIATHQUE_H_INCLUDED
