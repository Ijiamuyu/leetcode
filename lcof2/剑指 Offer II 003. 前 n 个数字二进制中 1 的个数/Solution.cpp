class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i & (i - 1)] + 1;
        }
        return f;
    }
};

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        for(int i = 1; i <= n; i++)
        {
            ans.push_back(ans[i & (i - 1)] +1);
        }
        return ans;
    }
};
