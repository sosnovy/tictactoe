#include <iostream>


void printGrid(){
    for(int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            char x = ' ';
            std::cout << x;
            if (i != 2) {
                std::cout << " || ";
            }

        }
        if(j != 2){
            std::cout << "\n" << "===========" << "\n";
        }
    }

}

int main() {
    printGrid();
}
