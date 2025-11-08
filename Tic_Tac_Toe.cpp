#include <iostream>
using namespace std;

int current_player;
int current_marker;
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void drawboard()
{
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
    // cout << "---|---|---\n";
}

bool placemarker(int slot)
{

    int row = (slot - 1) / 3;
    int column = (slot - 1) % 3;

    if (board[row][column] != 'X' && board[row][column] != '0')
    {
        board[row][column] = current_marker;
        return true;
    }
    else
    {
        return false;
    }
}
int winner(){
    // row
    for (int i = 0; i<3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            if (board[i][0] == 'X') return current_player;
            if (board[i][0] == '0') return current_player;
        
        }

        // column
        if (board[0][i] == board[1][i] && board[1][i]== board[2][i])
        {
            if (board[0][i] == 'X') return current_player;
            if (board[0][i] == '0') return current_player;
        }

        // diagonal
        if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        {
            if (board[0][0] && board[1][1] && board[2][2] == 'X') return current_player;
            if (board[0][0] && board[1][1] && board[2][2] == '0') return current_player;;
        }
        if(board[0][2]==board[1][1] && board[1][1] == board[2][0]){
            if (board[0][2] &&board[1][1] && board[1][1] == 'X') return current_player;
            if (board[0][2] &&board[1][1] && board[1][1] == '0') return current_player;
        }
    }
    return 0;
}

void swapplayerandmarker(){
    if(current_marker == 'X'){
        current_marker = '0';
    }
    else{
        current_marker ='X';
    }
    if(current_player == 1){
        current_player = 2;
    }
    else{
        current_player = 1;
    }
}



void game()
{

    cout << "Player1 Choose Your marker 0 or X :";
    char markerP1;
    cin >> markerP1;

    current_player = 1;
    current_marker = markerP1;

    drawboard();
    int playerwon;
    for (int i = 0; i < 9; i++)
    {
        cout << "Its Player " << current_player << "'s turn ! Enter Your Slot :";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9)
        {
            cout << "It is not a valid slot ! / Try Again !";
            i--;
            continue;
        }

        if (!placemarker(slot)){
            cout << "Space Occupied ! Try Again \n";
            i--;
            continue;
        }
        drawboard();
        playerwon = winner();

        if (playerwon == 1)
        {
            cout << "Player1 Wins";
            return;
            
        }
        if (playerwon == 2)
        {
            cout << "Player2 Wins";
            return;
           
        }
        swapplayerandmarker();
    }
    cout << "Its a tie !";
};

int main()
{
    game();
    return 0;
};