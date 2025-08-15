class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        while(n > 0){
            if(n == 1) return true;
            if(n %4 != 0) return false;
            n /= 4;
        }
        return false;
    }
};

// Time Complexity O(Logn)
// Space Complexity O(1)


// O(1) Code
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 and (n & n-1) == 0 and (n-1)%3 == 0;
    }
};
