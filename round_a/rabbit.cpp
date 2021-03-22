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
        
        long long solution = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c-1; j++) {
                int v = max(grid[i][j+1], grid[i][j]-1);
                solution += v - grid[i][j+1];
                grid[i][j+1] = v;
            }
            
            for (int j = c-1; j > 0; j--) {
                int v = max(grid[i][j-1], grid[i][j]-1);
                solution += v - grid[i][j-1];
                grid[i][j-1] = v;
            }
        }
        
        for (int j = 0; j < c; j++) {
            for (int i = 0; i < r-1; i++) {
                int v = max(grid[i+1][j], grid[i][j]-1);
                solution += v - grid[i+1][j];
                grid[i+1][j] = v;
            }
            
            for (int i = r-1; i > 0; i--) {
                int v = max(grid[i-1][j], grid[i][j]-1);
                solution += v - grid[i-1][j];
                grid[i-1][j] = v;
            }
        }
        
        cout << "Case #" << t << ": " << solution << endl;
    }

    return 0;
}
