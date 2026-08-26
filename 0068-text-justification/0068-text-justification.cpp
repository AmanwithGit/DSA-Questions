// LeetCode 68
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i;
            int lineLength = 0;

            while (j < n &&
                   lineLength + words[j].size() + (j - i) <= maxWidth) {
                lineLength += words[j].size();
                j++;
            }

            int spaces = maxWidth - lineLength;
            int gaps = j - i - 1;

            string line;

            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    if (k > i)
                        line += ' ';
                    line += words[k];
                }

                line += string(maxWidth - line.size(), ' ');
            } else {
                int each = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];

                    if (k < j - 1) {
                        line += string(each + (k - i < extra ? 1 : 0), ' ');
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};