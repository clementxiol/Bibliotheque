#ifndef DVD_H_INCLUDED
#define DVD_H_INCLUDED
#include <iostream>
#include <string>
#include "VHS.h"

using namespace std;

class DVD:public VHS{
protected :
    int nombrePistes;

public :
    DVD();
    virtual void add(string _type);
    virtual void load2Media(int quantiteMedia, ifstream& infile);
    virtual void add2Media(int quantiteMedia);
    virtual void afficheMedia();
    virtual void saveMedia(ofstream& MonFlux);
    virtual int searchMedia(string chaine);
    ~DVD();
};


#endif // DVD_H_INCLUDED
