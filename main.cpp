#include <iostream>
#include "Mediatheque.h"
#include "Livre.h"
#include "CD.h"
#include "Media.h"
#include <vector>
using namespace std;
int main()
{
    string filename = "..\\Coucou.txt";
    Mediatheque MaBiblio;
    MaBiblio.loadMedia(filename); // un seul fichier contient toutes les données
    MaBiblio.listeMedia[0]->afficheMedia();
    MaBiblio.listeMedia[1]->afficheMedia();
    MaBiblio.addMedia();
    MaBiblio.deleteID(2);
    MaBiblio.show(1);
    MaBiblio.show(2);
    MaBiblio.show(3);
    MaBiblio.loadMedia("..\\Coucou.txt");
    MaBiblio.save("..\\Clement.txt");
    MaBiblio.bye();


    return 0;
}
