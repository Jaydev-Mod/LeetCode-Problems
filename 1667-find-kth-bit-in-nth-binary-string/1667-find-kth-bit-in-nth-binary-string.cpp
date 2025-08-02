class Solution {
public:
    char findKthBit(int n, int k) {
        string generated = "0";
        int curr = 1;
        while(curr <= n){
            string inverted = generated;
            for(char &c : inverted) {
                c = (c == '0') ? '1' : '0'; 
            }
            reverse(inverted.begin(), inverted.end());
            generated = generated + "1" + inverted;
            curr++;
        }
        if(k <= generated.size()) { 
            return generated[k-1];  
        }
        return '0';
    }
};