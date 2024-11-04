class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0, n = numbers.size();; ++i) {
            int x = target - numbers[i];
            int j = lower_bound(numbers.begin() + i + 1, numbers.end(), x) - numbers.begin();
            if (j < n && numbers[j] == x) {
                return {i, j};
            }
        }
    }
};


//leetcode题目，下标不同
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        for(int i = 0; i < numbers.size(); i++)
        {
            int x = target - numbers[i];
            int j = lower_bound(numbers.begin() + i + 1, numbers.end(), x) - numbers.begin();
            if( j < numbers.size() && numbers[j] == x)
            {
                ans.push_back(i + 1);
                ans.push_back(j + 1);
                break;
            }
        }
        return ans;
    }
};