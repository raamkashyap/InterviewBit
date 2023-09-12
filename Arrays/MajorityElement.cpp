int Solution::majorityElement(const vector<int> &nums) {
    unordered_map<int,int> mp;
    int max = 0, maxele =0;
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
        if(mp[nums[i]]>max) {
            max = mp[nums[i]];
            maxele = nums[i];
        }
    }
    return maxele;
}
