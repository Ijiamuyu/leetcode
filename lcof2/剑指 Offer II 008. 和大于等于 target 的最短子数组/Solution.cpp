class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int inf = 1 << 30;
        int ans = inf;
        int n = nums.size();
        int s = 0;
        for (int i = 0, j = 0; j < n; ++j) {
            s += nums[j];
            while (s >= target) {
                ans = min(ans, j - i + 1);
                s -= nums[i++];
            }
        }
        return ans == inf ? 0 : ans;
    }
};

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int length = INT_MAX, sum = 0;
        for(int fast = 0, slow = 0; fast < nums.size(); fast++)
        {
            sum += nums[fast];
            while(sum >= target)
            {
                length = min(length, fast - slow + 1);
                sum -= nums[slow++];
            }
        }
        return length == INT_MAX ? 0 : length;
    }
};