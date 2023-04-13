
#ifndef LIVRE_H_INCLUDED
#define LIVRE_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include "Media.h"
using namespace std;

class Livre:public Media{
private :
    int date;
    int nombrePages;
    std::string collection;
    std::string resume;

public :
    Livre();
    ~Livre();
    Livre(string,string,int,string,int,int,string,string);
    virtual void getResume(std::string const);
    virtual void load2Media(int quantiteMedia, std::ifstream& infile);
    virtual void afficheMedia();
    virtual string ecritureMedia(int quantiteMedia, std::string data);
    virtual void add2Media(int quantiteMedia);
    virtual void saveMedia(ofstream& MonFlux);
    virtual int searchMedia(string chaine);
};


#endif // LIVRE_H_INCLUDED
