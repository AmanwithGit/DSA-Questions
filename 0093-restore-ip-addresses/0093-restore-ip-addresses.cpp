// LeetCode 93
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string current;

        function<void(int, int)> backtrack =
            [&](int index, int parts) {
                if (parts == 4) {
                    if (index == s.size())
                        ans.push_back(current);
                    return;
                }

                int remaining = s.size() - index;

                if (remaining < (4 - parts) ||
                    remaining > 3 * (4 - parts))
                    return;

                for (int len = 1; len <= 3; len++) {
                    if (index + len > s.size())
                        break;

                    string part = s.substr(index, len);

                    if (part.size() > 1 && part[0] == '0')
                        break;

                    if (stoi(part) > 255)
                        break;

                    int oldSize = current.size();

                    if (!current.empty())
                        current += '.';

                    current += part;

                    backtrack(index + len, parts + 1);

                    current.resize(oldSize);
                }
            };

        backtrack(0, 0);
        return ans;
    }
};