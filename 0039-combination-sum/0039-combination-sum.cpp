// LeetCode 39
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        function<void(int, int)> backtrack = [&](int start, int remaining) {
            if (remaining == 0) {
                ans.push_back(current);
                return;
            }

            for (int i = start; i < candidates.size(); i++) {
                if (candidates[i] > remaining)
                    continue;

                current.push_back(candidates[i]);
                backtrack(i, remaining - candidates[i]);
                current.pop_back();
            }
        };

        backtrack(0, target);
        return ans;
    }
};