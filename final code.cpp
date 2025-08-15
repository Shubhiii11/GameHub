#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;

// Color Codes
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// ----- Tic Tac Toe -----
string board[4][4];
int size;
char turn = 'X';
bool draw = false;
bool quit=false;
bool two_players;

const int PUZZLE_SIZE=3;
int puzzle[PUZZLE_SIZE][PUZZLE_SIZE];
int emptyRow,emptyCol;

void initialize_board() {
    int num = 1;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            board[i][j] = to_string(num++);
}


void display_board() {
    system("cls");
    cout <<CYAN<< "\nTic Tac Toe "<< size << "x" << size << "\n\n";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == "X")
                cout << RED << " X " <<CYAN<<  "|";
            else if (board[i][j] == "O")
                cout << YELLOW << " O " <<CYAN<< "|";
            else
                {
                	if(board[i][j].length()==1)
                	cout<<WHITE<<" "<<board[i][j]<<CYAN<<" |";
                	else
                	cout<<WHITE<<board[i][j]<<CYAN<<" |";
				}
        }
        cout << "\n";
        for (int k = 0; k < size * 4; k++) cout << "-";
        cout << "\n";
    }
}


bool move_is_valid(int r, int c) {
    return board[r][c] != "X" && board[r][c] != "O";
}


void player_turn() {
    int move;
    cout << "\nPlayer " << turn << ", enter cell number: "<< WHITE;
    cin >> move;
    if(move==0){
    	quit=true;
    	return;
	}
    int r = (move - 1) / size;
    int c = (move - 1) % size;
    if (move < 1 || move > size * size || !move_is_valid(r, c)) {
        cout << RED << "Invalid move!\n"<<CYAN;
        player_turn();
    } 
	else {
        board[r][c] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    }
}


bool gameover() {
    for (int i = 0; i < size; i++) {
        bool row = true, col = true;
        for (int j = 1; j < size; j++) {
            if (board[i][j] != board[i][0]) row = false;
            if (board[j][i] != board[0][i]) col = false;
        }
        if (row || col) return true;
    }
    bool d1 = true, d2 = true;
    for (int i = 1; i < size; i++) {
        if (board[i][i] != board[0][0]) d1 = false;
        if (board[i][ size - i - 1] != board[0][ size - 1]) d2 = false;
    }
    if (d1 || d2) return true;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            if (board[i][j] != "X" && board[i][j] != "O") return false;
    draw = true;
    return true;
}


void computer_turn() {
    int row, col;
    for(int i=0;i<size;i++){
    	for(int j=0;j<size;j++){
    		if(move_is_valid(i,j)){
    			string original=board[i][j];
    			board[i][j]="O";
    			if(gameover()){
    				turn='X';
    				return;
				}
				board[i][j]=original;
			}
		}
	}
	
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			if(move_is_valid(i,j)){
				string original=board[i][j];
		   	    board[i][j]="X";
			    if(gameover()){
			    	board[i][j]="O";
			    	turn='X';
			    	return;
		    	}
		    	board[i][j]=original;
	    	}
		}
	}
	
	srand(time(0));
	do{
		row=rand()%size;
		col=rand()%size;
	}while(!move_is_valid(row,col));
	
	board[row][col]="O";
	turn='X';
}


void show_tic_tac_toe_instructions(){
	system("cls");
	cout<<CYAN<<"\n---Tic Tac Toe Instructions---\n\n"<<GREEN;
	cout<<"1.The game can be played in 3x3 or 4x4 mode.\n";
	cout<<" 3x3 Grid              4x4 Grid\n";
	cout<<"___|___|___         ___|___|___|___\n";
	cout<<"___|___|___         ___|___|___|___\n";
	cout<<"   |   |            ___|___|___|___\n";
	cout<<"                       |   |   |   \n";
	cout<<"2.Choose Player vs Player or Computer vs Player.\n";
	cout<<"3.Players take turn entering the cell number to place X or O.\n";
	cout<<"4.First to align Xs or Os horizontally,vertically or diagonally wins.\n";
	cout<<"5.If the board fills without a winner, it's a draw.\n";
	cout<<"press enter to start..."<<CYAN;
	cin.ignore();
	cin.get();
}


