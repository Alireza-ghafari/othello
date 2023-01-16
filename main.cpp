#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// print game :
void print(char arr[8][8])
{
    int k = 1 ;
    for(int i=0 ; i<8 ; i++)
    {
        for (int j=0 ; j<8 ; j++)
        {
            if (i==0 && j==0)
            {
                for (int y=1 ; y<9 ; y++)
                {
                    if(y==1)
                        cout << "   " ;
                    cout << "  " << y << "  " ;
                }
                cout << endl ;
                cout << endl ;
            }
            if(i==0 && j==0)
                cout << " " << k << " " ;
            if(i>0 && j==0 )
                cout << " " << k << " " ;
            cout << "  " << arr [i][j] << "  " ;
        }
        k++ ;
        cout << endl ;
        cout << endl ;
    }
}

// correct place :
int positionn(char color , char arr[8][8] , int place[65])
{
    int x=0;
    for (int i=0 ; i<65 ; i++)
        place[i]=99;

    bool position = false ;
    for(int i = 0 ; i<8 ; i++)
        for(int j = 0 ; j<8 ; j++)
            if(arr[i][j] == color)
            {

                // right
                position = false ;
                for(int l = 1 ; l+j<8 ; l++)
                {
                    if (arr[i][j+l]=='-')
                    {
                        if (position==true)
                        {
                            place [x] = i+1 ;
                            place [x+1] = j+l+1 ;
                            position = false ;
                            x+=2;
                        }
                        else
                            continue ;
                    }
                    else if (arr[i][j+l]!='-' && arr[i][j+l]!=color)
                    {
                        position = true ;
                        continue ;
                    }
                    else if (arr[i][j+l]==color)
                        break;
                    position=false;
                }

                // top
                position = false ;
                for(int l = 1 ; i-l >=0 ; l++)
                {
                    if (arr[i-l][j]=='-')
                    {
                        if (position==true)
                        {
                            place [x] = i-l+1 ;
                            place [x+1] = j+1 ;
                            position = false ;
                            x+=2;
                        }
                        else
                            continue ;
                    }
                    else if (arr[i-l][j]!='-' && arr[i-l][j]!=color)
                    {
                        position = true ;
                        continue ;
                    }
                    else if (arr[i-l][j]==color)
                        break;
                    position=false;
                }

                // left
                position = false ;
                for(int l = 1 ; j-l >=0 ; l++)
                {
                    if (arr[i][j-l]=='-')
                    {
                        if (position==true)
                        {
                            place [x] = i+1 ;
                            place [x+1] = j-l+1 ;
                            position = false ;
                            x+=2;
                        }
                        else
                            continue ;
                    }
                    else if (arr[i][j-l]!='-' && arr[i][j-l]!=color)
                    {
                        position = true ;
                        continue ;
                    }
                    else if (arr[i][j-l]==color)
                        break;
                    position=false;
                }

                // down
                position = false ;
                for(int l = 1 ; l+i<8 ; l++)
                {
                    if (arr[i+l][j]=='-')
                    {
                        if (position==true)
                        {
                            place [x] = i+l+1 ;
                            place [x+1] = j+1 ;
                            position = false ;
                            x+=2;
                        }
                        else
                            continue ;
                    }
                    else if (arr[i+l][j]!='-' && arr[i+l][j]!=color)
                    {
                        position = true ;
                        continue ;
                    }
                    else if (arr[i+l][j]==color)
                        break;
                    position=false;
                }

                // top - right
                position = false ;
                for(int l = 1 , p = 1 ; l+j<8 && i-p>=0 ; l++,p++)
                {
                    if (arr[i-p][j+l]=='-')
                    {
                        if (position==true)
                        {
                            place [x] = i-p+1 ;
                            place [x+1] = j+l+1 ;
                            position = false ;
                            x+=2;
                        }
                        else
                            continue ;
                    }
                    else if (arr[i-p][j+l]!='-' && arr[i-p][j+l]!=color)
                    {
                        position = true ;
                        continue ;
                    }
                    else if (arr[i-p][j+l]==color)
                        break;
                    position=false;
                }

                // top - left
                position = false ;
                for(int l = 1 , p = 1 ; j-l >0 && i-p>=0 ; l++,p++)
                {
                    if (arr[i-p][j-l]=='-')
                    {
                        if (position==true)
                        {
                            place [x] = i-p+1 ;
                            place [x+1] = j-l+1 ;
                            position = false ;
                            x+=2;
                        }
                        else
                            continue ;
                    }
                    else if (arr[i-p][j-l]!='-' && arr[i-p][j-l]!=color)
                    {
                        position = true ;
                        continue ;
                    }
                    else if (arr[i-p][j-l]==color)
                        break;
                    position=false;
                }

                // down - right
                position = false ;
                for(int l = 1 , p = 1 ; l+j<8 && p+i<8 ; l++,p++)
                {
                    if (arr[i+p][j+l]=='-')
                    {
                        if (position==true)
                        {
                            place [x] = i+p+1 ;
                            place [x+1] = j+l+1 ;
                            position = false ;
                            x+=2;
                        }
                        else
                            continue ;
                    }
                    else if (arr[i+p][j+l]!='-' && arr[i+p][j+l]!=color)
                    {
                        position = true ;
                        continue ;
                    }
                    else if (arr[i+p][j+l]==color)
                        break;
                    position=false;
                }

                // down - left
                position = false ;
                for(int l = 1 , p = 1 ; j-l >=0 && p+i<8 ; l++,p++)
                {
                    if (arr[i+p][j-l]=='-')
                    {
                        if (position==true)
                        {
                            place [x] = i+p+1 ;
                            place [x+1] = j-l+1 ;
                            position = false ;
                            x+=2;
                        }
                        else
                            continue ;
                    }
                    else if (arr[i+p][j-l]!='-' && arr[i+p][j-l]!=color)
                    {
                        position = true ;
                        continue ;
                    }
                    else if (arr[i+p][j-l]==color)
                        break;
                    position=false;
                }

            }
    return x;
}


