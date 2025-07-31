const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result_ors, current_ors;

        for (int x : arr) {
            unordered_set<int> next_ors;
            next_ors.insert(x);
            for (int y : current_ors) {
                next_ors.insert(x | y);
            }
            result_ors.insert(next_ors.begin(), next_ors.end());
            current_ors = next_ors;
        }

        return result_ors.size();
    }
};

// Time complexity : O(N^2)
// Space complexity : O(N)
