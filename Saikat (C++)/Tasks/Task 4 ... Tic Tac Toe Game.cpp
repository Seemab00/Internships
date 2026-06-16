#include <iostream>
using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char b[3][3]) 
{
    cout<<"\n\n";
    for(int i=0; i<3; i++) 
	{
        for(int j=0; j<3; j++) 
		{
            cout<<" "<<b[i][j]<<" ";
            if(j<2)
			{
				cout<<"|";
			} 
        }
        if(i<2)
		{
			cout << "\n---|---|---\n";
		} 
    }
    cout<<"\n\n\n";
}

// Function to check for a win
bool checkWin(char b[3][3], char p) 
{
    // Check rows and columns
    for(int i=0; i<3; i++) 
	{
        if( (b[i][0]==p && b[i][1]==p && b[i][2]==p) || (b[0][i]==p && b[1][i]==p && b[2][i]==p) ) 
		{
            return true;
        }
    }
    // Check diagonals
    if( (b[0][0]==p && b[1][1]==p && b[2][2]==p) || (b[0][2]==p && b[1][1]==p && b[2][0]==p)) 
	{
        return true;
    }
    
    return false;
}

// Function to check if the board is full (draw condition)
bool isDraw(char b[3][3]) 
{
    for(int i=0; i<3; i++) 
	{
        for(int j=0; j<3; j++) 
		{
            if( b[i][j]==' ') 
			{
                return false;
            }
        }
    }
    return true;
}

// Main function to implement the game
int main() 
{
    char b[3][3] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
    char cp = 'X';
    int r, c;

    cout<<"\n ~~ Welcome to Tic-Tac-Toe!! ~~\n";
    displayBoard(b);

    while(true) 
	{
        cout<<"Player '"<<cp<<"' turn...";
        cout<<"\nEnter row (1-3) : "; 
        cin>>r;
		cout<<"Enter column (1-3) : "; 
		cin>>c;

        // Adjust indices for 0-based array
        r--;
        c--;

        // Validate the move
        if( r<0 || r>=3 || c<0 || c>=3 || b[r][c]!=' ' ) 
		{
            cout<<"\nInvalid move! Try again.\n\n";
            continue;
        }

        // Make the move
        b[r][c] = cp;
        displayBoard(b);

        // Check for a win
        if( checkWin(b, cp) ) 
		{
            cout<<"\nPlayer "<<cp<<" wins! ... Congratulations !! ";
            break;
        }

        // Check for a draw
        if( isDraw(b) ) 
		{
            cout<<"\nIt's a draw! Well played both !! ";
            break;
        }

        // Switch to the other player
        if(cp=='X')
        {
        	cp='O';
		}
		else
		{
			cp='X';
		}
        //cp = ( cp=='X') ? 'O' : 'X';
    }

    return 0;
}
