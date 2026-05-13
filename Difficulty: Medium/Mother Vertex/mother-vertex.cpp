class Solution {
    void computeTopologicalCandidate(int currentVertex, const vector<vector<int>>& forwardGraph, vector<bool>& visitationState, int& lastFinishedVertex) {
        visitationState[currentVertex] = true;
        for (const int adjacentVertex : forwardGraph[currentVertex]) {
            if (!visitationState[adjacentVertex]) {
                computeTopologicalCandidate(adjacentVertex, forwardGraph, visitationState, lastFinishedVertex);
            }
        }
        lastFinishedVertex = currentVertex;
    }

    void validateReachability(int currentVertex, const vector<vector<int>>& forwardGraph, vector<bool>& visitationState, int& reachableCount) {
        visitationState[currentVertex] = true;
        reachableCount++;
        for (const int adjacentVertex : forwardGraph[currentVertex]) {
            if (!visitationState[adjacentVertex]) {
                validateReachability(adjacentVertex, forwardGraph, visitationState, reachableCount);
            }
        }
    }

    void extractMotherSet(int currentVertex, const vector<vector<int>>& reversedGraph, vector<bool>& visitationState, int& minimumMotherVertex) {
        visitationState[currentVertex] = true;
        minimumMotherVertex = min(minimumMotherVertex, currentVertex);
        
        for (const int adjacentVertex : reversedGraph[currentVertex]) {
            if (!visitationState[adjacentVertex]) {
                extractMotherSet(adjacentVertex, reversedGraph, visitationState, minimumMotherVertex);
            }
        }
    }
  public:
    int findMotherVertex(int V, vector<vector<int>>& edges) {
        // code here
        if (V <= 0) return -1;
        
        vector<vector<int>> forwardGraph(V);
        vector<vector<int>> reversedGraph(V);
        
        for (const auto& edge : edges) {
            if (edge.size() < 2) continue; 
            
            int origin = edge[0];
            int destination = edge[1];
            
            if (origin >= 0 && origin < V && destination >= 0 && destination < V) {
                forwardGraph[origin].push_back(destination);
                reversedGraph[destination].push_back(origin);
            }
        }
        
        vector<bool> forwardVisitation(V, false);
        int candidateVertex = -1;
        
        for (int i = 0; i < V; ++i) {
            if (!forwardVisitation[i]) {
                computeTopologicalCandidate(i, forwardGraph, forwardVisitation, candidateVertex);
            }
        }
        
        if (candidateVertex == -1) return -1;
        
        vector<bool> validationVisitation(V, false);
        int totalReachableNodes = 0;
        validateReachability(candidateVertex, forwardGraph, validationVisitation, totalReachableNodes);
        
        if (totalReachableNodes != V) {
            return -1;
        }
        
        vector<bool> reverseVisitation(V, false);
        int smallestMotherVertex = candidateVertex;
        
        //any node that can reach the validated mother vertex is also a mother vertex.
        //traversing the reversed graph from the candidate guarantees we isolate this exact set.
        extractMotherSet(candidateVertex, reversedGraph, reverseVisitation, smallestMotherVertex);
        
        return smallestMotherVertex;
    }
};