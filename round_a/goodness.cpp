#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int test_cases; 
    cin >> test_cases;

    for (int t = 1; t <= test_cases; t++) {
        int n, k;
        cin >> n >> k;
        
        string s;
        cin >> s;

        for (int i = 0; i < n/2; i++)
            if (s[i] != s[n-i-1])
                k -= 1;

        int r = abs(k);

        cout << "Case #" << t << ": " << r << endl;
    }

    return 0;
}