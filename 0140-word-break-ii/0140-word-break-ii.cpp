// LeetCode 140
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;

        function<vector<string>(int)> dfs = [&](int start) {
            if (memo.count(start))
                return memo[start];

            vector<string> result;

            if (start == s.size()) {
                result.push_back("");
                return result;
            }

            for (int end = start + 1; end <= s.size(); end++) {
                string word = s.substr(start, end - start);

                if (!dict.count(word))
                    continue;

                vector<string> suffixes = dfs(end);

                for (string suffix : suffixes) {
                    if (suffix.empty())
                        result.push_back(word);
                    else
                        result.push_back(word + " " + suffix);
                }
            }

            return memo[start] = result;
        };

        return dfs(0);
    }
};