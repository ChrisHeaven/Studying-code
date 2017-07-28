class Flip {
public:
    vector<vector<int> > flipChess(vector<vector<int> > A, vector<vector<int> > f) {
        // write code here
        for (int i = 0; i < 3; i++)
        {
            int row = f[i][0] - 1;
            int col = f[i][1] - 1;

            if (row - 1 >= 0)
            {
                if (A[row - 1][col] == 0)
                    A[row - 1][col] = 1;
                else
                    A[row - 1][col] = 0;
            }

            if (row + 1 < 4)
            {
                if (A[row + 1][col] == 0)
                    A[row + 1][col] = 1;
                else
                    A[row + 1][col] = 0;
            }

            if (col - 1 >= 0)
            {
                if (A[row][col - 1] == 0)
                    A[row][col - 1] = 1;
                else
                    A[row][col - 1] = 0;
            }

            if (col + 1 < 4)
            {
                if (A[row][col + 1] == 0)
                    A[row][col + 1] = 1;
                else
                    A[row][col + 1] = 0;
            }
        }
        return A;
    }
};