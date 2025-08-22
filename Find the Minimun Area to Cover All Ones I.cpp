class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int firstRowOccurrence  = -1;
        int lastRowOccurrence  = -1;

        int firstColOccurrence = 1001;
        int lastColOccurrence = -1;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(firstRowOccurrence == -1  && grid[i][j] == 1) {
                    firstRowOccurrence = i;
                    
                }
                if(j < firstColOccurrence && grid[i][j] == 1) {
                    firstColOccurrence = j;
                }
                if(grid[i][j] == 1) {
                    lastRowOccurrence = i;
                    lastColOccurrence = max(lastColOccurrence,j);
                }
            }
        }

        if(firstRowOccurrence == -1 && firstColOccurrence == -1) return 0;

        int rowArea = (lastRowOccurrence + 1 - firstRowOccurrence) ;
        int colArea = (lastColOccurrence + 1 - firstColOccurrence) ;

        

        return rowArea  * colArea ;
        
    }
};
