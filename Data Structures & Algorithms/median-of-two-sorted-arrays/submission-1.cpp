class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {

        // 1 3 => 1
        // 2 4 => 2

        // 1 3 5 7 9
        // 2 4 6 8 10
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nums3(n+m, 0);
        int i = 0;
        int l = 0, r = 0;
        while(l < n && r < m)
        {
            if(nums1[l] < nums2[r])
            {
                nums3[i] = nums1[l];
                l++;
            }
            else
            {
                nums3[i] = nums2[r];
                r++;
            }
            i++;
        }

        while(l < n)
        {
            nums3[i] = nums1[l];
            l++;
            i++;
        }

        while(r < m)
        {
            nums3[i] = nums2[r];
                r++;
            i++;
        }

        double ans = 0;
        int index = (n+m);
        if((index)%2)
        {
            //cout<<index<<" if "<<endl;
            ans = nums3[index/2];
        }
        else
        {
            //cout<<nums3[(index/2)-1]<<" "<<nums3[(index/2)]<<" else "<<endl;
            ans = (nums3[(index/2)-1]+ nums3[index/2])/2.0;
        }

        return ans;
    }
};
