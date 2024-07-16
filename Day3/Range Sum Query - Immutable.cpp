class NumArray {
public:
    vector<int> seg;
    int n;
    void create_seg(vector<int>& nums,int l,int r,int i)
    {
        n = nums.size();
        if(l == r)
        {
            seg[i] = nums[l];
            return;
        }
        int mid = l + (r-l)/2;
        create_seg(nums,l,mid,i*2 + 1);
        create_seg(nums,mid+1,r,i*2 + 2);
        seg[i] = seg[i*2 + 1] + seg[i*2 + 2];
    }
    NumArray(vector<int>& nums) {
        seg.resize(4*nums.size() + 1,0);
        create_seg( nums,0,nums.size()-1,0);
    }
    long find_sum(int l,int r, int left ,int right,int i)
    {
        if(left <= l and r <= right) return seg[i];
        if(r<left or l > right) return 1e13;
        int mid = l + (r-l)/2;
        long sum = 0;
        long sum1 = find_sum(l,mid,left,right,2*i+1);
        long sum2 =  find_sum(mid+1,r,left,right,2*i+2);
        if(sum1 != 1e13) sum += sum1;
        if(sum2 != 1e13) sum += sum2;
        return sum;
    }
    int sumRange(int left, int right) {
           return (int)find_sum(0,n-1,left,right,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */