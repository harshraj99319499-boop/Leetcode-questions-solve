
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Track digits in rows, columns, and 3x3 boxes
        bool rows[9][9] = {};
        bool cols[9][9] = {};
        bool boxes[9][9] = {};

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {

                // Ignore empty cells
                if (board[i][j] == '.') {
                    continue;
                }

                // Convert character '1'-'9' to index 0-8
                int digit = board[i][j] - '1';

                // Find the 3x3 box index
                int boxIndex = (i / 3) * 3 + (j / 3);

                // Check for duplicates
                if (rows[i][digit] ||
                    cols[j][digit] ||
                    boxes[boxIndex][digit]) {
                    return false;
                }

                // Mark digit as seen
                rows[i][digit] = true;
                cols[j][digit] = true;
                boxes[boxIndex][digit] = true;
            }
        }

        return true;
    }
};
