class Solution {
public:
    int hIndex(vector<int>& citations) {
        int N = citations.size();
        vector<int> bucket(N + 1, 0);

        for (int citation : citations) {
            if (citation >= N) {
                bucket[N]++;
            } else {
                bucket[citation]++;
            }
        }

        int count = 0;
        for (int i = N; i >= 0; i--) {
            count += bucket[i];
            if (count >= i) {
                return i;
            }
        }

        return 0;
    }
};
