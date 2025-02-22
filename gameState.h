#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>
#include <iostream>
#include <queue>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

#define GRID_ROW 3
#define GRID_COL 3

class gameState {
    public:
        gameState(int &numValues, char* values[]);
        ~gameState();
        void drawGrid();
        bool solveGrid();
        void printProposalHist();
    private:
        boost::numeric::ublas::matrix<int> sudokuGrid;
        std::queue<std::pair<int, int>> proposalHistory; // Replace with new history datatype
        bool checkRow();
        bool checkCol();
        bool checkSegment(int& proposal, int& i, int& j);
        bool makeProposal(int& i, int& j);
};

#endif