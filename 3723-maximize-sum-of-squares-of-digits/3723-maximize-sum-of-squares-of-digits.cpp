class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

      if(sum > num * 9) 
       return "";
        
        int nines = sum / 9;
        int remn = sum % 9;

        string result(nines, '9');

        if(remn > 0) {
          result.push_back(remn  + '0');
        }
        result.append (num - result.length(), '0');

        return result;
    }
};

 //T.C O(num)
 //S.C O(1)