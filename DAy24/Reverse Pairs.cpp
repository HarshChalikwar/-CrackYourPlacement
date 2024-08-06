class Solution {
public:
    int merge(vector<int>& nums,int i,int m,int j)
    {
        int l = i;
        int h = m+1;
        int ans = 0;
        vector<int> temp;
        while(l<=m and h<=j)
        {
            if(nums[l] > 2*(long)nums[h])
            {
                ans += m-l+1;
                h++;
            }
            else
            {
                l++;
            }
        }
        l = i;
        h = m+1;
        while(l<=m and h<=j)
        {
            if(nums[l] <= nums[h])
            {
                temp.push_back(nums[l]);
                l++;
            }
            else
            {
                temp.push_back(nums[h]);
                h++;
            }
        }
        while(l<=m)
        {
            temp.push_back(nums[l]);
            l++;
        }
        while(h<=j)
        {
            temp.push_back(nums[h]);
            h++;
        }   
        for(int k = 0;k<temp.size();k++)
        {
            nums[i + k] = temp[k];
        }
        return ans;
    }
    int mergeSort(vector<int>& nums,int i,int j)
    {
        if(i==j) return 0;
        int m = (j+i)/2;
        int ans = 0;
        ans += mergeSort(nums,i,m);
        ans += mergeSort(nums,m+1,j);
        ans += merge(nums,i,m,j);
        return ans;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};