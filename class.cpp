# include "class.h"
# include <iostream>
# include <string>
# include <stdlib.h>

using namespace std;


Board::Board()
{
    LongueurBoard = 0;
    LargeurBoard = 0;
    BombNumber = 0;
    Victoire = false;
    Defaite = false;
}

Board::Board(int a, int b):LongueurBoard(a), LargeurBoard(b)
{
    set_Array(LongueurBoard, LargeurBoard);
    set_Arr(LongueurBoard, LargeurBoard);
    set_Arra(LongueurBoard, LargeurBoard);

    BombNumber = 0;
    Victoire = false;
    Defaite = false;

}

Board::set_LongueurBoard(int a)
{
    LongueurBoard = a ;

}

Board::set_LargeurBoard(int b)
{
    LargeurBoard = b ;

}

Board::set_BombNumer(int c)
{
    BombNumber = c;
}

Board::set_Array(int LongueurBoard, int LargeurBoard)
{
    array = new int*[LongueurBoard];
    for(unsigned i=0; i < LongueurBoard; i++)
        array[i] = new int[LargeurBoard];
}

Board::set_Arr(int LongueurBoard, int LargeurBoard)
{
    arr = new string*[LongueurBoard];
    for(unsigned i=0; i < LongueurBoard; i++)
        arr[i] = new string[LargeurBoard];
}

Board::set_Arra(int LongueurBoard, int LargeurBoard)
{
    arra = new string*[LongueurBoard];
    for(unsigned i=0; i < LongueurBoard; i++)
        arra[i] = new string[LargeurBoard];
}

Board::CreationBoard()
{
    int x;
    int CompteurBomb = 0;

    int RandomLong;
    int RandomLarg;

    for (int x = 0; x < LongueurBoard; x++) { // Creaton du board
		for (int y = 0; y < LargeurBoard; y++)
			array[x][y] = 0;
		}

    for (int g = 0; g < LongueurBoard; g++) { // Creaton du board
		for (int h = 0; h < LargeurBoard; h++)
			arr[g][h] = " ";
		}

    for (int g = 0; g < LongueurBoard; g++) { // Creaton du board
		for (int h = 0; h < LargeurBoard; h++)
			arra[g][h] = "0";
		}

    do{
    RandomLong = rand() % LongueurBoard;
    RandomLarg = rand() % LargeurBoard;

    if(array[RandomLong][RandomLarg] == 1){

    }else{
        array[RandomLong][RandomLarg] = 1;
        CompteurBomb++;
    }

    }while(CompteurBomb < BombNumber);

    for (int i = 0; i < LongueurBoard; i++)
	{
		for (int j = 0; j < LargeurBoard; ++j)
		{
		    cout << "[   ]";
		}
        cout << '\n';
	}

    DetectionMine();
}

Board::DisplayAffichage()
{
    for (int i = 0; i < LongueurBoard; i++)
	{
		for (int j = 0; j < LargeurBoard; ++j)
		{
		    cout << "[ ";
		    switch(array[i][j])
		    {
                case 10: // Aucune Bombe Autour
                    cout << "-";
                    break;
                case 11: // 1
                    cout << "1";
                    break;
                case 12: // 2
                    cout << "2";
                    break;
                case 13: // 3
                    cout << "3";
                    break;
                case 14: // 4
                    cout << "4";
                    break;
                case 15: // 5
                    cout << "5";
                    break;
                case 16: // 6
                    cout << "6";
                    break;
                case 17: // 7
                    cout << "7";
                    break;
                case 18: // 8
                    cout << "8";
                    break;
                case 0:
                case 1:
                    cout << "X"; // Initialise le tableau
            }

            cout << " ]";


		}
        cout << '\n';
	}

}

