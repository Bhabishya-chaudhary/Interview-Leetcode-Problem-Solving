/******************************************** C++ ********************************************/
//Approach-1 (Simple DFS)
//T.C : O(m*n)
//S.C : O(1)

class Solution {
public:
   
    int m, n;
    vector<vector<int>> direction = {{0 , 1}, {0, -1}, {1, 0}, {-1, 0}};
    
      long long  DFS(int i, int j, vector<vector<int>>& grid) {
       long long sum = grid[i][j]; //value
          grid[i][j] = 0; //make visited 0

         for (vector<int>& dir : direction) {
           int i_ = i + dir[0];
           int j_ = j + dir[1];

           if(i_ >= 0 && i_ < m && j_ >= 0 && j_ < n && grid[i_][j_] > 0 ) {
            sum += DFS(i_, j_, grid);
           }
         }
         return sum; 
    }  

    int countIslands(vector<vector<int>>& grid, int k) {
         m = grid.size();
         n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m; i++) {
          for(int j = 0; j < n; j++) {
            if(grid[i][j] > 0) {
              long long sum = DFS(i, j, grid);
              if(sum % k == 0) 
                count ++;
            }
          }
       }
       return count;
    }
};