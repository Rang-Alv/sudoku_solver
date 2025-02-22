#include <vector>

#include "gameState.h"

gameState::gameState(int &numValues, char* values[]) {
    sudokuGrid.resize(GRID_ROW, GRID_COL, false);
    proposalHistory = std::queue<std::pair<int, int>>();
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
            if (sudokuGrid.operator()(i, j) == 0 && !makeProposal(i, j)) {
                // Backtracking algo here
                return false;
            }
            else {
                proposalHistory.push(std::make_pair(i, j));
            }
        }
    }
    // TODO: Add check for the complete grid
    return true;
}

/*
makeProposal

Inserts a valid number into the sudoku puzzle

Returns:
    true if a valid number is found
    false if no valid number is found

*/
bool gameState::makeProposal(int& i, int& j){
    std::cout << "making proposal for empty space at: " << i << "," << j << "\n";
    for (int proposal = 0; proposal < 10; proposal++){
        if (checkSegment(proposal, i, j)) {
            sudokuGrid.operator()(i, j) = proposal;
            return true;
        }
    }
    std::cout << "The solution could not be found\n";
    return false;
}

bool gameState::checkSegment(int& proposal, int& i, int& j) {
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

void gameState::printProposalHist() {
    std::cout << "reading the proposal history";
    while (!proposalHistory.empty()) {
        std::cout << proposalHistory.front().first << "," << proposalHistory.front().second << "\n";\
        proposalHistory.pop();
    }
}