Board::DetectionMine()
{

    for (int i = 0; i < LongueurBoard; i++)
	{
		for (int j = 0; j < LargeurBoard; j++)
		{
		    int BombeAutour = 0;
		    if(array[i][j] == 1) // 1 : Bombe
            {

            }

            else
            {
                if((i == 0) && (j == 0)){ // -- Angle Haut Gauche --
                    if(array[i+1][j] == 1)//Droite
                      BombeAutour++;
                    if(array[i][j+1] == 1)//Bas
                      BombeAutour++;
                    if(array[i+1][j+1] == 1)//BasDroite
                      BombeAutour++;
                }

                else if((i == (LongueurBoard - 1)) && (j == 0)){ // -- Angle Haut Droite --
                    if(array[i-1][j] == 1)//Gauche
                      BombeAutour++;
                    if(array[i][j+1] == 1)//Bas
                      BombeAutour++;
                    if(array[i-1][j+1] == 1)//BasGauche
                      BombeAutour++;
                }

                else if((i == (LongueurBoard - 1)) && (j == (LargeurBoard - 1))){ // -- Angle Bas Droite --
                    if(array[i-1][j] == 1)//Gauche
                      BombeAutour++;
                    if(array[i][j-1] == 1)//Haut
                      BombeAutour++;
                    if(array[i-1][j-1] == 1)//HautGauche
                      BombeAutour++;
                }

                else if((i == 0 ) && (j == (LargeurBoard - 1))){ // -- Angle Bas Gauche --
                    if(array[i+1][j] == 1)//Droite
                      BombeAutour++;
                    if(array[i][j-1] == 1)//Haut
                      BombeAutour++;
                    if(array[i+1][j-1] == 1)//HautDroite
                      BombeAutour++;
                }


                else if(j == 0){ // -- Coté Haut --
                    if(array[i+1][j] == 1)//Droite
                      BombeAutour++;
                    if(array[i][j+1] == 1)//Bas
                      BombeAutour++;
                    if(array[i-1][j] == 1)//Gauche
                      BombeAutour++;
                    if(array[i+1][j+1] == 1)//BasDroite
                      BombeAutour++;
                    if(array[i-1][j+1] == 1)//BasGauche
                      BombeAutour++;
                }

                else if(i == 0){ // -- Coté Gauche --
                    if(array[i+1][j] == 1)//Droite
                      BombeAutour++;
                    if(array[i][j+1] == 1)//Bas
                      BombeAutour++;
                    if(array[i][j-1] == 1)//Haut
                      BombeAutour++;
                    if(array[i+1][j+1] == 1)//BasDroite
                      BombeAutour++;
                    if(array[i+1][j-1] == 1)//HautDroite
                      BombeAutour++;
                }



                 else if(i == (LongueurBoard - 1)){ // -- Coté Droit --i == (LongueurBoard - 1)
                    if(array[i-1][j] == 1)//Gauche
                      BombeAutour++;
                    if(array[i][j-1] == 1)//Haut
                      BombeAutour++;
                    if(array[i][j+1] == 1)//Bas
                      BombeAutour++;
                    if(array[i-1][j+1] == 1)//BasGauche
                      BombeAutour++;
                    if(array[i-1][j-1] == 1)//HautGauche
                      BombeAutour++;
                }



                else if(j == (LargeurBoard - 1)){ // Cote Bas
                    if(array[i+1][j] == 1)//Droite
                      BombeAutour++;
                    if(array[i][j-1] == 1)//Haut
                      BombeAutour++;
                    if(array[i-1][j] == 1)//Gauche
                      BombeAutour++;
                    if(array[i+1][j-1] == 1)//HautDroite
                      BombeAutour++;
                    if(array[i-1][j-1] == 1)//HautGauche
                      BombeAutour++;
                }

                else//CaseNormale
                {
                    if(array[i+1][j] == 1)//Droite
                      BombeAutour++;
                    if(array[i][j+1] == 1)//Bas
                      BombeAutour++;
                    if(array[i-1][j] == 1)//Gauche
                      BombeAutour++;
                    if(array[i][j-1] == 1)//Haut
                      BombeAutour++;
                    if(array[i+1][j-1] == 1)//DroitHaut
                      BombeAutour++;
                    if(array[i+1][j+1] == 1)//DroitBas
                      BombeAutour++;
                    if(array[i-1][j-1] == 1)//GaucheHaut
                      BombeAutour++;
                    if(array[i-1][j+1] == 1)//GaucheBas
                      BombeAutour++;

                }

                switch(BombeAutour)
                {
                case 0:
                    array[i][j] = 10;
                    break;
                case 1:
                    array[i][j] = 11;
                    break;
                case 2:
                    array[i][j] = 12;
                    break;
                case 3:
                    array[i][j] = 13;
                    break;
                case 4:
                    array[i][j] = 14;
                    break;
                case 5:
                    array[i][j] = 15;
                    break;
                case 6:
                    array[i][j] = 16;
                    break;
                case 7:
                    array[i][j] = 17;
                    break;
                case 8:
                    array[i][j] = 18;
                    break;
                }
            }
        }
    }
}