// change coins :
void changecoins(int inputarr[1][2] ,char spacearr [8][8] ,char color)
{
    inputarr[0][0]-- ;
    inputarr[0][1]-- ;

    // right :
    if ( spacearr[inputarr[0][0]][inputarr[0][1]+1] != color && spacearr[inputarr[0][0]][inputarr[0][1]+1] != '-' )
        for ( int x = 2 ; x < 8 ; x++ )
        {
            if ( spacearr[inputarr[0][0]][inputarr[0][1]+x] == '-' )
                break ;
            if ( spacearr[inputarr[0][0]][inputarr[0][1]+x] == color )
                for ( int y = 0 ; y < x ; y++ )
                {
                    spacearr[inputarr[0][0]][inputarr[0][1]+y] = color ;
                }
        }

    // left :
    if ( spacearr[inputarr[0][0]][inputarr[0][1]-1] != color && spacearr[inputarr[0][0]][inputarr[0][1]-1] != '-' )
        for ( int x = 2 ; x < 8 ; x++ )
        {
            if ( spacearr[inputarr[0][0]][inputarr[0][1]-x] == '-' )
                break ;
            if ( spacearr[inputarr[0][0]][inputarr[0][1]-x] == color )
                for ( int y = 0 ; y < x ; y++ )
                {
                    spacearr[inputarr[0][0]][inputarr[0][1]-y] = color ;
                }
        }

    // up :
    if( spacearr[inputarr[0][0]-1][inputarr[0][1]] != color && spacearr[inputarr[0][0]-1][inputarr[0][1]] != '-' )
        for ( int x = 2 ; x < 8 ; x++ )
        {
            if ( spacearr[inputarr[0][0]-x][inputarr[0][1]] == '-' )
                break ;
            if ( spacearr[inputarr[0][0]-x][inputarr[0][1]] == color )
                for ( int y = 0 ; y < x ; y++ )
                {
                    spacearr[inputarr[0][0]-y][inputarr[0][1]] = color ;
                }
        }

    // down :
    if ( spacearr[inputarr[0][0]+1][inputarr[0][1]] != color && spacearr[inputarr[0][0]+1][inputarr[0][1]] != '-' )
        for ( int x = 2 ; x < 8 ; x++ )
        {
            if ( spacearr[inputarr[0][0]+x][inputarr[0][1]] == '-' )
                break ;
            if ( spacearr[inputarr[0][0]+x][inputarr[0][1]] == color )
                for ( int y = 0 ; y < x ; y++ )
                {
                    spacearr[inputarr[0][0]+y][inputarr[0][1]] = color ;
                }
        }

    // up - right :
    if ( spacearr[inputarr[0][0]-1][inputarr[0][1]+1] != color && spacearr[inputarr[0][0]-1][inputarr[0][1]+1] != '-' )
        for ( int x = 2 ; x < 8 ; x++ )
        {
            if ( spacearr[inputarr[0][0]-x][inputarr[0][1]+x] == '-' )
                break ;
            if ( spacearr[inputarr[0][0]-x][inputarr[0][1]+x] == color )
                for ( int y = 0 ; y < x ; y++ )
                {
                    spacearr[inputarr[0][0]-y][inputarr[0][1]+y] = color ;
                }
        }

    // up - left :
    if( spacearr[inputarr[0][0]-1][inputarr[0][1]-1] != color && spacearr[inputarr[0][0]-1][inputarr[0][1]-1] != '-' )
        for ( int x = 2 ; x < 8 ; x++ )
        {
            if ( spacearr[inputarr[0][0]-x][inputarr[0][1]-x] == '-' )
                break ;
            if ( spacearr[inputarr[0][0]-x][inputarr[0][1]-x] == color )
                for ( int y = 0 ; y < x ; y++ )
                {
                    spacearr[inputarr[0][0]-y][inputarr[0][1]-y] = color ;
                }
        }

    // down - right :
    if ( spacearr[inputarr[0][0]+1][inputarr[0][1]+1] != color && spacearr[inputarr[0][0]+1][inputarr[0][1]+1] != '-' )
        for ( int x = 2 ; x < 8 ; x++ )
        {
            if ( spacearr[inputarr[0][0]+x][inputarr[0][1]+x] == '-' )
                break ;
            if ( spacearr[inputarr[0][0]+x][inputarr[0][1]+x] == color )
                for ( int y = 0 ; y < x ; y++ )
                {
                    spacearr[inputarr[0][0]+y][inputarr[0][1]+y] = color ;
                }
        }

    // down - left :
    if ( spacearr[inputarr[0][0]+1][inputarr[0][1]-1] != color && spacearr[inputarr[0][0]+1][inputarr[0][1]-1] != '-' )
        for ( int x = 2 ; x < 8 ; x++ )
        {
            if ( spacearr[inputarr[0][0]+x][inputarr[0][1]-x] == '-' )
                break ;
            if ( spacearr[inputarr[0][0]+x][inputarr[0][1]-x] == color )
                for ( int y = 0 ; y < x ; y++ )
                {
                    spacearr[inputarr[0][0]+y][inputarr[0][1]-y] = color ;
                }
        }

}


