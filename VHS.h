
#ifndef VHS_H_INCLUDED
#define VHS_H_INCLUDED
#include <iostream>
#include <string>
#include "Media.h"

using namespace std;

class VHS:public Media{
protected :
    std::string maisonProduction;
    int duree;

public :
    VHS();
    virtual void load2Media(int quantiteMedia,ifstream& infile);
    virtual void addMedia(string _type);
    virtual void add2Media(int quantiteMedia);
    virtual void afficheMedia();
    virtual void saveMedia(ofstream& MonFlux);
    virtual int searchMedia(string chaine);
    ~VHS();
};


#endif // VHS_H_INCLUDED
