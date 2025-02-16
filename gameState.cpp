#include <vector>

#include "gameState.h"

gameState::gameState(int &numValues, char* values[]) {
    sudokuGrid.resize(GRID_ROW, GRID_COL, false);
    std::cout << "gameState contructor\n";
    int currentVal;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            sudokuGrid.operator()(i, j) = (int)(*values[j*3 + i + 1] - '0');
        }
    }
}

gameState::~gameState() {
    std::cout << "gameState destructor called\n";
}

void gameState::drawGrid() {
    std::cout << "drawing sudoku game state\n";
    for (int j = 0; j < 3; j++) {
        std::cout << "|";
        for (int i = 0; i < 3; i++) {
            std::cout << sudokuGrid.operator()(i, j) << "|";
        }
        std::cout << "\n";
    }
}

bool gameState::solveGrid() {
    std::cout << "solving the game (brute force)\n";
    for (int j = 0; j < GRID_ROW; j++) {
        for (int i = 0; i < GRID_COL; i++) {
            if (sudokuGrid.operator()(i, j) == 0) {
                sudokuGrid.operator()(i, j) = makeProposal(i, j);
            }
        }
    }
    // TODO: Add check for the complete grid
    return false;
}

int gameState::makeProposal(int i, int j){
    std::cout << "making proposal for empty space at: " << i << "," << j << "\n";
    for (int proposal = 0; proposal < 10; proposal++){
        if (checkSegment(proposal, i, j)) {
            return proposal;
        }
    }
    return 0;
}

bool gameState::checkSegment(int proposal, int i, int j) {
    std::cout << "checking the segment\n";

    // TODO: Calc which segment is being checked
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 3; i++) {
            if (sudokuGrid.operator()(i, j) == proposal) {
                std::cout << proposal << " is already in the position: " << i << "," << j << ": try another one\n";
                return false;
            }
        }
    }
    return true;
}