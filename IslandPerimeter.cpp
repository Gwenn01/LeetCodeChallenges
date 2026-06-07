#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    string checkSide(int i, int j, int row, int col) {
        if (i == 0 && j == 0) {
            return "upper left";
        }

        if (i == 0 && j == col - 1) {
            return "upper right";
        }

        if (i == row - 1 && j == 0) {
            return "lower left";
        }

        if (i == row - 1 && j == col - 1) {
            return "lower right";
        }

        if (j == 0) {
            return "left";
        }

        if (i == 0) {
            return "upper";
        }

        if (j == col - 1) {
            return "right";
        }

        if (i == row - 1) {
            return "lower";
        }

        return "middle";
    }

    bool checkNext(int i, int j, vector<vector<int>>& grid, string move) {

        int row = grid.size();
        int col = grid[0].size();

        if (move == "left") {
            if (j - 1 < 0) return false;
            return grid[i][j - 1] == 1;
        }

        if (move == "right") {
            if (j + 1 >= col) return false;
            return grid[i][j + 1] == 1;
        }

        if (move == "up") {
            if (i - 1 < 0) return false;
            return grid[i - 1][j] == 1;
        }

        if (move == "down") {
            if (i + 1 >= row) return false;
            return grid[i + 1][j] == 1;
        }

        return false;
    }

    int islandPerimeter(vector<vector<int>>& grid) {

        int row = grid.size();
        int col = grid[0].size();
        int ans = 0;

        if (row == 1 && col == 1) {
            return grid[0][0] == 1 ? 4 : 0;
        }

        for (int i = 0; i < row; i++) {

            for (int j = 0; j < col; j++) {

                if (grid[i][j] == 1) {

                    string position = checkSide(i, j, row, col);

                    int side = 4;

                    if (position == "upper left") {

                        if (checkNext(i, j, grid, "right")) side--;
                        if (checkNext(i, j, grid, "down")) side--;

                    }
                    else if (position == "upper right") {

                        if (checkNext(i, j, grid, "left")) side--;
                        if (checkNext(i, j, grid, "down")) side--;

                    }
                    else if (position == "lower left") {

                        if (checkNext(i, j, grid, "right")) side--;
                        if (checkNext(i, j, grid, "up")) side--;

                    }
                    else if (position == "lower right") {

                        if (checkNext(i, j, grid, "left")) side--;
                        if (checkNext(i, j, grid, "up")) side--;

                    }
                    else if (position == "upper") {

                        if (checkNext(i, j, grid, "right")) side--;
                        if (checkNext(i, j, grid, "down")) side--;
                        if (checkNext(i, j, grid, "left")) side--;

                    }
                    else if (position == "lower") {

                        if (checkNext(i, j, grid, "right")) side--;
                        if (checkNext(i, j, grid, "up")) side--;
                        if (checkNext(i, j, grid, "left")) side--;

                    }
                    else if (position == "left") {

                        if (checkNext(i, j, grid, "right")) side--;
                        if (checkNext(i, j, grid, "up")) side--;
                        if (checkNext(i, j, grid, "down")) side--;

                    }
                    else if (position == "right") {

                        if (checkNext(i, j, grid, "left")) side--;
                        if (checkNext(i, j, grid, "up")) side--;
                        if (checkNext(i, j, grid, "down")) side--;

                    }
                    else if (position == "middle") {

                        if (checkNext(i, j, grid, "right")) side--;
                        if (checkNext(i, j, grid, "up")) side--;
                        if (checkNext(i, j, grid, "down")) side--;
                        if (checkNext(i, j, grid, "left")) side--;

                    }

                    ans += side;
                }
            }
        }

        return ans;
    }
};

int main() {

    Solution s;

    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    cout << s.islandPerimeter(grid) << endl;

    return 0;
}