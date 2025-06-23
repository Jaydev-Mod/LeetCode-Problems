class Solution {
public:
    bool isPalindromeInBase(long long a, int k) {
        if (a == 0) return true;
        
        vector<char> s;
        while (a > 0) {
            int digit = a % k;
            char c = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
            s.push_back(c);
            a /= k;
        }
        
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    long long createPalindrome(int num, bool isOddLength) {
        long long palindrome = num;
        if (isOddLength) num /= 10;
        while (num > 0) {
            palindrome = palindrome * 10 + num % 10;
            num /= 10;
        }
        return palindrome;
    }
    long long kMirror(int k, int n) {
        long long ans = 0;
        int count = 0;
        
        for (int length = 1; count < n; length++) {
            int start = pow(10, (length - 1) / 2);
            int end = pow(10, (length + 1) / 2);
            
            for (int num = start; num < end && count < n; num++) {
                long long palindrome = createPalindrome(num, length % 2 != 0);
                if (isPalindromeInBase(palindrome, k)) {
                    ans += palindrome;
                    count++;
                }
            }
        }
        return ans;
    }
};