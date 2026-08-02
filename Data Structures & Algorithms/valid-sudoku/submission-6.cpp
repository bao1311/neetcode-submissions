class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,unordered_set<int>> rows;
        unordered_map<int,unordered_set<int>> cols;
        unordered_map<int,unordered_set<int>> box;
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                if (board[i][j] == '.')
                    continue;

                if (rows[i].contains(board[i][j]) or cols[j].contains(board[i][j]) or box[i/3*3+j/3].contains(board[i][j]))
                {
                    return false;
                }
                else
                {
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    box[i/3*3+j/3].insert(board[i][j]);
                }
            }

        }

        return true;
        
    }
};
