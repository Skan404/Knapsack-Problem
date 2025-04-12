#include <algorithm>
#include <iostream>
#include <vector>

#define QUERIES 500

using namespace std;

int main() {
    int query;
    int n;

    for (int q = 0; q < QUERIES; q++) {
        cin >> n;

        vector<int> values(n);
        vector<int> weights(n);

        for (int i = 0; i < values.size(); i++)
        {
            cin >> values[i];
        }

        for (int i = 0; i < weights.size(); i++)
        {
            cin >> weights[i];
        }

        cin >> query;

        vector<vector<int>> buff(n + 1, vector<int>(query + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= query; j++) {
                if (weights[i - 1] > j) {
                    buff[i][j] = buff[i - 1][j];
                }
                else {
                    int a = buff[i - 1][j];
                    int b = buff[i - 1][j - weights[i - 1]] + values[i - 1];
                    if (a>b)
                    {
                        buff[i][j] = a;
                    }
                    else
                    {
                        buff[i][j] = b;
                    }
                }
            }
        }
        cout << buff[n][query] << endl;
    }
    
    
    return 0;
}