// coins number :
int coinsnum (char color , char spacearr[8][8])
{
    int numW = 0 ;
    int numB = 0 ;
    for (int i=0 ; i<8 ; i++)
        for (int j=0 ; j<8 ; j++)
        {
            if (spacearr[i][j]=='W')
                numW++;
            else if (spacearr[i][j]=='B')
                numB++;
        }
    if(color=='W')
        return numW;
    else if (color=='B')
        return numB;
    else
        return 0 ;
}

// check tekrar in place :
int tekrar(int place[65],int x,int y)
{
    for (int i = y-2 ; i>=0 ; i-=2)
    {
        if ( place[y] == place[i] )
        {
            if ( place[x] == place[i-1])
                return 1;
        }
        else
            continue;
    }
    return -1;
}

int main()
{
    char space[8][8] ;
    int x , y ;
    fstream myfile;
    // save place in arr :
    int place [65] ;
    // cin place :
    int input [1][2] ;
    char color = 'B' ;
    string player = "Black" ;
    int coinB=30 , coinW=30 ;
    char start ;
    int nobat = 1 ;
    for(int i=0 ; i<8 ; i++)
    {
        for (int j=0 ; j<8 ; j++)
            space [i][j]= 45 ;
        space [3][3] = 'W' ;
        space [4][4] = 'W' ;
        space [3][4] = 'B' ;
        space [4][3] = 'B' ;
    }
    char a[70];
    cout << "if you want a new game type (y) or if you want resume last game type (n):" ;
    cin >> start ;

    // read file :
    if (start=='y')
    {
        ifstream myfile("E:\\daneshgah\\Mabani\\othello-p1\\othello\\ last game.txt");
        if (!myfile)
            cout << "File Could not be open !" << endl ;
        myfile >> a ;
        for (int i=0 ; i<8 ; i++)
            for (int j =0 ;j<8 ; j++)
                space[i][j]=a[i*8 + j];
        coinB = a[64];
        coinW = a[65];
        nobat = a[66];

    }
    else if (start!='n' && start!='y')
    {
        cout << "pleas type (y) or (n)!" ;
    }
    cout << endl ;
    print(space) ;
    while (coinsnum('B',space)+coinsnum('W',space)<65)
    {
        if (nobat%2==0)
        {
            color = 'W' ;
            player = "White" ;
            coinW--;
        }
        if (nobat%2!=0)
        {
            color = 'B' ;
            player = "Black" ;
            coinB--;
        }
        int numseg = positionn(color,space,place) ;
        if(place[0]==99 && place[1]==99)
        {
            if (color=='B')
            {
                color='W';
                nobat++;
            }
            else if (color=='W')
            {
                color='B';
                nobat++;
            }

        }
        cout << "Coins on board for Player-Black: " << coinsnum('B',space) << endl ;
        cout << "Coins on board for Player-White: " << coinsnum('W',space) << endl ;
        cout << endl ;
        cout << "Player-" << player <<"'s turn.\n" ;
        for (int i=0 ; i<65 ; i+=2)
            if (place [i]!=99)
            {
                if(tekrar(place,i,i+1)==-1)
                    cout << "(" << place[i] << "," << place[i+1] << ")" << "  " ;
            }
        cout << endl ;
        cout << "Enter the Row Number: " ;
        cin >> y ;
        cout << "Enter the Column Number: " ;
        cin >> x ;
        input [0][0] = x ;
        input [0][1] = y ;
        if (x>8 || x<1 || y>8 || y<1)
            cout << "Illegal move! Try again.\n" ;
        for( int i=0;i<numseg;i+=2)
        {
            if (x<=8 && x>=1 && y<=8 && y>=1)
            {
                positionn(color,space,place) ;
                if ( input[0][0]==place[i] && input[0][1]==place[i+1] )
                {
                    space[x-1][y-1] = color ;
                    changecoins(input,space,color) ;
                }
            }
        }
        cout << endl << endl ;
        print(space) ;
        if (space[x-1][y-1] != color )
        {
            cout << "<< Illegal move! please Try again >>\n\n" ;
        }
        if (space[x-1][y-1] == color)
        {
            nobat++ ;
        }

        // save game :
        ofstream myfile("E:\\daneshgah\\Mabani\\othello-p1\\othello\\ last game.txt");
        if (!myfile)
            cout << "File Could not be open !" << endl ;
        for (int i=0 ; i<8 ; i++)
            for (int j=0; j<8 ; j++)
                myfile << space[i][j];
        myfile << coinB ;
        myfile << coinW ;
        myfile << nobat ;
        myfile.close();

    }

    // winner :
    if (coinsnum('B',space) > coinsnum('W',space))
    {
        cout << "Black wins!" ;
    }

    if (coinsnum('B',space) < coinsnum('W',space))
    {
        cout << "White wins!" ;
    }

    return 0 ;
}
