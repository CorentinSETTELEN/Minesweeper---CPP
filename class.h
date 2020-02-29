#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED
# include <iostream>
# include <string>
# include <stdlib.h>

using namespace std;

class Board
{
private :
    int LongueurBoard;
    int LargeurBoard;
    int BombNumber;
    int** array;
    string **arr;
    string **arra;
    bool Victoire;
    bool Defaite;
    int UserLong;
    int UserLarg;


public :
     Board();
     Board(int a, int b);

     set_LongueurBoard(int a);
     set_LargeurBoard(int b);
     set_BombNumer(int c);
     set_Array(int LongueurBoard, int LargeurBoard);
     set_Arr(int LongueurBoard, int LargeurBoard);
     set_Arra(int LongueurBoard, int LargeurBoard);

     CreationBoard();
     DisplayAffichage();
     DetectionMine();
     DemandeCase();
     AffichageNewBoard();
     TestVictoire();
     RechercheDeTiret(int UserLong, int UserLarg);
     RechercheDeTiretTable(int Longg, int Largg, int hautgauche, int haut, int hautdroite, int droite, int basdroite, int bas, int basgauche, int gauche);
     Deletememory();


     affichage()
{
    cout << "Voici la largeur : " << LargeurBoard << " Voici la longueur : " << LongueurBoard << endl;
}



};


#endif // CLASS_H_INCLUDED
