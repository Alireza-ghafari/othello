#include <iostream>
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
void changecoins(int inputarr[1][2], char spacearr[8][8] , char color )
{
    inputarr[0][0]--;
    inputarr[0][1]--;

    // right :
    for (int i = 1 ; i < 15 ; i++)  // check it
        if(spacearr[inputarr[0][0]][inputarr[0][1]+i]==color || spacearr[inputarr[0][0]][inputarr[0][1]+i]==45)
            break;
        else if(spacearr[inputarr[0][0]][inputarr[0][1]+i]!=color && spacearr[inputarr[0][0]][inputarr[0][1]+i]!=45)
        {
            for (int l=2 ; l<15 ; l++)
            {
                if (spacearr[inputarr[0][0]][inputarr[0][1]+l]==color)
                {
                    if(spacearr[inputarr[0][0]][inputarr[0][1]+i]=='W')
                        spacearr[inputarr[0][0]][inputarr[0][1]+i]='B';
                    else if(spacearr[inputarr[0][0]][inputarr[0][1]+i]=='B')
                        spacearr[inputarr[0][0]][inputarr[0][1]+i]='W';
                }
                else
                    continue;
            }
        }

    // left :
    for (int i = 1 ; i < 15 ; i++)  // check it
        if(spacearr[inputarr[0][0]][inputarr[0][1]-i]==color || spacearr[inputarr[0][0]][inputarr[0][1]-i]==45)
            break;
        else if(spacearr[inputarr[0][0]][inputarr[0][1]-i]!=color && spacearr[inputarr[0][0]][inputarr[0][1]-i]!=45)
        {
            for (int l=2 ; l<15 ; l++)
                if (spacearr[inputarr[0][0]][inputarr[0][1]-l]==color)
                {
                    if(spacearr[inputarr[0][0]][inputarr[0][1]-i]=='W')
                        spacearr[inputarr[0][0]][inputarr[0][1]-i]='B';
                    else if(spacearr[inputarr[0][0]][inputarr[0][1]-i]=='B')
                        spacearr[inputarr[0][0]][inputarr[0][1]-i]='W';
                }
                else
                    continue;
        }

    // top :
    for (int i = 1 ; i < 15 ; i++)  // check it
        if(spacearr[inputarr[0][0]+i][inputarr[0][1]]==color || spacearr[inputarr[0][0]+i][inputarr[0][1]]==45)
            break;
        else if(spacearr[inputarr[0][0]+i][inputarr[0][1]]!=color && spacearr[inputarr[0][0]+i][inputarr[0][1]]!=45)
        {
            for (int l=2 ; l<15 ; l++)
                if (spacearr[inputarr[0][0]+l][inputarr[0][1]]==color)
                {
                    if(spacearr[inputarr[0][0]+i][inputarr[0][1]]=='W')
                        spacearr[inputarr[0][0]+i][inputarr[0][1]]='B';
                    else if(spacearr[inputarr[0][0]+i][inputarr[0][1]]=='B')
                        spacearr[inputarr[0][0]+i][inputarr[0][1]]='W';
                }
                else
                    continue;
        }

    // down :
    for (int i = 1 ; i < 15 ; i++)  // check it
        if(spacearr[inputarr[0][0]-i][inputarr[0][1]]==color || spacearr[inputarr[0][0]-i][inputarr[0][1]]==45)
            break;
        else if(spacearr[inputarr[0][0]-i][inputarr[0][1]]!=color && spacearr[inputarr[0][0]-i][inputarr[0][1]]!=45)
        {
            for (int l=2 ; l<15 ; l++)
                if (spacearr[inputarr[0][0]-l][inputarr[0][1]]==color)
                {
                    if(spacearr[inputarr[0][0]-i][inputarr[0][1]]=='W')
                        spacearr[inputarr[0][0]-i][inputarr[0][1]]='B';
                    else if(spacearr[inputarr[0][0]-i][inputarr[0][1]]=='B')
                        spacearr[inputarr[0][0]-i][inputarr[0][1]]='W';
                }
                else
                    continue;
        }

    // top - right :
    int k = 0 ;
    for (int i = 1 ; i < 20 ; i++)  // check it
        if(spacearr[inputarr[0][0]+i][inputarr[0][1]-i]==color || spacearr[inputarr[0][0]+i][inputarr[0][1]-i]==45)
        {
            k++;
            break;
        }

        else if(spacearr[inputarr[0][0]+i][inputarr[0][1]-i]!=color && spacearr[inputarr[0][0]+i][inputarr[0][1]-i]!=45)
        {
            if (k<2)
            {
                for (int l=2 ; l < 20 ; l++)
                    if (spacearr[inputarr[0][0]+l][inputarr[0][1]-l]==color)
                    {
                        if(spacearr[inputarr[0][0]+i][inputarr[0][1]-i]=='W')
                            spacearr[inputarr[0][0]+i][inputarr[0][1]-i]='B';
                        else if(spacearr[inputarr[0][0]+i][inputarr[0][1]-i]=='B')
                            spacearr[inputarr[0][0]+i][inputarr[0][1]-i]='W';
                    }
                    else
                        continue;
            }
        }

    // top - left :
    k = 0 ;
    for (int i = 1 ; i < 20 ; i++)  // check it
        if(spacearr[inputarr[0][0]+i][inputarr[0][1]+i]==color || spacearr[inputarr[0][0]+i][inputarr[0][1]+i]==45)
        {
            k++;
            break;
        }

        else if(spacearr[inputarr[0][0]+i][inputarr[0][1]+i]!=color && spacearr[inputarr[0][0]+i][inputarr[0][1]+i]!=45)
        {
            if (k<2)
            {
                for (int l=2 ; l < 20 ; l++)
                    if (spacearr[inputarr[0][0]+l][inputarr[0][1]+l]==color)
                    {
                        if(spacearr[inputarr[0][0]+i][inputarr[0][1]+i]=='W')
                            spacearr[inputarr[0][0]+i][inputarr[0][1]+i]='B';
                        else if(spacearr[inputarr[0][0]+i][inputarr[0][1]+i]=='B')
                            spacearr[inputarr[0][0]+i][inputarr[0][1]+i]='W';
                    }
                    else
                        continue;
            }
        }

    // down - right :
    k = 0 ;
    for (int i = 1 ; i < 20 ; i++)  // check it
        if(spacearr[inputarr[0][0]-i][inputarr[0][1]+i]==color || spacearr[inputarr[0][0]-i][inputarr[0][1]+i]==45)
        {
            k++;
            break;
        }

        else if(spacearr[inputarr[0][0]-i][inputarr[0][1]+i]!=color && spacearr[inputarr[0][0]-i][inputarr[0][1]+i]!=45)
        {
            if (k<2)
            {
                for (int l=2 ; l < 20 ; l++)
                    if (spacearr[inputarr[0][0]-l][inputarr[0][1]+l]==color)
                    {
                        if(spacearr[inputarr[0][0]-i][inputarr[0][1]+i]=='W')
                            spacearr[inputarr[0][0]-i][inputarr[0][1]+i]='B';
                        else if(spacearr[inputarr[0][0]-i][inputarr[0][1]+i]=='B')
                            spacearr[inputarr[0][0]-i][inputarr[0][1]+i]='W';
                    }
                    else
                        continue;
            }
        }

    // down - left :
    k = 0 ;
    for (int i = 1 ; i < 20 ; i++)  // check it
        if(spacearr[inputarr[0][0]-i][inputarr[0][1]-i]==color || spacearr[inputarr[0][0]-i][inputarr[0][1]-i]==45)
        {
            k++;
            break;
        }

        else if(spacearr[inputarr[0][0]-i][inputarr[0][1]-i]!=color && spacearr[inputarr[0][0]-i][inputarr[0][1]-i]!=45)
        {
            if (k<2)
            {
                for (int l=2 ; l < 20 ; l++)
                    if (spacearr[inputarr[0][0]-l][inputarr[0][1]-l]==color)
                    {
                        if(spacearr[inputarr[0][0]-i][inputarr[0][1]-i]=='W')
                            spacearr[inputarr[0][0]-i][inputarr[0][1]-i]='B';
                        else if(spacearr[inputarr[0][0]-i][inputarr[0][1]-i]=='B')
                            spacearr[inputarr[0][0]-i][inputarr[0][1]-i]='W';
                    }
                    else
                        continue;
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
    // save place in arr :
    int place [65] ;
    // cin place :
    int input [1][2] ;
    char color = 'B' ;
    string player = "Black" ;
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
    print(space) ;
    while (coinsnum('B',space)+coinsnum('W',space)<65)
    {
        if (nobat%2==0)
        {
            color = 'W' ;
            player = "White" ;
        }
        if (nobat%2!=0)
        {
            color = 'B' ;
            player = "Black" ;
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

    }
    return 0 ;
}
