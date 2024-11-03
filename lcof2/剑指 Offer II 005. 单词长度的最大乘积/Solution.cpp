class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        int mask[n];
        memset(mask, 0, sizeof(mask));
        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                mask[i] |= 1 << (c - 'a');
            }
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((mask[i] & mask[j]) == 0) {
                    ans = max(ans, int(words[i].size() * words[j].size()));
                }
            }
        }
        return ans;
    }
};

int string_to_int(string word)
{
    int ret = 0;
    for(int i = 0; i < word.size(); i++)
    {
        ret |= 1 << (word[i] - 'a');
    }
    return ret;
}

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int max = 0, numa = 0, numb = 0;
        int i, j;
        for(i = 0; i < words.size() - 1; i++)
        {
            numa = string_to_int(words[i]);
            for(j = i + 1;j < words.size(); j++)
            {
                numb = string_to_int(words[j]);
                if( !(numa & numb))
                {
                    max = max > words[i].size() * words[j].size() ? max : words[i].size() * words[j].size();
                }
            }
        }
        return max;
    }
};