/*********************************************************** C++ **************************************************/
//Approach-1 (Brute Force)
//T.C : The time complexity is O(n log n + m log n), where n = arr2.size() and m = arr1.size().
//- Sorting arr2 takes O(n log n).
//- For each of the m values in arr1, lower_bound takes O(log n).
//The extra space is O(1), excluding any space used internally by sort.
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int n = arr2.size();
        int count = 0;
        
        for(int i = 0; i < arr1.size(); i++) {
        int j = lower_bound(begin(arr2), end(arr2), arr1[i]) - begin(arr2); //pointer-->index

         if(j == 0) { //all element are greater and equal to arr1[i] 
             count += (arr2[0] - arr1[i]) > d;
         }  else if (j >= n) {  //all element are small then  arr1[i] 
             count += (arr1[i] - arr2[n-1]) > d;
         } else {
             count += (arr2[j] - arr1[i] > d) && (arr1[i] - arr2[j-1] > d);
          }
        }
        return count;
    }
};
