class NumArray {
public:
    vector<int> seg;
    int n;
    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4*nums.size() + 1);
        create_seg(nums,0,n-1,0);
    }
    void create_seg(vector<int>& nums,int l,int r,int i)
    {
        if(l == r)
        {
            seg[i] = nums[l];
            return;
        }
        int mid = l+ (r-l)/2;
        create_seg(nums,l,mid,2*i+1);
        create_seg(nums,mid+1,r,2*i+2);
        seg[i] = seg[2*i+1] + seg[2*i+2];
    }
    void update_seg(int l,int r,int i,int index,int val)
    {
        if(l == r and l==index) 
        {
            seg[i] = val;
            return;
        }
        int mid = l + (r-l)/2;
        if(index <= mid)
        update_seg(l,mid,2*i+1,index,val);
        else update_seg(mid+1,r,2*i+2,index,val);
        seg[i] = seg[2*i+1]+seg[2*i+2];
    }
    void update(int index, int val) {
        update_seg(0,n-1,0,index,val);
    }
    long find_sum(int left,int right,int l,int r,int i)
    {
        if(left<=l and r <= right) return seg[i];
        if(r<left or l > right) return 1e13;
        long ans = 0;
        int m = l + (r-l)/2;
        long ans1 = find_sum(left,right,l,m,2*i+1);
        long ans2 = find_sum(left,right,m+1,r,2*i+2);
        if(ans1 != 1e13) ans += ans1;
        if(ans2 != 1e13) ans += ans2;
        return ans;
    }
    int sumRange(int left, int right) {
        return (int)find_sum(left,right,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */