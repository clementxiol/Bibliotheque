#ifndef MEDIA_H_INCLUDED
#define MEDIA_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Media{

protected :
    std::string auteur;
    std::string titre;
    int ID;
    std::string type;

public :
    Media();
    Media(string , string , int , string );
    virtual void load2Media(int quantiteMedia, std::ifstream& infile);
    virtual void add2Media(int quantiteMedia);
    virtual void saveMedia(std::ofstream& MonFlux);
    virtual int searchMedia(std::string chaine);
    virtual void showMedia(int _ID, Media* M);
    virtual void deleteMedia(int);
    virtual void afficheMedia();
    virtual string ecritureMedia(int quantiteMedia, std::string data);
    virtual void changeID(int i);
    ~Media();
};

#endif // MEDIA_H_INCLUDED
