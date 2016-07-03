/*¡¢
350. Intersection of Two Arrays II My Submissions QuestionEditorial Solution
Total Accepted: 4984 Total Submissions: 11955 Difficulty: Easy
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to num2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
Subscribe to see which companies asked this question
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ret;
       
        for(auto it = nums2.begin();nums1.size()!=0&&it!=nums2.end();++it)
        {   
           for(auto it2 = nums1.begin();nums1.size()!=0&&it2!=nums1.end();++it2)
           {
               if(*it2==*it)
               {
                   ret.push_back(*it);
                   nums1.erase(it2);
                   break;
               }
           }
        }
        
        return ret;
    }
};