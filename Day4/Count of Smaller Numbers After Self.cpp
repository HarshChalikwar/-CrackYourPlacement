class Solution {
public:
    vector<int> cnt;
    void merge(vector<pair<int,int>>& nums2,int i,int m,int j,vector<int>& nums)
    {
        int l = i;
        int h = m+1;
        vector<pair<int,int>> temp;
        int count = 0;
        while(l<=m and h<=j)
        {
            if(nums2[l].first <= nums2[h].first)
            {
                temp.push_back(nums2[l]);
                cnt[nums2[l].second] += count;
                l++;
            }
            else
            {
                temp.push_back(nums2[h]);
                h++;
                count++;
            }
        }
        while(l<=m)
        {
            temp.push_back(nums2[l]);
            cnt[nums2[l].second] += count;
            l++;
        }
        while(h<=j)
        {
            temp.push_back(nums2[h]);
            h++;
        }
        for(int c = 0;c<temp.size();c++)
        {
            nums2[i+c] = temp[c];
        }
    }
    void mergeSort(vector<pair<int,int>>& nums2,int i,int j,vector<int>& nums)
    {
        if(i == j) return;
        int m = i + (j-i)/2;
        mergeSort(nums2,i,m,nums);
        mergeSort(nums2,m+1,j,nums);
        merge(nums2,i,m,j,nums);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> nums2;
        cnt.resize(nums.size());
        for(int i = 0;i<nums.size();i++)
        {
            nums2.push_back({nums[i],i});
        }
        mergeSort(nums2,0,nums2.size()-1,nums);
        return cnt;
    }
};