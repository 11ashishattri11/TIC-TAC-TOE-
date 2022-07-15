//TIC_TAC_TOE GAME(player against computer)
#include<random>
#include<iostream>
#include<time.h> 
using namespace std;

bool isavailable(char game1[], int c)
{
if(game1[c]=='F')
return true;
else 
return false;
}

int main()
{
srand(time(0));
//game matrix
char game[3][3];
int userR,userC,comR,comC;
//corresponding linear array
char game1[3*3] = {'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F', 'F'};
int i = 0, j = 0, c = 0;
cout<<"\nAvatar for user : O";
cout<<"\nAvatar for Computer : X\n";
for(int a = 0; a < 3*3; a++) {
    cout<<"\nChoose indices : ";
    //user inputs
    cin>>userR>>userC;
    cout<<"\nYour inputs are "<<userR<<","<<userC;
    //when computer chooses preoccupied value, it has to rechoose
    rechoose:
    //random values assigned to computer's row and col
    comC = rand()%3;
    comR = rand()%3;
    //if generated values are same as user, then rechoose
    if (comR == userR && comC == userC)
        goto rechoose;

    if (comR != userR || comC != userC) 
    {
        //to relate it to linear array
        c = comR * 3 + comC;                     //(row*3+column) is done to relate it to linear array.
        bool b1 = isavailable(game1, c);
        if (b1 == false) 
            goto rechoose;
            //if position is preoccupied, jump to rechoose
        else
        {
            cout<<"\nComputer inputs are " << comR << ","<< comC<<endl;
            for (i = 0; i < 3; i++) 
            {
                cout<<endl;

                for (j = 0; j < 3; j++) 
                {
                    if (i == comR && j == comC) {
                        game[i][j] = 'X';
                        game1[i * 3 + j] = game[i][j];
                    } else if (i == userR && j == userC) {
                            game[i][j] = 'O';
                            game1[i * 3 + j] = game[i][j];
                            } else if (game[i][j] != 'X' && game[i][j] != 'O')
                                game[i][j] = '_';

                    cout<<game[i][j] << " ";
                }
            }
            cout<<endl;
        }
    }
    //Winning Conditions
    if (
                    (game1[0] == 'X' && game1[0] == game1[1] && game1[0] == game1[2]) ||
                    (game1[0] == 'X' && game1[0] == game1[3] && game1[0] == game1[6]) ||
                    (game1[0] == 'X' && game1[0] == game1[4] && game1[0] == game1[8]) ||
                    (game1[1] == 'X' && game1[1] == game1[4] && game1[1] == game1[7]) ||
                    (game1[2] == 'X' && game1[2] == game1[5] && game1[2] == game1[8]) ||
                    (game1[2] == 'X' && game1[2] == game1[4] && game1[2] == game1[6]) ||
                    (game1[3] == 'X' && game1[3] == game1[4] && game1[3] == game1[5]) ||
                    (game1[6] == 'X' && game1[6] == game1[7] && game1[6] == game1[8])
    ) {
        cout<<"\nGGWP, Computer wins :(";
        break;
    } else if (
                    (game1[0] == 'O' && game1[0] == game1[1] && game1[0] == game1[2]) ||
                    (game1[0] == 'O' && game1[0] == game1[3] && game1[0] == game1[6]) ||
                    (game1[0] == 'O' && game1[0] == game1[4] && game1[0] == game1[8]) ||
                    (game1[1] == 'O' && game1[1] == game1[4] && game1[1] == game1[7]) ||
                    (game1[2] == 'O' && game1[2] == game1[5] && game1[2] == game1[8]) ||
                    (game1[2] == 'O' && game1[2] == game1[4] && game1[2] == game1[6]) ||
                    (game1[3] == 'O' && game1[3] == game1[4] && game1[3] == game1[5]) ||
                    (game1[6] == 'O' && game1[6] == game1[7] && game1[6] == game1[8])
            ) {
                cout<<"\nCongrats, you won :)";
                break;
            }
}
return 0;
}