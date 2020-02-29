# include "class.h"
# include <iostream>
# include <string>
# include <stdlib.h>

using namespace std;

int main()
{
    int Long;
    int Larg;
    int Bomb;

    do{
    cout << "Rentrer une longueur" << endl;
    cin >> Long;
    }while(Long <= 0 || Long > 100);

    do{
    cout << "Rentrer une largeur" << endl;
    cin >> Larg;
    }while(Larg <= 0 || Larg > 100);

    do{
    cout << "Rentrer un Nbre de bombe" << endl;
    cin >> Bomb;
    }while(Bomb > (Long * Larg) || Bomb <= 0);

    Board a(Long,Larg);
    a.affichage();
    a.set_BombNumer(Bomb);
    a.CreationBoard();
    a.DemandeCase();
    a.Deletememory();

    cin >> Bomb;
    return 0;
}

