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
    //MaBiblio.listeMedia[2]->afficheMedia();
    //MaBiblio.searchM("Livre");
    //MaBiblio.rechercheMedia[0]->afficheMedia();
    //MaBiblio.rechercheMedia[1]->afficheMedia();
    //MaBiblio.rechercheMedia[2]->afficheMedia();
    MaBiblio.addMedia();
    MaBiblio.deleteID(2);
    //MaBiblio.addMedia();
    MaBiblio.reloadMedia("..\\Coucou.txt");
    MaBiblio.show(1);
    MaBiblio.show(2);
    MaBiblio.show(3);
    MaBiblio.bye();
    //MaBiblio.loadMedia("C:\\Users\\Xiol\\CLionProjects\\new_biblio\\Jeje.txt");
    //MaBiblio.listeMedia[3]->afficheMedia();
    //MaBiblio.listeMedia[4]->afficheMedia();
    //MaBiblio.listeMedia[5]->afficheMedia();
    //MaBiblio.show(1);
    //MaBiblio.deleteID(1);
    //MaBiblio.listeMedia[0]->afficheMedia();
    //MaBiblio.show(1);
    //MaBiblio.show(2);
    //MaBiblio.show(3);
    //MaBiblio.bye();
    //MaBiblio.show(1);
    /*int i =0;
    while(i<3){
        MaBiblio.addMedia();
        MaBiblio.listeMedia[i]->afficheMedia();
        i++;
    }*/
    return 0;
}
