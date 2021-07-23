#include <bits/stdc++.h>

using namespace std;
void display(vector<vector<int>> board, int n, int m)
{
    cout << "\n\n";
    cout << "************* The filled valid Sudoku is as follows *************"
         << "\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isValid(vector<vector<int>> board, int n, int m, int x, int y, int pos)
{
    for (int j = 0; j < m; j++)
    {
        if (board[x][j] == pos)
        {
            return false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (board[i][y] == pos)
        {
            return false;
        }
    }

    int subi = x / 3 * 3;
    int subj = y / 3 * 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[subi + i][subj + j] == pos)
                return false;
        }
    }

    return true;
}
void sudokuSolve(vector<vector<int>> board, int n, int m, int x, int y)
{

    if (x == n)
    {
        display(board, n, m);
        return;
    }

    int next_x = 0;
    int next_y = 0;

    if (y == m - 1)
    {
        next_x = x + 1;
        next_y = 0;
    }
    else
    {
        next_x = x;
        next_y = y + 1;
    }

    if (board[x][y] != 0)
    {
        sudokuSolve(board, n, m, next_x, next_y);
    }
    else
    {
        for (int pos = 1; pos <= 9; pos++)
        {
            if (isValid(board, n, m, x, y, pos) == true)
            {
                board[x][y] = pos;
                sudokuSolve(board, n, m, next_x, next_y);
                board[x][y] = 0;
            }
        }
    }
}

int main()
{
    int n = 9, m = 9;
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    sudokuSolve(arr, n, m, 0, 0);
}
