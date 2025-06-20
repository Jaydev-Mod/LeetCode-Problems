class Solution {
public:
    bool isFreqSame(vector<int> freq1, vector<int> freq2){
        for(int i = 0; i < freq1.size(); i++){
            if(freq1[i]!=freq2[i]){
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26, 0);
        for(int i = 0; i < s1.length(); i++){
            freq1[s1[i]-'a']++;
        }
        int windowLen = s1.length();
        
        for(int i = 0; i < s2.length(); i++){
            int windowIdx = 0;
            int idx = i;
            vector<int> freq2(26, 0);
            while(windowIdx < windowLen && idx < s2.length()){
                freq2[s2[idx]-'a']++;
                idx++;
                windowIdx++;
            }
            if(isFreqSame(freq1, freq2)){
                return true;
            }
        }
        return false;
    }
};