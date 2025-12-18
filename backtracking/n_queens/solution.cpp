#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int numOfQueens = 0;
    vector<vector<char>> chessTable;
    vector<vector<string>> ans;

    bool isValid(int rowIndex, int colIndex) {
        // there can not be another queen in the same row
        for (int i = 0; i < colIndex; ++i) {
            if (chessTable[rowIndex][i] == 'Q') return false;
        }

        // top-left diagonal
        for (int i = rowIndex, j = colIndex; i >= 0 && j >= 0; --i, --j) {
            if (chessTable[i][j] == 'Q') return false;
        }

        // bottom-left diagonal
        for (int i = rowIndex, j = colIndex; i < numOfQueens && j >= 0; ++i, --j) {
            if (chessTable[i][j] == 'Q') return false;
        }

        return true;
    }

    void setQueen(int colIndex) {
        if (colIndex == numOfQueens) {
            vector<string> board;
            for (int i = 0; i < numOfQueens; ++i) {
                string row(chessTable[i].begin(), chessTable[i].end());
                board.push_back(row);
            }
            ans.push_back(board);
            return;
        }

        for (int rowIndex = 0; rowIndex < numOfQueens; ++rowIndex) {
            if (isValid(rowIndex, colIndex)) {
                chessTable[rowIndex][colIndex] = 'Q';
                setQueen(colIndex + 1);
                chessTable[rowIndex][colIndex] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        numOfQueens = n;
        chessTable.assign(numOfQueens, vector<char>(numOfQueens, '.'));
        setQueen(0);
        return ans;
    }
};
