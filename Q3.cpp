#include <iostream>
#include <string>
#include <vector>
using namespace std;

const char EMPTY = '.';
const char ROCK = '#';
const char BAMBOO = '*';
const char PASSED = '0';

const int START_ROW = 0;
const int START_COL = 0;

const int FIRST_DIR_ROW[2] = {1, 0};
const int FIRST_DIR_COL[2] = {0, 1};

const int BIG_NUMBER = 100000;
const string NO_PATH = "No path found\n";

bool is_legal_move(vector<string> &board, int panda_row, int panda_col)
{
    if (panda_row >= board.size() || panda_row < 0 || panda_col >= board[0].size() || panda_col < 0 || board[panda_row][panda_col] == ROCK)
        return false;
    else
        return true;
}

void next_directions(int delta_row, int &next_dir_row1, int &next_dir_col1, int &next_dir_row2, int &next_dir_col2)
{
    if (delta_row == 0)
    {
        next_dir_row1 = 1;
        next_dir_row2 = -1;
        next_dir_col1 = next_dir_col2 = 0;
    }
    else
    {
        next_dir_row1 = next_dir_row2 = 0;
        next_dir_col1 = 1;
        next_dir_col2 = -1;
    }
}

void find_path(vector<string> &board, int panda_row, int panda_col, int &shortest_path, int path_length, int delta_row, int delta_col)
{
    if (!is_legal_move(board, panda_row + delta_row, panda_col + delta_col))
        return;
    int add_to_path = 0;
    while (is_legal_move(board, panda_row + delta_row, panda_col + delta_col))
    {
        panda_row += delta_row;
        panda_col += delta_col;
        add_to_path++;
        if (board[panda_row][panda_col] == BAMBOO)
        {
            path_length += add_to_path;
            if (path_length < shortest_path)
                shortest_path = path_length;
            path_length = 0;
            return;
        }
    }
    if (board[panda_row][panda_col] == PASSED)
        return;
    path_length += add_to_path;
    board[panda_row][panda_col] = PASSED;
    int next_dir_row1, next_dir_col1, next_dir_row2, next_dir_col2;
    next_directions(delta_row, next_dir_row1, next_dir_col1, next_dir_row2, next_dir_col2);

    find_path(board, panda_row, panda_col, shortest_path, path_length, next_dir_row1, next_dir_col1);
    find_path(board, panda_row, panda_col, shortest_path, path_length, next_dir_row2, next_dir_col2);

    path_length -= add_to_path;
    board[panda_row][panda_col] = EMPTY;
}

int main()
{
    vector<string> board;
    string input_string;
    while (cin >> input_string)
        board.push_back(input_string);
    int shortest_path = BIG_NUMBER, path_length = 0;
    board[START_ROW][START_COL] = PASSED;
    find_path(board, START_ROW, START_COL, shortest_path, path_length, FIRST_DIR_ROW[0], FIRST_DIR_COL[0]);
    find_path(board, START_ROW, START_COL, shortest_path, path_length, FIRST_DIR_ROW[1], FIRST_DIR_COL[1]);
    if (shortest_path == BIG_NUMBER)
        cout << NO_PATH;
    else
        cout << shortest_path << endl;
    return 0;
}