class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() - 1;

        while (l <= r)
        {
            int m = l + (r-l) / 2;
            if (matrix[m][0] == target)
                return true;
            else if (matrix[m][0] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        if (r < 0)
            return false;
        int row = r;
        l = 0;
        r = matrix[row].size() - 1;
        while (l <= r)
        {
            int m = l + (r-l)/2;
            if (matrix[row][m] == target)
                return true;
            else if (matrix[row][m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        return false;
    }
};
