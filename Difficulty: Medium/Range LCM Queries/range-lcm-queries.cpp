#include <vector>
#include <numeric>

using namespace std;

class Solution {
    vector<long long> segmentTree;
    int arrayCapacity;

    void buildSegmentTree(const vector<int>& sourceArray, int nodeIndex, int leftBound, int rightBound) {
        if (leftBound == rightBound) {
            segmentTree[nodeIndex] = sourceArray[leftBound];
            return;
        }
        
        int midPoint = leftBound + (rightBound - leftBound) / 2;
        int leftChildIndex = 2 * nodeIndex + 1;
        int rightChildIndex = 2 * nodeIndex + 2;

        buildSegmentTree(sourceArray, leftChildIndex, leftBound, midPoint);
        buildSegmentTree(sourceArray, rightChildIndex, midPoint + 1, rightBound);

        // Utilizing C++17 std::lcm to handle prime factorization merges without manual GCD operations or overflow risks.
        segmentTree[nodeIndex] = std::lcm(segmentTree[leftChildIndex], segmentTree[rightChildIndex]);
    }

    void updateNode(int nodeIndex, int leftBound, int rightBound, int targetUpdateIndex, long long updatedValue) {
        if (leftBound == rightBound) {
            segmentTree[nodeIndex] = updatedValue;
            return;
        }

        int midPoint = leftBound + (rightBound - leftBound) / 2;
        int leftChildIndex = 2 * nodeIndex + 1;
        int rightChildIndex = 2 * nodeIndex + 2;

        if (targetUpdateIndex <= midPoint) {
            updateNode(leftChildIndex, leftBound, midPoint, targetUpdateIndex, updatedValue);
        } else {
            updateNode(rightChildIndex, midPoint + 1, rightBound, targetUpdateIndex, updatedValue);
        }

        segmentTree[nodeIndex] = std::lcm(segmentTree[leftChildIndex], segmentTree[rightChildIndex]);
    }

    long long queryRangeLcm(int nodeIndex, int leftBound, int rightBound, int queryStartBound, int queryEndBound) {
        if (queryStartBound > rightBound || queryEndBound < leftBound) {
            return 1; 
        }
        if (queryStartBound <= leftBound && queryEndBound >= rightBound) {
            return segmentTree[nodeIndex];
        }

        int midPoint = leftBound + (rightBound - leftBound) / 2;
        int leftChildIndex = 2 * nodeIndex + 1;
        int rightChildIndex = 2 * nodeIndex + 2;

        long long leftSegmentLcm = queryRangeLcm(leftChildIndex, leftBound, midPoint, queryStartBound, queryEndBound);
        long long rightSegmentLcm = queryRangeLcm(rightChildIndex, midPoint + 1, rightBound, queryStartBound, queryEndBound);

        return std::lcm(leftSegmentLcm, rightSegmentLcm);
    }

public:
    vector<long long> RangeLCMQuery(vector<int>& arr, vector<vector<int>>& queries) {
        if (arr.empty() || queries.empty()) {
            return {};
        }

        arrayCapacity = arr.size();
        segmentTree.assign(4 * arrayCapacity, 1);
        buildSegmentTree(arr, 0, 0, arrayCapacity - 1);

        vector<long long> queryResults;
        queryResults.reserve(queries.size());

        for (const auto& operation : queries) {
            if (operation.empty() || operation.size() < 3) {
                continue;
            }

            int operationType = operation[0];

            if (operationType == 1) {
                int targetUpdateIndex = operation[1];
                int updatedValue = operation[2];
                
                if (targetUpdateIndex >= 0 && targetUpdateIndex < arrayCapacity) {
                    updateNode(0, 0, arrayCapacity - 1, targetUpdateIndex, updatedValue);
                }
            } else if (operationType == 2) {
                int queryStartBound = operation[1];
                int queryEndBound = operation[2];
                
                if (queryStartBound >= 0 && queryEndBound >= queryStartBound && queryEndBound < arrayCapacity) {
                    queryResults.push_back(queryRangeLcm(0, 0, arrayCapacity - 1, queryStartBound, queryEndBound));
                }
            }
        }

        return queryResults;
    }
};