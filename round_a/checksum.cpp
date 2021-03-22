#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vec_int;
typedef vector<vec_int> mat_int;
typedef pair<int, int> tup_int;
typedef pair<int, tup_int> tri_int;

int main() {
    int test_cases;
    cin >> test_cases;
    
    for (int t = 1; t <= test_cases; t++) {
        int n; 
        cin >> n;
        
        mat_int grid_a(n, vec_int(n, 0));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid_a[i][j];
        
        mat_int grid_b(n, vec_int(n, 0));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> grid_b[i][j];
        
        for (int i = 0, v = 0; i < 2*n; i++) cin >> v;
        
        priority_queue<tri_int> heap;
        long long graph_cost = 0;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid_a[i][j] == -1) {
                    graph_cost += grid_b[i][j];
                    heap.push(make_pair(grid_b[i][j], make_pair(i, n+j)));
                }
        
        vec_int c_checker(2*n, 0);
        for (int i = 0; i < 2*n; i++)
            c_checker[i] = i;
        
        long long tree_cost = 0;
        
        while (heap.size()) {
            int cost = heap.top().first;
            
            int i = heap.top().second.first;
            int j = heap.top().second.second;
            
            int x = i;
            while (x != c_checker[x]) 
                x = c_checker[x];
            
            int y = j;
            while (y != c_checker[y]) 
                y = c_checker[y];
            
            if (x != y) {
                tree_cost += cost;
                c_checker[y] = x;
            }
            
            heap.pop();
        }
        
        long long solution = graph_cost - tree_cost;
        
        cout << "Case #" << t << ": " << solution << endl;
    }

    return 0;
}
