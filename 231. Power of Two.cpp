class Solution {
public:
    bool isPowerOfTwo(int n) {
        long long val=1LL;
        while(true){
            if(val == n) return true;
            if(val > n) return false;
            val = val << 1;
        }
        return true;
    }
};
