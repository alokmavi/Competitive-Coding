class Solution {
public:
    int countSpanTree(int n, vector<vector<int>>& edges) {
        if (n <= 1) return 1;

        // Step 1: Build Adjacency Matrix
        vector<vector<int>> adj(n, vector<int>(n, 0));
        for (auto& edge : edges) {
            // fixed this part now: Access the first and second elements of the edge vector
            int u = edge[0];
            int v = edge[1];
            adj[u][v] = adj[v][u] = 1;
        }

        // Step 2: Build Laplacian Matrix
        vector<vector<double>> laplacian(n, vector<double>(n, 0));
        for (int i = 0; i < n; ++i) {
            int degree = 0;
            for (int j = 0; j < n; ++j) {
                if (adj[i][j]) degree++;
            }
            laplacian[i][i] = degree;
            for (int j = 0; j < n; ++j) {
                if (i != j && adj[i][j]) {
                    laplacian[i][j] = -1;
                }
            }
        }

        // Step 3: Remove last row and column to get cofactor matrix
        int size = n - 1;
        vector<vector<double>> cofactor(size, vector<double>(size));
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                cofactor[i][j] = laplacian[i][j];
            }
        }

        // Step 4: Compute determinant using Gaussian elimination
        double det = 1.0;
        for (int i = 0; i < size; ++i) {
            int pivot = i;
            while (pivot < size && abs(cofactor[pivot][i]) < 1e-9) pivot++;
            if (pivot == size) return 0; // Singular matrix

            if (pivot != i) {
                swap(cofactor[i], cofactor[pivot]);
                det = -det;
            }

            det *= cofactor[i][i];
            for (int j = i + 1; j < size; ++j) {
                double factor = cofactor[j][i] / cofactor[i][i];
                for (int k = i; k < size; ++k) {
                    cofactor[j][k] -= factor * cofactor[i][k];
                }
            }
        }

        return round(abs(det));
    }
};