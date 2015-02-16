#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i = stoi("01");
    cout << i << endl;

    string sa[] = {"1", "23", "456"};
    vector<string> v(sa, sa+3);
    sort(v.rbegin(), v.rend());
    for (auto &x : v) cout << x << ", " << endl;
}
