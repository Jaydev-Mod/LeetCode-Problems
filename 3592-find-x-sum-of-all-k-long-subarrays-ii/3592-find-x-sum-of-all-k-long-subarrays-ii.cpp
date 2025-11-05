class Solution {
    // We use long long for sums to prevent overflow
    long long xSum = 0;
    // Sets to maintain the two groups, sorted by {frequency, value}
    set<pair<int, int>> topX;
    set<pair<int, int>> others;
    // Map to track frequencies
    unordered_map<int, int> freq;
    
    // Helper to remove a value.
    // Finds its {freq, val} pair, removes it from the correct set,
    // and updates xSum if it was in topX.
    void remove(int val) {
        int f = freq[val];
        pair<int, int> p = {f, val};
        
        if (topX.count(p)) {
            topX.erase(p);
            xSum -= (long long)p.first * p.second;
        } else if (others.count(p)) {
            others.erase(p);
        }
    }
    
    // Helper to add a value.
    // Finds its {freq, val} pair, inserts it into 'others',
    // (We add to 'others' and let rebalance fix it).
    void add(int val) {
        int f = freq[val];
        pair<int, int> p = {f, val};
        if (f > 0) {
            others.insert(p);
        }
    }
    
    // Helper to rebalance the two sets to maintain the Top X.
    void rebalance(int x) {
        // 1. Fill topX if it's not full
        while (topX.size() < x && !others.empty()) {
            auto p = *others.rbegin(); // Best of 'others'
            others.erase(p);
            xSum += (long long)p.first * p.second;
            topX.insert(p);
        }
        
        // 2. If topX is overfull (can happen if x=0), move worst to others
        while (topX.size() > x) {
            auto p = *topX.begin(); // Worst of 'topX'
            topX.erase(p);
            xSum -= (long long)p.first * p.second;
            others.insert(p);
        }

        // 3. Swap if worst of topX is "worse" than best of others
        while (!topX.empty() && !others.empty() && *topX.begin() < *others.rbegin()) {
            auto pTop = *topX.begin();
            auto pOth = *others.rbegin();
            
            topX.erase(pTop);
            xSum -= (long long)pTop.first * pTop.second;
            others.insert(pTop);
            
            others.erase(pOth);
            xSum += (long long)pOth.first * pOth.second;
            topX.insert(pOth);
        }
    }

public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> answer;
        long long windowSum = 0;
        
        // 1. Initialize the first window
        for (int i = 0; i < k; ++i) {
            windowSum += nums[i];
            freq[nums[i]]++;
        }
        
        // 2. Create the initial 'others' set
        for (auto const& [val, f] : freq) {
            others.insert({f, val});
        }
        
        // 3. Perform initial balance
        rebalance(x);
        
        // 4. Store the first answer
        if (topX.size() + others.size() <= x) {
            answer.push_back(windowSum);
        } else {
            answer.push_back(xSum);
        }
        
        // 5. Slide the window from k to n-1
        for (int i = k; i < n; ++i) {
            int enteringVal = nums[i];
            int leavingVal = nums[i - k];
            
            // Update total window sum
            windowSum = windowSum - leavingVal + enteringVal;
            
            // --- Remove leavingVal ---
            remove(leavingVal); // Remove its {oldFreq, val} pair
            freq[leavingVal]--;  // Decrement frequency
            add(leavingVal);     // Add its {newFreq, val} pair back (if freq > 0)
            
            // --- Add enteringVal ---
            remove(enteringVal); // Remove its {oldFreq, val} pair (if it exists)
            freq[enteringVal]++;   // Increment frequency
            add(enteringVal);      // Add its {newFreq, val} pair
            
            // --- Rebalance and store ---
            rebalance(x);
            
            if (topX.size() + others.size() <= x) {
                answer.push_back(windowSum);
            } else {
                answer.push_back(xSum);
            }
        }
        
        return answer;
    }
};