#include <vector>
using namespace std;

/*
 * Valid Sudoku using seen-frequency arrays for rows, columns, and 3x3 boxes.
 * Time: O(9^2), Space: O(1)
 *
 */
class Solution {
public:

    bool seen(bool* dict, char c) {
        if (c == '.') return false;
        if (dict[c - '1']) return true;
        dict[c - '1'] = true;
        return false;
    }

    bool isValidRow(vector<vector<char>>& board, int i) {
        bool dict[9] = {false};

        for (int j = 0; j < board.size(); ++j) {
            if (seen(dict, board[i][j])) return false;
        }

        return true;
    }

    bool isValidCol(vector<vector<char>>& board, int j) {
        bool dict[9] = {false};

        for (int i = 0; i < board.size(); ++i) {
            if (seen(dict, board[i][j])) return false;
        }

        return true;
    }

    bool isValidBox(vector<vector<char>>& board, int startRow, int startCol) {
        bool dict[9] = {false};

        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (seen(dict, board[i][j])) return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();

        for (int i = 0; i < n; ++i) {
            if (!isValidRow(board, i)) return false;
            if (!isValidCol(board, i)) return false;
        }

        for (int i = 0; i < n; i += 3) {
            for (int j = 0; j < n; j += 3) {
                if (!isValidBox(board, i, j)) return false;
            }
        }

        return true;
    }
};
