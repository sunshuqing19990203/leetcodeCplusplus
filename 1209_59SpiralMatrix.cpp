// 1209 孙书情
// 螺旋矩阵II
// 左闭右开


class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // 坚持左闭右开的原则
        // 循环次数为n/2
        vector<vector<int>> matrix(n,vector<int>(n,0));
        int loop = n / 2;
        int startx = 0;
        int starty = 0;
        int offset = 1;
        int count = 1;
        while(loop--){
        // 四个步骤为一轮：
        // 从左到右横坐标不变为startx，纵坐标[starty,starty+n-offset),
        // 从上到下横[startx,startx+n-offset)
        // 从右向左[上一次过程的初值，startx),与上一个过程中纵坐标相同)
        // 从下到上，纵坐标与上一个过程相同，横从初值到startx）
        int i = startx;
        int j = starty;
        for(; j < starty + n - offset; j++)
            matrix[i][j] = count++;
        for(; i < startx + n -offset; i++)
            matrix[i][j] = count++;
        for(; j > starty; j--)
            matrix[i][j] = count++;
        for(; i > startx; i--)
            matrix[i][j] = count++;
        
        startx++;
        starty++;
        offset = offset + 2;
        }
        if(n % 2)
            matrix[n / 2][n / 2] = count;
        
        return matrix;
    
    }
};