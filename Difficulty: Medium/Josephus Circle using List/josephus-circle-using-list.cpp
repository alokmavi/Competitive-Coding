// User function Template for C++

int josephus(int n, int k) {
    // code here
    list<int> people;
        
        for (int i = 1; i <= n; ++i) {
            people.push_back(i);
        }
        
        auto it = people.begin();
        
        while (people.size() > 1) {
            // Move (k-1) steps forward
            for (int i = 1; i < k; ++i) {
                ++it;
                if (it == people.end()) {
                    it = people.begin();
                }
            }
            auto next_it = std::next(it);
            
            if (next_it == people.end()) {
                next_it = people.begin();
            }
            
            // Erase the current person
            people.erase(it);
            
            // Move to the next person for the next round
            it = next_it;
        }
        
        return *people.begin();
}