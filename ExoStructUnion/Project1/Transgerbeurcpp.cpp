#include <iostream>

using namespace std;


//declaration des union et enum
enum etat;
union contenu;


int main() {
    //declaration de variable/structure
    int px = 0;
    int py = 0;
    int poids = 0;
    char reference;
    float longueur;
    int num;
    struct palletteCasier { int poids; char reference; };
    struct rouleauCasier { float longueur; int num; };
    struct casier { enum etat; union contenu; };


	cout << "la triosieme fonction est le  TransGerbeur" << endl;

    int tabCasier[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // Création et initialisation d'un tableau de 5 entiers

// Affichage des valeurs du tableau
    for (int i = 0; i < 9; i++) {
        cout << tabCasier[i] << " ";
    }
    return 0;
}
