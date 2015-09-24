#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:    
    vector<vector<int> > threeSum(vector<int>& nums) {        
        vector<vector<int> > result;        
        if (nums.size() < 3)            
        return result;                
        sort(nums.begin(), nums.end());        
        int begin = 0;        
        int last =  nums.size() - 1;        
        for (; begin < nums.size() - 2; ++begin)        {   
            vector<int> temp;
            int center = begin + 1;            
            if (begin > 0 && nums[begin] == nums[begin - 1])                
                continue;            
            int end = last - 1;            
            while (center < end)            
            {                
                if (nums[begin] + nums[center] + nums[end] < 0) {                    
                     ++center;                    
                     while (nums[center] == nums[center - 1] && center < end)                        
                        ++center;                
                    
                }                
                else if (nums[begin] + nums[center] + nums[end] > 0) {                    
                    --end;                    
                    while (nums[end] == nums[end + 1] && center < end)                        
                    --end;                
                }                
                else                
                {        
                    temp.push_back(nums[begin]);
                    temp.push_back(nums[center]);
                    temp.push_back(nums[end]);
                    result.push_back(temp);  
                    temp.clear();
                    ++center;                    
                    --end;                    
                    while (nums[center] == nums[center - 1] && nums[end] == nums[end + 1] && center < end)                      
                        ++center;                
                    
                }            
            }        
            
        }        
        return result;    
    }
    
};

int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(-1);
    a.push_back(-1);
    a.push_back(0);

    Solution test;
    vector<vector<int> > result;
    result = test.threeSum(a);
    cout << result.size() << endl;

    return 0;
}
