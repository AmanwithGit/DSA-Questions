// LeetCode 47
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        vector<bool> used(nums.size(), false);
        vector<int> current;

        function<void()> backtrack = [&]() {
            if (current.size() == nums.size()) {
                ans.push_back(current);
                return;
            }

            for (int i = 0; i < nums.size(); i++) {
                if (used[i])
                    continue;

                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                    continue;

                used[i] = true;
                current.push_back(nums[i]);

                backtrack();

                current.pop_back();
                used[i] = false;
            }
        };

        backtrack();
        return ans;
    }
};