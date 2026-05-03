class Solution {
public:
    string addBinary(string a, string b) 
    {

        string ans = "";

        int n = a.size();
        int m = b.size();
        int rem = 0;
        int i = 0;
        int j = 0;

        while(i<n || j<m || rem > 0)
        {

            int digit_1 = (i < n) ? (a[n-i-1]-'0') : 0;
            int digit_2 = (j < m) ? (b[m-j-1]-'0') : 0;
            

            int temp = digit_1 + digit_2 + rem;
            rem = temp/2;

            int sum = temp%2;
            //cout<<a[n-i-1]-'0'<<" "<<b[m-j-1]-'0'<<" "<<sum<<" "<<rem<<endl;
            
            ans += sum+'0';
            i++;
            j++;

        }
        #if 0
        while(i<n)
        {
            int temp = (a[n-i-1]-'0') + rem;
            rem = temp/2;

            int sum = temp%2;
            cout<<a[n-i-1]-'0'<<" "<<sum<<" "<<rem<<endl;
            
            ans += sum+'0';
            i++;
        }

        while(j<m)
        {
            int temp = (b[m-j-1]-'0') + rem;
            rem = temp/2;

            int sum = temp%2;
            cout<<b[m-j-1]-'0'<<" "<<sum<<" "<<rem<<endl;
            
            ans += sum+'0';
            j++;

        }
        
        if(rem)
            ans += '1';
        #endif

        reverse(ans.begin(), ans.end());

        return ans;
        
    }
};