void play_tic_tac_toe() {
	draw=false;
	quit=false;
	show_tic_tac_toe_instructions();
	system("cls");
	cout<<"Tic Tac Toe\n\n";
    cout << CYAN << "Choose board size (3 or 4): "<< WHITE ;
    cin >> size;
    if (size != 3 && size != 4) size = 3;
    cout << CYAN << "\n1. Player vs Player\n2. Player vs Computer\nChoose: "<< WHITE;
    int mode;
    cin >> mode;
    two_players = (mode == 1);
    initialize_board();
    while (!gameover() && !quit) {
        display_board();
        if ( two_players || turn == 'X')
            player_turn();
        else
            computer_turn();
            if(draw) break;
    }
    display_board();
    if(quit)
        cout<< YELLOW <<"\nYou exited the game\n"<<WHITE;
    else if (draw)
        cout << YELLOW << "\nDraw!\n"<<WHITE;
    else
        cout << YELLOW << "\nWinner: " << ( turn == 'X' ? 'O' : 'X') << "\n"<<WHITE ;
}





void swap(string &a, string &b) {
    string temp = a;
    a = b;
    b = temp;
}


void shuffle(string arr[], int size) {
    srand(time(0));
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
}


void show_memory_match_instructions(){
	system("cls");
	cout << CYAN << "\n--- Memory Match Instructions ---\n\n"<<GREEN;
    cout << "1. A 4x4 grid hides 8 pairs of symbols.\n";
    cout << "2. Each turn, pick two numbers from 1 to 16 to reveal cards.\n";
    cout << "3. If they match, they stay revealed.\n";
    cout << "4. If not, they get hidden again.\n";
    cout << "5. Match all pairs to win the game.\n";
    cout << "Press Enter to start..."<<CYAN;
    cin.ignore();
    cin.get();
}


void play_memory_match() {
	show_memory_match_instructions();
    string emojis[8] = {"@","#","$","%","&","!","@@","##"};
    string cards[16];

    int k = 0;
    for (int i = 0; i < 8; i++) {
        cards[k++] = emojis[i];
        cards[k++] = emojis[i];
    }

    shuffle(cards, 16);

    string grid[4][4];
    k = 0;
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            grid[i][j] = cards[k++];

    bool revealed[4][4] = {false};
    int matches = 0;

    while (matches < 8) {
        system("cls");

        cout <<CYAN<< "\nMemory Match Game\n\n";
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (revealed[i][j]) {
                    cout << "  " << WHITE << grid[i][j] << " "<<CYAN;
                } else {
                    int num = i * 4 + j + 1;
                    if (num < 10)
                        cout << " [ " << num << "]";
                    else
                        cout << " [" << num << "]";
                }
            }
            cout << "\n";
        }

        int pick1, pick2;
        cout << "\nPick two cards from 1 to 16 or enter 0 to exit: "<< WHITE;
        cin >> pick1 >> pick2;
        if(pick1==0||pick2==0){
        	cout<<YELLOW<<"\nyou exited the game\n";
        	return;
		}

        int r1 = (pick1 - 1) / 4, c1 = (pick1 - 1) % 4;
        int r2 = (pick2 - 1) / 4, c2 = (pick2 - 1) % 4;
        
        if (pick1 == pick2 || revealed[r1][c1] || revealed[r2][c2]) {
            cout << "Invalid pick. Try again.\n";
            system("pause");
            continue;
    }
    
        system("cls");
        cout << "You picked:\n";
        cout << "Card " << pick1 << ": " << grid[r1][c1]
             << "   Card " << pick2 << ": " << grid[r2][c2] << "\n";

        if (grid[r1][c1] == grid[r2][c2]) {
            cout <<YELLOW<< "It's a match!\n\n"<<CYAN;
            revealed[r1][c1] = true;
            revealed[r2][c2] = true;
            matches++;
        } else {
            cout <<RED<< "Not a match.\n\n"<<CYAN;
        }

        cout << "Press enter to continue ";
        cin.ignore();
      	cin.get();        
    }

    cout <<GREEN<<"\nCongratulations! You matched all pairs!\n";
}





void show_puzzle_game_instructions() {
    system("cls");
    cout << CYAN << "\n--- 8-Puzzle Instructions ---\n\n"<< GREEN;
    cout << "1. Arrange the numbers from 1 to 8 with one empty space.\n";
    cout << "  1  2  3\n";
    cout << "  4  5  6\n";
    cout << "  7  8  __ (empty)\n\n";
    cout << "2. Use U, D, L, R keys to move the empty tile.\n";
    cout << "  U - Move Up\n";
    cout << "  D - Move Down\n";
    cout << "  L - Move Left\n";
    cout << "  R - Move Right\n";
    cout << "  Q - Quit the game\n";
    cout << "3. Goal is to match the solved state shown at the start.\n";
    cout << "4. Press Q to quit anytime.\n";
    cout << "Press Enter to start..."<<CYAN;
    cin.ignore();
    cin.get();
}


