#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string BALANCABLE = "True";
const string UNBALANCABLE = "False";

bool balance(vector<int> rocks, int goal, int section1, int section2, int index)
{
    if (section1 == section2)
        return true;
    if (index >= rocks.size())
        return false;
    if (balance(rocks, goal, section1 + rocks[index], section2, index + 1) || balance(rocks, goal, section1, section2 + rocks[index], index + 1) ||
        balance(rocks, goal, section1, section2, index + 1))
        return true;
    return false;
}

vector<int> read_rocks(int rock_number)
{
    vector<int> rocks;
    for (int rock_count = 0; rock_count < rock_number; rock_count++)
    {
        int rock_weight;
        cin >> rock_weight;
        rocks.push_back(rock_weight);
    }
    return rocks;
}

int main()
{
    int rock_number, goal;
    cin >> rock_number >> goal;
    vector<int> rocks = read_rocks(rock_number);
    int section1 = goal, section2 = 0;
    if (balance(rocks, goal, section1, section2, 0))
        cout << BALANCABLE;
    else
        cout << UNBALANCABLE;
    return 0;
}
