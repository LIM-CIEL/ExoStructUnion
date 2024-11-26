#include <iostream>

using namespace std;
/*

//declaration des union et enum
enum Eetat;
union Ucontenu;

struct Spallette{
        int poids;
        char reference;
    };

    struct Srouleau{
        float longueur;
        int num;
    };
   
    struct Scasier{
        enum Eetat;
        int px;
        int py;
    };

    struct UContenue {
        Spallette pallette;
        Srouleau rouleau;
    };

int main() {
    //declaration de variable/structure
    int px = 0;
    int py = 0;
    int poids = 0;
    char reference;
    float longueur;
    int num;

    Srouleau ro1;
    ro1.longueur = 10;
    ro1.num = 26845;

    Spallette pa1;
    pa1.poids = 40;
    strcpy_s(pa1.reference, "PalletteN1");



	cout << "la triosieme fonction est le  TransGerbeur" << endl;


    int tabCasier[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };  // Cr�ation et initialisation d'un tableau de 5 entiers

// Affichage des valeurs du tableau
    for (int i = 0; i < 9; i++) {
        cout << tabCasier[i] << " ";
    }
    return 0;
}
*/
#include <iostream>
#include <cstring> // Pour strcpy_s

using namespace std;

// �num�ration pour l'�tat du casier
enum EEtat {
    Vide,
    Palette,
    Rouleau
};

// Structure pour les coordonn�es
struct SCoordonnees {
    int x;
    int y;
};

// Structure pour une palette
struct SPalette {
    int poids;                // Poids de la palette
    char reference[20];       // R�f�rence (19 caract�res max + '\0')
};

// Structure pour un rouleau
struct SRouleau {
    float longueur;           // Longueur du rouleau
    int numero;               // Num�ro de s�rie
};

// Union pour le contenu d'un casier
union UContenu {
    SPalette palette;
    SRouleau rouleau;
};

// Structure pour un casier
struct SCasier {
    SCoordonnees coordonnees; // Coordonn�es x et y
    EEtat etat;               // �tat du contenu
    UContenu contenu;         // Contenu (palette ou rouleau)
};

int main() {
    // D�claration et initialisation d'un rouleau
    SRouleau ro1 = { 10.5f, 12345 };

    // D�claration d'une palette et affectation des valeurs
    SPalette pa1;
    pa1.poids = 50;
    strcpy_s(pa1.reference, "REF-PALETTE-001");

    // D�claration et initialisation d'un �tat
    EEtat etatC1 = Vide;

    // D�claration et initialisation d'un contenu avec une palette
    UContenu cont;
    cont.palette = pa1;

    // D�claration d'un casier et affectation des valeurs
    SCasier c1;
    c1.coordonnees = { 2, 3 };
    c1.etat = Palette;
    c1.contenu.palette = pa1;

    // D�claration d'un second casier initialis� avec un rouleau
    SCasier c2 = { {4, 5}, Rouleau, {.rouleau = ro1} };

    // Tableau de casiers
    SCasier tabCasier[9] = {};
    tabCasier[0] = c1;
    tabCasier[2] = c2;

    // Affichage des tailles des �l�ments avec sizeof()
    cout << "Taille de SCoordonnees : " << sizeof(SCoordonnees) << " octets" << endl;
    cout << "Taille de SPalette : " << sizeof(SPalette) << " octets" << endl;
    cout << "Taille de SRouleau : " << sizeof(SRouleau) << " octets" << endl;
    cout << "Taille de UContenu : " << sizeof(UContenu) << " octets" << endl;
    cout << "Taille de SCasier : " << sizeof(SCasier) << " octets" << endl;
    cout << "Taille du tableau de casiers : " << sizeof(tabCasier) << " octets" << endl;

    // Affichage des informations des casiers
    cout << "\nCasier 1 : (" << c1.coordonnees.x << ", " << c1.coordonnees.y << "), �tat: " << c1.etat
        << ", R�f�rence Palette: " << c1.contenu.palette.reference << endl;

    cout << "Casier 2 : (" << c2.coordonnees.x << ", " << c2.coordonnees.y << "), �tat: " << c2.etat
        << ", Num�ro Rouleau: " << c2.contenu.rouleau.numero << endl;

    return 0;
}