void init_puzzle_board() {
    int num = 1;
    for (int i = 0; i < PUZZLE_SIZE; i++)
        for (int j = 0; j < PUZZLE_SIZE; j++)
            puzzle[i][j] = num++;
    puzzle[PUZZLE_SIZE - 1][PUZZLE_SIZE - 1] = 0;
    emptyRow = PUZZLE_SIZE - 1;
    emptyCol = PUZZLE_SIZE - 1;
}


void display_puzzle() {
	system("cls");
    cout << "Puzzle Game\n\n";
    for (int i = 0; i < PUZZLE_SIZE; i++) {
        for (int j = 0; j < PUZZLE_SIZE; j++) {
            if (puzzle[i][j] == 0)
                cout << " __ ";
            else
                cout <<WHITE<< " " << puzzle[i][j] << " "<<CYAN;
        }
        cout << "\n";
    }
}


void swap_puzzle_tiles(int r1, int c1, int r2, int c2) {
    int temp = puzzle[r1][c1];
    puzzle[r1][c1] = puzzle[r2][c2];
    puzzle[r2][c2] = temp;
}


void light_shuffle() {
    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int dir = rand() % 4;
        int r = emptyRow, c = emptyCol;
        switch (dir) {
            case 0: if (r > 0) swap_puzzle_tiles(r, c, r - 1, c), emptyRow--; break;
            case 1: if (r < PUZZLE_SIZE - 1) swap_puzzle_tiles(r, c, r + 1, c), emptyRow++; break;
            case 2: if (c > 0) swap_puzzle_tiles(r, c, r, c - 1), emptyCol--; break;
            case 3: if (c < PUZZLE_SIZE - 1) swap_puzzle_tiles(r, c, r, c + 1), emptyCol++; break;
        }
    }
}


bool is_puzzle_solved() {
    int num = 1;
    for (int i = 0; i < PUZZLE_SIZE; i++)
        for (int j = 0; j < PUZZLE_SIZE; j++) {
            if (i == PUZZLE_SIZE - 1 && j == PUZZLE_SIZE - 1) return puzzle[i][j] == 0;
            if (puzzle[i][j] != num++) return false;
        }
    return true;
}


void play_puzzle_game() {
	show_puzzle_game_instructions();
    init_puzzle_board();
    light_shuffle();

    while (true) {
        display_puzzle();
        if (is_puzzle_solved()) {
            cout << "\nCongratulations! You solved the puzzle!\n";
            break;
        }

        cout << "\nMove using U/L/D/R or press Q to quit: ";
        char move = _getch();
        int r = emptyRow, c = emptyCol;

        switch (move) {
            case 'd': case 'D': if (r < PUZZLE_SIZE - 1) swap_puzzle_tiles(r, c, r + 1, c), emptyRow++; break;
            case 'u': case 'U': if (r > 0) swap_puzzle_tiles(r, c, r - 1, c), emptyRow--; break;
            case 'r': case 'R': if (c < PUZZLE_SIZE - 1) swap_puzzle_tiles(r, c, r, c + 1), emptyCol++; break;
            case 'l': case 'L': if (c > 0) swap_puzzle_tiles(r, c, r, c - 1), emptyCol--; break;
            case 'q': case 'Q': cout <<YELLOW<< "\nYou quit the game.\n"; return;
        }
    }
}


void show_menu() {
    while(true){
        cout <<WHITE<< "\n==== Game Hub ====\n" ;
        cout << "1. Tic Tac Toe\n";
        cout << "2. Memory Match\n";
        cout << "3. 8-Puzzle\n";
        cout << "4. Exit\n";
        cout << "Choose: ";
        int choice;
        cin >> choice;
        if (choice == 1) play_tic_tac_toe();
        else if (choice == 2) play_memory_match();
        else if (choice == 3) play_puzzle_game();
        else if (choice==4) break;
        else cout<<"\nInvalid choice\n\n";
    }
}


int main() {
    srand(time(0));
    show_menu();
    return 0;
}