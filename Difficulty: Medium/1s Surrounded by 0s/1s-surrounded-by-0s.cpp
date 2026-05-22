class Solution {
    void flagEscapableClusters(int startRow, int startCol, int maxRows, int maxCols, const vector<vector<int>>& grid, vector<vector<bool>>& escapableState) {
        queue<pair<int, int>> traversalQueue;
        traversalQueue.push({startRow, startCol});
        escapableState[startRow][startCol] = true;
        
        static const int rowDirections[] = {-1, 1, 0, 0};
        static const int colDirections[] = {0, 0, -1, 1};

        while (!traversalQueue.empty()) {
            auto [currentRow, currentCol] = traversalQueue.front();
            traversalQueue.pop();

            for (int directionIndex = 0; directionIndex < 4; ++directionIndex) {
                int nextRow = currentRow + rowDirections[directionIndex];
                int nextCol = currentCol + colDirections[directionIndex];

                if (nextRow >= 0 && nextRow < maxRows && nextCol >= 0 && nextCol < maxCols) {
                    if (grid[nextRow][nextCol] == 1 && !escapableState[nextRow][nextCol]) {
                        escapableState[nextRow][nextCol] = true;
                        traversalQueue.push({nextRow, nextCol});
                    }
                }
            }
        }
    }

public:
    int cntOnes(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int rowCount = grid.size();
        int colCount = grid[0].size();

        vector<vector<bool>> escapableState(rowCount, vector<bool>(colCount, false));

        for (int col = 0; col < colCount; ++col) {
            if (grid[0][col] == 1 && !escapableState[0][col]) {
                flagEscapableClusters(0, col, rowCount, colCount, grid, escapableState);
            }
            if (grid[rowCount - 1][col] == 1 && !escapableState[rowCount - 1][col]) {
                flagEscapableClusters(rowCount - 1, col, rowCount, colCount, grid, escapableState);
            }
        }

        for (int row = 0; row < rowCount; ++row) {
            if (grid[row][0] == 1 && !escapableState[row][0]) {
                flagEscapableClusters(row, 0, rowCount, colCount, grid, escapableState);
            }
            if (grid[row][colCount - 1] == 1 && !escapableState[row][colCount - 1]) {
                flagEscapableClusters(row, colCount - 1, rowCount, colCount, grid, escapableState);
            }
        }

        int trappedCount = 0;

        for (int row = 0; row < rowCount; ++row) {
            for (int col = 0; col < colCount; ++col) {
                if (grid[row][col] == 1 && !escapableState[row][col]) {
                    trappedCount++;
                }
            }
        }

        return trappedCount;
    }
};