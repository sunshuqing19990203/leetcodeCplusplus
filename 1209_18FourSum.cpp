class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        sort(nums.begin(),nums.end());
        // 双指针+两层循环
        // a = nums[k],k从0遍历到nums.size()-1;
        // b = nums[i],i从k+1遍历到nums.size()-1;
        // c = nums[left],left从i+1遍历到nums.size()-1;
        // d = nums[right],right从nums.size()-1遍历到left-1
        // a<=b<=c<=d

        for(int k = 0; k < nums.size(); k++){
            // 考虑特殊情况，减少时间消耗

            // ********这种方式是错误的********，会出现问题
            // if(nums[k] > target)
            //     return results;

            
            // 考虑去重
            if(k > 0 && nums[k] == nums[k - 1])
                continue;
            // 普遍情况下
            // 考虑b+c+d=target-a
            for(int i = k + 1; i < nums.size(); i++){
                int left = i + 1;
                int right = nums.size() - 1;
                // 考虑去重
                if(i > k + 1 && nums[i] == nums[i - 1])
                    continue;
                else{
                    while(left < right){
                        if(nums[k] + nums[i] + nums[left] + nums[right] < target)
                            left++;
                        else if(nums[k] + nums[i] + nums[left] + nums[right] > target)
                            right--;
                        else{
                            results.push_back(vector<int>{nums[k],nums[i],nums[left],nums[right]});
                            while(left < right && nums[left] == nums[left + 1])
                                left++;
                            while(left < right && nums[right] == nums[right - 1])
                                right--;
                            left++;
                            right--;
                        }
                    }
                }
            }
        }

        return results;
    }
};