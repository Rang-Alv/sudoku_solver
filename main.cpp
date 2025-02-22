#include <boost/regex.hpp>
#include <iostream>
#include <string>

#include "draw.h"
#include "gameState.h"

int main(int argc, char* argv[]) {
    try {
        std::cout << "Sudoku Solver\n";
        if (argc != 10) {
            std::cout << "Incorrect number of input, expected 9, received \n" << argc - 1;
        }

        gameState sudokuGame(argc, argv);
        sudokuGame.drawGrid();
        sudokuGame.solveGrid();
        sudokuGame.drawGrid();
        sudokuGame.printProposalHist();
        //drawValues(argc, argv);
        return 0;
    }
    catch (const std::exception& e) {
        std::cout << "Caught standard exception: '" << e.what() << "'\n";
    }
}