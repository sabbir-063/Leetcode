class Solution {
public:
    bool reorderedPowerOf2(int n) {
        vector<string>v;
        int x=1;
        while(x <= 1e9){
            v.push_back(to_string(x));
            x <<= 1;
        }

        string t = to_string(n);
        sort(t.begin(), t.end());
        
        do{
            if(t[0] == '0') continue;
            for(auto it : v){
                if(it == t) return true;
            }
        }while(next_permutation(t.begin(), t.end()));

        return false;
    }
};
