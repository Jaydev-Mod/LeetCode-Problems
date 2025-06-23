class Solution {
public:
    bool isPrime(int a) {
        int ctn = 0;
        if (a <= 1) return false;
        else {
            for (int i = 1; i <= a; i++) {
                if (a % i == 0)
                    ctn++;
            }
            if (ctn > 2) return false;
            else return true;
        }
    }

    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }
        for (auto& a : freq) {
            if (isPrime(a.second)) {
                return true;
            }
        }
        return false;
    }
};