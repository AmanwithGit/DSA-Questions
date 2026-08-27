// LeetCode 78
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        function<void(int)> backtrack = [&](int index) {
            ans.push_back(current);

            for (int i = index; i < nums.size(); i++) {
                current.push_back(nums[i]);
                backtrack(i + 1);
                current.pop_back();
            }
        };

        backtrack(0);
        return ans;
    }
};