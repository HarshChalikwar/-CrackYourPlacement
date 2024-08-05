class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int r = m+n-1;
        // if(i == -1) nums1 = nums2;
        while(i>= 0 and j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                swap(nums1[i],nums1[r]);
                r--;i--;
            }
            else
            {
                swap(nums2[j],nums1[r]);
                r--;j--;
            }
        }
        while(j>=0){
            swap(nums2[j],nums1[r]);
                r--;j--;
        }
        while(i>=0){
            swap(nums1[i],nums1[r]);
                r--;i--;
        }
    }
};