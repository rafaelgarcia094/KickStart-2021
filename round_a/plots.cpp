#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vec_int;
typedef vector<vec_int> mat_int;

int main() {
    int tests_cases; 
    cin >> tests_cases;
    
    for (int t = 1; t <= tests_cases; t++) {
        int r, c; 
        cin >> r >> c;
        
        mat_int grid(r, vec_int(c, 0));
        
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> grid[i][j];
        
        vector<mat_int> t_grid(r, mat_int(c, vec_int(4, 0)));
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                t_grid[i][j][0] = grid[i][j];
                t_grid[i][j][1] = grid[i][j];
                t_grid[i][j][2] = grid[i][j];
                t_grid[i][j][3] = grid[i][j];
            }
        }
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c-1; j++)
                if (grid[i][j+1] && grid[i][j]) 
                    t_grid[i][j+1][0] += t_grid[i][j][0];
            
            for (int j = c-1; j > 0; j--)
                if (grid[i][j-1] && grid[i][j]) 
                    t_grid[i][j-1][1] += t_grid[i][j][1];
        }
        
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r-1; i++)
                if (grid[i+1][j] && grid[i][j]) 
                    t_grid[i+1][j][2] += t_grid[i][j][2];
            
            for (int i = r-1; i > 0; i--)
                if (grid[i-1][j] && grid[i][j])
                    t_grid[i-1][j][3] += t_grid[i][j][3];
        }
        
        int solution = 0;
        
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                for (int a = 0; a <= 1; a++)
                    for (int b = 2; b <= 3; b++) {
                        int k = min(t_grid[i][j][a], t_grid[i][j][b] / 2);
                
                        if (k > 1) {
                            solution += k - 1;
                        }
                        
                        
                        k = min(t_grid[i][j][b], t_grid[i][j][a] / 2);
                
                        if (k > 1) {
                            solution += k - 1;
                        }
                    }
        
        
        cout << "Case #" << t << ": " << solution << endl;
    }

    return 0;
}
