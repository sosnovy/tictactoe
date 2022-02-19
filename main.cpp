#include <iostream>
#include <memory>
#include <cmath>


struct Game{
    char currPlayer;
    int turn;
    std::array<int,9> tiles;
    Game(char currPlayer_, int turn_, std::array<int,9> tiles_):
        currPlayer{currPlayer_}
        ,turn{turn_}
        ,tiles{tiles_}{};

    char checkWin(){
        if(turn > 3){
            //horizontal win conditions
            if(tiles[0] == tiles[1] && tiles[1] == tiles[2] && tiles[0] >= 0){
                if(tiles[0] == 0){
                    return 'X';;
                }
                else if(tiles[0] == 1 ){
                    return 'O';
                }

            }
            else if(tiles[3] == tiles[4] && tiles[4] == tiles[5] && tiles[3] >= 0){
                if(tiles[0] == 0){
                    return 'X';
                }
                else if(tiles[0] == 1 ){
                    return 'O';
                }
            }
            else if(tiles[6] == tiles[7] && tiles[7] == tiles[8] && tiles[6] >= 0){
                if(tiles[0] == 0){
                    return 'X';
                }
                else if(tiles[0] == 1 ){
                    return 'O';
                }
            }
                //vertical win conditions
            else if(tiles[0] == tiles[3] && tiles[3] == tiles[6] && tiles[0] >= 0){
                if(tiles[0] == 0){
                    return 'X';
                }
                else if(tiles[0] == 1 ){
                    return 'O';
                }
            }
            else if(tiles[1] == tiles[4] && tiles[4] == tiles[7] && tiles[1] >= 0){
                if(tiles[0] == 0){
                    return 'X';
                }
                else if(tiles[0] == 1 ){
                    return 'O';
                }
            }
            else if(tiles[2] == tiles[5] && tiles[5] == tiles[8] && tiles[2] >= 0){
                if(tiles[0] == 0){
                    return 'X';
                }
                else if(tiles[0] == 1 ){
                    return 'O';
                }
            }
                //diagonal win conditions
            else if(tiles[0] == tiles[4] && tiles[4] == tiles[8] && tiles[0] >= 0){
                if(tiles[0] == 0){
                    return 'X';
                }
                else if(tiles[0] == 1 ){
                    return 'O';
                }
            }
            else if(tiles[2] == tiles[4] && tiles[4] == tiles[6] && tiles[2] >= 0){
                if(tiles[0] == 0){
                    return 'X';
                }
                else if(tiles[0] == 1 ){
                    return 'O';
                }
            }
            else{
                std::cout << "\n";
                return 'n';
            }
        }
        else{
            return 'n';
        }
    }
    float scores(char& var){
        switch(var){
            case 'X':
                return -1;
            case 'O':
                return 1;
            default:
                return 0;
        }
    }
    float minimax(Game* game, int depth, char player){
        if(depth == 0 || game->checkWin() != 'n'){
            return scores(player);
        }
        if(player == 'X'){
            float value = -INFINITY;
            for(int i = 0; i < tiles.size(); i++){
                if(game->tiles[i] < 0){
                    Game* newGame = new Game(player,game->turn+1,game->tiles);
                    newGame->tiles[i] = 1;
                    value = fmax(value*depth, minimax(newGame, depth - 1,'O'));
                    return value*depth;
                }
            }

        }
        else{
            float value = INFINITY;
            for(int i = 0; i < tiles.size(); i++){
                if(game->tiles[i] < 0){
                    Game* newGame = new Game(player,game->turn+1,game->tiles);
                    newGame->tiles[i] = 0;
                    value = fmin(value*depth, minimax(newGame, depth - 1,'X'));
                    return value*depth;
                }
            }
        }

    }
    void aiTurn(){
        float score = -INFINITY;
        int toPlace;
        for(int i = 0; i < tiles.size(); i++){
            if(tiles[i] == -1){
                Game* newGame = new Game('O',turn+1,tiles);
                newGame->tiles[i] = 1;
                float newScore = minimax(newGame,9 - newGame->turn,'O');
                if(newScore > score){
                    score = newScore;
                    toPlace = i;
                }
            }
        }
        tiles[toPlace] = 1;

        currPlayer = 'O';
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
    void startGame(){
        int var;

        while(true){
            if (Game::checkWin() != 'n') {
                std::cout << "Game over";
                Game::printGrid();
                break;
            }
            if(currPlayer == 'O') {


                Game::printGrid();
                Game::printAvailableTiles();
                std::cin >> var;
                while (tiles[var] >= 0) {
                    if (var > tiles.size() - 1 || var < 0) {
                        std::cout << "Selection out of bounds. \n";
                    } else {
                        std::cout << "Tile already selected, please select a new tile. \n";
                    }
                    printAvailableTiles();
                    std::cin >> var;
                }
                tiles[var] = 0;
                std::cout << "DEBUG \n";
                for(int a : Game::tiles){
                    std::cout << a << " ";
                }
                std::cout << "\n";
                if (checkWin() != 'n') {
                    std::cout << "Game over \n";
                    break;
                }
                currPlayer = 'X';
                turn++;
            }
            else{
                aiTurn();
                turn++;
            }




        }

    }



};
int main() {
    Game* tictactoe = new Game('O',0,{-1,-1,-1,-1,-1,-1,-1,-1,-1});
    tictactoe->startGame();



}