Board::DemandeCase()
{
    do{

        cout << "Indicate the next bot without mine" << endl;
        do{
            cout << "Column number [0-" << LongueurBoard - 1  << "] ?" << endl;
            cin >> UserLong;
           }
        while(UserLong < 0 || UserLong > (LongueurBoard - 1));

        do{
            cout << "Line number [0-" << LargeurBoard - 1 << "] ?" << endl;
            cin >> UserLarg;
         }
        while(UserLarg < 0 || UserLarg > (LargeurBoard - 1));
        cout << "Voici les coords du pion : [" << UserLong << "-" << UserLarg << "]" << endl;

        int ValuePoint;
        ValuePoint = array[UserLong][UserLarg];
        string ValeurToArray = "";
        switch(ValuePoint){
            case 1 :
                ValeurToArray = "X";
                Defaite = true;
                break;
            case 10 :
                ValeurToArray = "-";
                arr[UserLong][UserLarg] = ValeurToArray;
                RechercheDeTiret(UserLong, UserLarg);
                AffichageNewBoard();
                break;
            case 11 :
                ValeurToArray = "1";
                arr[UserLong][UserLarg] = ValeurToArray;
                AffichageNewBoard();
                break;
            case 12 :
                ValeurToArray = "2";
                arr[UserLong][UserLarg] = ValeurToArray;
                AffichageNewBoard();
                break;
            case 13 :
                ValeurToArray = "3";
                arr[UserLong][UserLarg] = ValeurToArray;
                AffichageNewBoard();
                break;
            case 14 :
                ValeurToArray = "4";
                arr[UserLong][UserLarg] = ValeurToArray;
                AffichageNewBoard();
                break;
            case 15 :
                ValeurToArray = "5";
                arr[UserLong][UserLarg] = ValeurToArray;
                AffichageNewBoard();
                break;
            case 16 :
                ValeurToArray = "6";
                arr[UserLong][UserLarg] = ValeurToArray;
                AffichageNewBoard();
                break;
            case 17 :
                ValeurToArray = "7";
                arr[UserLong][UserLarg] = ValeurToArray;
                AffichageNewBoard();
                break;
            case 18:
                ValeurToArray = "8";
                arr[UserLong][UserLarg] = ValeurToArray;
                AffichageNewBoard();
                break;
            default:
                ValeurToArray = "Bug";
                break;
        }

        TestVictoire();

    }while(!Defaite && !Victoire);

    if(Victoire)
    {
        cout << "-----  Bravo vous avez gagne ! -----" << endl;
        cout << "Voici la solution : " << endl;

    }
    if(Defaite)
    {
        cout << "----- Dommage vous avez perdu -----" << endl;
        cout << "Voici la solution : " << endl;
    }

    DisplayAffichage();
}

