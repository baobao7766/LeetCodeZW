
#include <vector>

using namespace std;

class Solution {
public:
	Solution(){
		int a[4][2] = {{-1,0}, {0,-1}, {1,0},{0,1}};
		this->dir[4][2] = a[4][2];
	}
    int dir[4][2];
    void dfs(vector<vector<char> > &grid, int x, int y) {
        grid[x][y] = '0';
        for(int k=0;k<4;k++) {
            int nx = x+dir[k][0];
            int ny = y+dir[k][1];
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size())
                if(grid[nx][ny]=='1')
                    dfs(grid, nx, ny);
        }
    }
    int numIslands(vector<vector<char> > &grid) {
        int m = grid.size();
        if(m==0)
            return 0;
        int n = grid[0].size();
        int res = 0;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]=='1') {
                    dfs(grid, i, j);
                    res++;
                }
        return res;
    }
};

//int main()
//{
//	
//	return 0;
//}