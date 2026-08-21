// LeetCode 17
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> mp = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;

        function<void(int, string)> backtrack =
            [&](int index, string current) {
                if (index == digits.size()) {
                    ans.push_back(current);
                    return;
                }

                for (char c : mp[digits[index] - '0']) {
                    backtrack(index + 1, current + c);
                }
            };

        backtrack(0, "");

        return ans;
    }
};