Board::AffichageNewBoard()
{
    for (int i = 0; i < LongueurBoard; i++)
        {
            for (int j = 0; j < LargeurBoard; ++j)
            {
                cout << "[ " << arr[j][i]<< " ]";
            }
        cout << '\n';
		}

}


 Board::RechercheDeTiret(int Largg, int Longg)
{
    if(arra[Longg][Largg] == "1")
    {

    }else{

        arra[Longg][Largg] = "1";


        if((Longg == 0)&&(Largg == 0)) //Angle Haut gauche
        {
            if(array[Longg + 1][Largg] == 10) // droite
            {
                arr[Longg + 1][Largg] = "-";
                RechercheDeTiret( Longg + 1, Largg);
            }

            if(array[Longg + 1][Largg + 1] == 10) // basdroite
            {
                arr[Longg + 1][Largg + 1] = "-";
                RechercheDeTiret( Longg + 1, Largg + 1);
            }

            if(array[Longg][Largg + 1] == 10) // bas
            {
                arr[Longg][Largg + 1] = "-";
                RechercheDeTiret( Longg, Largg + 1);
            }
        }

        else if((Longg == (LongueurBoard - 1))&&(Largg == 0)) // Angle Haut droite
        {
            if(array[Longg][Largg + 1] == 10) // bas
            {
                arr[Longg][Largg + 1] = "-";
                RechercheDeTiret( Longg, Largg + 1);
            }


            if(array[Longg - 1][Largg + 1] == 10) // basgauche
            {
                arr[Longg - 1][Largg + 1] = "-";
                RechercheDeTiret( Longg - 1, Largg + 1);
            }

            if(array[Longg - 1][Largg] == 10) // gauche
            {
                arr[Longg - 1][Largg] = "-";
                RechercheDeTiret( Longg - 1, Largg);
            }
        }

        else if((Longg == (LongueurBoard - 1))&& (Largg == (LargeurBoard - 1 ))) // Angle Bas droite
        {
            if(array[Longg - 1][Largg - 1] == 10) // hautgauche
            {
                arr[Longg - 1][Largg - 1] = "-";
                RechercheDeTiret(Longg - 1, Largg - 1);
            }
            if(array[Longg][Largg - 1] == 10) // haut
            {
                arr[Longg][Largg - 1] = "-";
                RechercheDeTiret(Longg, Largg - 1);
            }

            if(array[Longg - 1][Largg] == 10) // gauche
            {
                arr[Longg - 1][Largg] = "-";
                RechercheDeTiret( Longg - 1, Largg);
            }
        }

        else if((Longg == 0) && (Largg == (LargeurBoard - 1 ))) // Angle Bas gauche
        {

            if(array[Longg][Largg - 1] == 10) // haut
            {
                arr[Longg][Largg - 1] = "-";
                RechercheDeTiret(Longg, Largg - 1);
            }

            if(array[Longg + 1][Largg - 1] == 10) // hautdroite
            {
                arr[Longg + 1][Largg - 1] = "-";
                RechercheDeTiret( Longg + 1, Largg - 1);
            }

            if(array[Longg + 1][Largg] == 10) // droite
            {
                arr[Longg + 1][Largg] = "-";
                RechercheDeTiret( Longg + 1, Largg);
            }
        }

        else if(Largg == 0) // Haut
        {

            if(array[Longg + 1][Largg] == 10) // droite
            {
                arr[Longg + 1][Largg] = "-";
                RechercheDeTiret( Longg + 1, Largg);
            }
            if(array[Longg + 1][Largg + 1] == 10) // basdroite
            {
                arr[Longg + 1][Largg + 1] = "-";
                RechercheDeTiret( Longg + 1, Largg + 1);
            }

            if(array[Longg][Largg + 1] == 10) // bas
            {
                arr[Longg][Largg + 1] = "-";
                RechercheDeTiret( Longg, Largg + 1);
            }

            if(array[Longg - 1][Largg + 1] == 10) // basgauche
            {
                arr[Longg - 1][Largg + 1] = "-";
                RechercheDeTiret( Longg - 1, Largg + 1);
            }

            if(array[Longg - 1][Largg] == 10) // gauche
            {
                arr[Longg - 1][Largg] = "-";
                RechercheDeTiret( Longg - 1, Largg);
            }
        }

        else if(Longg == 0) // Gauche
        {
            if(array[Longg][Largg - 1] == 10) // haut
            {
                arr[Longg][Largg - 1] = "-";
                RechercheDeTiret(Longg, Largg - 1);
            }

            if(array[Longg + 1][Largg - 1] == 10) // hautdroite
            {
                arr[Longg + 1][Largg - 1] = "-";
                RechercheDeTiret( Longg + 1, Largg - 1);
            }
            if(array[Longg + 1][Largg] == 10) // droite
            {
                arr[Longg + 1][Largg] = "-";
                RechercheDeTiret( Longg + 1, Largg);
            }
            if(array[Longg + 1][Largg + 1] == 10) // basdroite
            {
                arr[Longg + 1][Largg + 1] = "-";
                RechercheDeTiret( Longg + 1, Largg + 1);
            }

            if(array[Longg][Largg + 1] == 10) // bas
            {
                arr[Longg][Largg + 1] = "-";
                RechercheDeTiret( Longg, Largg + 1);
            }
        }

        else if(Longg == (LongueurBoard - 1)) // Droit
        {

            if(array[Longg - 1][Largg - 1] == 10) // hautgauche
            {
                arr[Longg - 1][Largg - 1] = "-";
                RechercheDeTiret(Longg - 1, Largg - 1);
            }

            if(array[Longg][Largg - 1] == 10) // haut
            {
                arr[Longg][Largg - 1] = "-";
                RechercheDeTiret(Longg, Largg - 1);
            }
            if(array[Longg][Largg + 1] == 10) // bas
            {
                arr[Longg][Largg + 1] = "-";
                RechercheDeTiret( Longg, Largg + 1);
            }

            if(array[Longg - 1][Largg + 1] == 10) // basgauche
            {
                arr[Longg - 1][Largg + 1] = "-";
                RechercheDeTiret( Longg - 1, Largg + 1);
            }

            if(array[Longg - 1][Largg] == 10) // gauche
            {
                arr[Longg - 1][Largg] = "-";
                RechercheDeTiret( Longg - 1, Largg);
            }
        }
        else if(Largg == (LargeurBoard - 1)) // Bas
        {
            if(array[Longg - 1][Largg - 1] == 10) // hautgauche
            {
                arr[Longg - 1][Largg - 1] = "-";
                RechercheDeTiret(Longg - 1, Largg - 1);
            }

            if(array[Longg][Largg - 1] == 10) // haut
            {
                arr[Longg][Largg - 1] = "-";
                RechercheDeTiret(Longg, Largg - 1);
            }

            if(array[Longg + 1][Largg - 1] == 10) // hautdroite
            {
                arr[Longg + 1][Largg - 1] = "-";
                RechercheDeTiret( Longg + 1, Largg - 1);
            }
            if(array[Longg + 1][Largg] == 10) // droite
            {
                arr[Longg + 1][Largg] = "-";
                RechercheDeTiret( Longg + 1, Largg);
            }
            if(array[Longg - 1][Largg] == 10) // gauche
            {
                arr[Longg - 1][Largg] = "-";
                RechercheDeTiret( Longg - 1, Largg);
            }
        }
        else // Pion normal
        {
            if(array[Longg - 1][Largg - 1] == 10) // hautgauche
            {
                arr[Longg - 1][Largg - 1] = "-";
                RechercheDeTiret(Longg - 1, Largg - 1);
            }

            if(array[Longg][Largg - 1] == 10) // haut
            {
                arr[Longg][Largg - 1] = "-";
                RechercheDeTiret(Longg, Largg - 1);
            }

            if(array[Longg + 1][Largg - 1] == 10) // hautdroite
            {
                arr[Longg + 1][Largg - 1] = "-";
                RechercheDeTiret( Longg + 1, Largg - 1);
            }
            if(array[Longg + 1][Largg] == 10) // droite
            {
                arr[Longg + 1][Largg] = "-";
                RechercheDeTiret( Longg + 1, Largg);
            }

            if(array[Longg + 1][Largg + 1] == 10) // basdroite
            {
                arr[Longg + 1][Largg + 1] = "-";
                RechercheDeTiret( Longg + 1, Largg + 1);
            }
            if(array[Longg][Largg + 1] == 10) // bas
            {
                arr[Longg][Largg + 1] = "-";
                RechercheDeTiret( Longg, Largg + 1);
            }

            if(array[Longg - 1][Largg + 1] == 10) // basgauche
            {
                arr[Longg - 1][Largg + 1] = "-";
                RechercheDeTiret( Longg - 1, Largg + 1);
            }

            if(array[Longg - 1][Largg] == 10) // gauche
            {
                arr[Longg - 1][Largg] = "-";
                RechercheDeTiret( Longg - 1, Largg);
            }
        }
    }
}


