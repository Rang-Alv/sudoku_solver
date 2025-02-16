#include "draw.h"

void drawValues(int &numValues, char* values[]) {
    for (int j = 0; j < 3; j++) {
        std::cout << "|";
        for (int i = 0; i < 3; i++) {
            std::cout << values[j*3 + i + 1] << "|";
        }
        std::cout << "\n";
        //std::cout << "_______\n";
    }
}