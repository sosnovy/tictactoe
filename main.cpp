#include <iostream>
#include <memory>

std::array<int,9> tiles;
int turn;
bool player;
bool won;

void clearScreen()
{
    int n;
    for (n = 0; n < 5; n++)
        printf( "\n\n\n\n\n\n\n\n\n\n" );
}
void printAvailableTiles(){
    std::cout << "Available tiles: ";
    for(int i = 0; i < tiles.size(); i++){
        if(tiles[i] < 0){
            std::cout << i << " ";
        }
    }
    std::cout << "\n";
}
void printGrid(){
    for(int j = 0; j < 9; j=j+3) {
        for (int i = 0; i < 3; i++) {
            char x = ' ';
            if(tiles[i+j] == 0){
                x = 'X';
            }
            else if(tiles[i+j] == 1){
                x = 'O';
            }
            std::cout << x;
            if (i != 2) {
                std::cout << " || ";
            }
        }
        if(j != 6){
            std::cout << "\n" << "===========" << "\n";
        }
    }
    std::cout << "\n";
}
void initialize(){
    tiles={-1,-1,-1,-1,-1,-1,-1,-1,-1};
    turn = 0;
    player = 0;
    won = false;
    printGrid();
}
void checkWin(){
    if(turn > 3){
        //horizontal win conditions
        if(tiles[0] == tiles[1] && tiles[1] == tiles[2] && tiles[0] >= 0){
            std:: cout << "Player " << player+1 << " wins!";
            won = true;
        }
        else if(tiles[3] == tiles[4] && tiles[4] == tiles[5] && tiles[3] >= 0){
            std:: cout << "Player " << player+1 << " wins!";
            won = true;
        }
        else if(tiles[6] == tiles[7] && tiles[7] == tiles[8] && tiles[6] >= 0){
            std:: cout << "Player " << player+1 << " wins!";
            won = true;
        }
            //vertical win conditions
        else if(tiles[0] == tiles[3] && tiles[3] == tiles[6] && tiles[0] >= 0){
            std:: cout << "Player " << player+1 << " wins!";
            won = true;
        }
        else if(tiles[1] == tiles[4] && tiles[4] == tiles[7] && tiles[1] >= 0){
            std:: cout << "Player " << player+1 << " wins!";
            won = true;
        }
        else if(tiles[2] == tiles[5] && tiles[5] == tiles[8] && tiles[2] >= 0){
            std:: cout << "Player " << player+1 << " wins!";
            won = true;
        }
            //diagonal win conditions
        else if(tiles[0] == tiles[4] && tiles[4] == tiles[8] && tiles[0] >= 0){
            std:: cout << "Player " << player+1 << " wins!";
            won = true;
        }
        else if(tiles[2] == tiles[4] && tiles[4] == tiles[6] && tiles[2] >= 0){
            std:: cout << "Player " << player+1 << " wins!";
            won = true;
        }
        std::cout << "\n";
    }
}
void game(){
    int var {0};
        initialize();
        while(!won) {
            std::cout << "It's player " << player + 1 << "'s turn! \n";
            std::cout << "Please select a tile \n";
            printAvailableTiles();
            std::cin >> var;
            while(tiles[var] >= 0){
                if(var > tiles.size()-1 || var < 0 ){
                    std::cout << "Selection out of bounds. \n";
                }
                else{
                    std::cout << "Tile already selected, please select a new tile. \n";
                }
                printAvailableTiles();
                std::cin >> var;
            }
            if(player){
                tiles[var] = 0;
            }
            else{
                tiles[var] = 1;
            }
            clearScreen();
            checkWin();
            printGrid();
            if(won){
                break;
            }
            player = !player;
            turn++;
            if(turn > 8){
                std::cout << "TIE";
                break;
            }
        }
}
void startGame(){
    game();
    std::cout << "Would you like to play again? \n 0: Play again \n 1: Exit";
    int selection = -1;
        std::cin >> selection;
        if(selection == 0) {
            clearScreen();
            startGame();
        }
        else{
            exit;
        }
}
int main() {
    clearScreen();
    startGame();
}
