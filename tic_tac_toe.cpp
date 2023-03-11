#include<iostream>
#include<bits/stdc++.h>
using namespace std;
string X,O;
string player_X,player_O;
//                       player information 
void player_info()
{
//	Step1: collecting info
//    cin.ignore();
	cout<<"Enter a name for X Player:"<<endl;
//	getline(cin,X);
	getline(cin,X);
	cout<<"Enter a name for O Player:"<<endl;
	getline(cin,O);

// step2: validating info

	while(1)
	{
	    cout<< "Who plays first, "<<X<<" or "<<O<<" ?"<<endl;
	    getline(cin,player_X);
		if(!(player_X==X || player_X==O))
		{
			cout<<player_X<<" is not a registered player "<<endl;
		}
		else
		{
		    if(player_X==X)
		    player_O=O;
		    else
		    player_O=X;
		    break;
		}		
	}
}
                                //structure of tic tac toe
void initial_stage(char arr[3][3])
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3 ;j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	cout<<"Player of current turn: "<<player_X<<"(X)"<<endl;
		
}

                               // game logic starts here
void start_game(char arr[3][3], int i)
{
	int r,c;
	while(1)
	{
	    cout<<"Choose a row number (0 to 2): "<<endl;
	    cin>>r;
	    if(r>-1 && r<3)
	    {
		    cout<<"Choose a column number(0 to 2): "<<endl;
		    cin>>c;
		    if(!(c>-1 && c<3))
		    {
			    cout<<c<<" is not a valid column. "<<endl;
		    }
		    else
		    {
		    	int flag=0;
		    	if(arr[r][c]!='.')
	            {
	            	flag=1;
	    	        cout<<"space is occupied"<<endl;
		        }
		        if(flag==0)
			    break;
		    }
	    }
	    else
	    {
		    cout<<r<<" is not a valid row. "<<endl;
	    }
	    
    }
    if(i%2==0)
    {
    	arr[r][c]='X';
	}
	else
	{
	    arr[r][c]='O';	
	}
}
                              // showing current tic tac toe
void show(char arr[3][3], int index)
{
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<arr[i][j];
		}
		cout<<endl;
	}
	if(!(index%2==0))
	{
		cout<<"Player of current turn: "<<player_X<<"(X)"<<endl;
	}
	else
	cout<<"Player of current turn: "<<player_O<<"(O)"<<endl;
}
                             // result of the game tic tac toe
char result(char arr[3][3])
{
	if(arr[0][0]=='X' && arr[1][1]=='X' && arr[2][2]=='X')
	{
		cout<<1;
		return 'X';
	}
	if(arr[0][0]=='O' && arr[1][1]=='O' && arr[2][2]=='O')
	{
		cout<<2;
		return 'O';
	}
	if(arr[0][2]=='X' && arr[1][1]=='X' && arr[2][0]=='X')
	{
		cout<<3;
		return 'X';
	}
	if(arr[0][2]=='O' && arr[1][1]=='O' && arr[2][0]=='O')
	{
		cout<<4;
		return 'X';
	}
		
    for(int i=0; i<3; i++)
    {
	    if(arr[i][0]=='X' && arr[i][1]=='X' && arr[i][2]=='X')
	    {
	    	cout<<5;
		    return 'X';
	    }
	    if(arr[i][0]=='O' && arr[i][1]=='O' && arr[i][2]=='O')
	    {
	    	cout<<6;
		    return 'O';
	    }
    }
    for(int i=0; i<3; i++)
    {
	    if(arr[0][i]=='X' && arr[1][i]=='X' && arr[2][i]=='X')
	    {
	    	cout<<7;
		    return 'X';
	    }
	    if(arr[0][i]=='O' && arr[1][i]=='O' && arr[2][i]=='O')
	    {
	    	cout<<8;
		    return 'O';
	    }
    }
    return 'N';
}
int main()
{
	char choice;
	cout<<" welcome to tic tac toe !"<<endl;
	do
	{
	    player_info();
	    char arr[3][3]={{'.','.','.'},
	                    {'.','.','.'},
			    	    {'.','.','.'}};
	    initial_stage(arr);
	    int flag=0;
	    for(int i=0; i<9; i++)
	    {
		    start_game(arr, i);
		    show(arr,i);
		    if(i>4)
		    {
		        if(result(arr)=='X')
		        {
		    	    flag==1;
			        cout<<"Game is over: "<<endl;
			        cout<<player_X<<" wins! "<<endl;
			        break;
		        }
		        else if(result(arr)=='O')
		        {
		    	    flag==1;
			        cout<<"Game is over: "<<endl;
			        cout<<player_O<<" wins! "<<endl;
			        break;
		        }
	        }
	    }
	
	    if(flag==1)
	    {
		    cout<<"Game is over: "<<endl;
		    cout<<"It is a tie! "<<endl;
	    }
	    while(1)
	    {
	        cout<<"Would you like to play again? (Y/N) "<<endl;
	        choice;
	        cin>>choice;
	        if(choice!='Y' && choice!='N')
	        {
	    	    cout<<choice<<" is not a valid answer. "<<endl;
	        }
	        else
		    {
	       	    break;
		    }
	    }
	    if(choice=='N')
	    {
	   	    break;
	    }
    }while(1);
}
