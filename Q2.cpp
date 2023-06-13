#include <iostream>
#include <string>
using namespace std;

const string INTERLEAVING_OUTPUT = "Interleaving";
const string NOT_INTERLEAVING_OUTPUT = "Not Interleaving";

bool is_interleaving(string &first_str, string &second_str, string &permutation, int index_1, int index_2, int index_p)
{
    if (index_p >= permutation.size() && index_1 >= first_str.size() && index_2 >= second_str.size())
        return true;
    if (index_p >= permutation.size())
        return false;
    if ((permutation[index_p] == first_str[index_1]) && (permutation[index_p] == second_str[index_2]))
        return (is_interleaving(first_str, second_str, permutation, index_1 + 1, index_2, index_p + 1) ||
                is_interleaving(first_str, second_str, permutation, index_1, index_2 + 1, index_p + 1));
    if (permutation[index_p] == first_str[index_1])
        return is_interleaving(first_str, second_str, permutation, index_1 + 1, index_2, index_p + 1);
    if (permutation[index_p] == second_str[index_2])
        return is_interleaving(first_str, second_str, permutation, index_1, index_2 + 1, index_p + 1);
    return false;
}

int main()
{
    string first_str, second_str, permutation;
    cin >> first_str >> second_str >> permutation;
    if (is_interleaving(first_str, second_str, permutation, 0, 0, 0))
        cout << INTERLEAVING_OUTPUT;
    else
        cout << NOT_INTERLEAVING_OUTPUT;
}