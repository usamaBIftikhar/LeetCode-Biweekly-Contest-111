class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=nums.size();
        for(int i = 0;i<=nums.size();i++){
            for(int j = i;j<=nums.size();j++){
                int sum=0;
                for(int k = 0;k<i;k++){
                    if(nums[k]!=1)sum++;  
                }
                for(int k = i;k<j;k++){
                    if(nums[k]!=2)sum++;
                }
                for(int k = j;k<nums.size();k++){
                    if(nums[k]!=3)sum++;
                }
                ans=min(ans,sum);
            }
        }
        return ans;
    }
};