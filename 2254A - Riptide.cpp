#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    int rounds = 0;

    // Game continues as long as all three players have distinct token counts
    while (a != b && b != c && a != c) {
        vector<int> tokens = {a, b, c};
        
        // Find indices of minimum and maximum elements
        int min_idx = min_element(tokens.begin(), tokens.end()) - tokens.begin();
        int max_idx = max_element(tokens.begin(), tokens.end()) - tokens.begin();

        // Player with strictly most tokens gives 1 token to player with strictly fewest
        tokens[max_idx]--;
        tokens[min_idx]++;

        // Update a, b, c
        a = tokens[0];
        b = tokens[1];
        c = tokens[2];

        rounds++;
    }

    cout << rounds << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}