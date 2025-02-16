#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <vector>
#include <iostream>
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
    private:
        boost::numeric::ublas::matrix<int> sudokuGrid;
        bool checkRow();
        bool checkCol();
        bool checkSegment(int proposal, int i, int j);
        int makeProposal(int i, int j);
};

#endif