/*Board::RechercheDeTiretTable(int Longg, int Largg   , int hautgauche, int haut, int hautdroite, int droite, int basdroite, int bas, int basgauche, int gauche)
{
    if(hautgauche == 1){
        if(array[Longg - 1][Largg - 1] == 10) // hautgauche
        {
            arr[Longg - 1][Largg - 1] = "-";
            RechercheDeTiret(Longg - 1, Largg - 1);
        }
    }

    if(haut == 1){
        if(array[Longg][Largg - 1] == 10) // haut
        {
            arr[Longg][Largg - 1] = "-";
            RechercheDeTiret(Longg, Largg - 1);
        }
    }

    if(hautdroite == 1){
        if(array[Longg + 1][Largg - 1] == 10) // hautdroite
        {
            arr[Longg + 1][Largg - 1] = "-";
            RechercheDeTiret( Longg + 1, Largg - 1);
        }
    }

    if(droite == 1){
        if(array[Longg + 1][Largg] == 10) // droite
        {
            arr[Longg + 1][Largg] = "-";
            RechercheDeTiret( Longg + 1, Largg);
        }
    }

    if(basdroite == 1){
        if(array[Longg + 1][Largg + 1] == 10) // basdroite
        {
            arr[Longg + 1][Largg + 1] = "-";
            RechercheDeTiret( Longg + 1, Largg + 1);
        }
    }

    if(bas == 1){
        if(array[Longg][Largg + 1] == 10) // bas
        {
            arr[Longg][Largg + 1] = "-";
            RechercheDeTiret( Longg, Largg + 1);
        }
    }

    if(basgauche == 1){
        if(array[Longg - 1][Largg + 1] == 10) // basgauche
        {
            arr[Longg - 1][Largg + 1] = "-";
            RechercheDeTiret( Longg - 1, Largg + 1);
        }
    }

    if(gauche == 1){
        if(array[Longg - 1][Largg] == 10) // gauche
        {
            arr[Longg - 1][Largg] = "-";
            RechercheDeTiret( Longg - 1, Largg);
        }
    }
}*/


Board::TestVictoire()
{
    int CaseVide;
    CaseVide = LongueurBoard * LargeurBoard; // 5 * 5 / abc = 25
    for (int i = 0; i < LongueurBoard; i++)
        {
            for (int j = 0; j < LargeurBoard; ++j)
            {
                if((arr[j][i]) != " ")
                {
                    CaseVide--; // abc vide = 3
                    if(CaseVide == BombNumber)
                        Victoire = true;
                }

            }
		}
}
Board::Deletememory()
{
    for(int i; i < LongueurBoard; i++)
        delete[]array[i];
    delete[] array;
}
