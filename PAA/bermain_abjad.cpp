#include <iostream>
#include <array>
#include <string.h>

std::array<std::array<bool, 5>, 5> flag;
std::array<std::array<char, 5>, 5> board;
std::string answer;

bool traverseBoard(int answer_index, int x, int y) {
    // base case
    if (answer_index >= answer.length()) {
        return true;
    }

    // exception handling
    if (x < 0 || x >= 5 || y < 0 || y >= 5) {
        return false;
    }

    // check if the current cell is already visited
    if (flag[x][y]) {
        return false;
    }

    // return false if the current cell is not the answer
    if (board[x][y] != answer[answer_index]) {
        return false;
    }

    // check if the current cell is the answer
    if (board[x][y] == answer[answer_index]) {
        flag[x][y] = true;
        bool found = traverseBoard(answer_index + 1, x + 1, y) ||
                     traverseBoard(answer_index + 1, x - 1, y) ||
                     traverseBoard(answer_index + 1, x, y + 1) ||
                     traverseBoard(answer_index + 1, x, y - 1);
        flag[x][y] = false;
        return found;
    }
}

int main() {
    flag.fill({false, false, false, false, false});
    board.fill({' ', ' ', ' ', ' ', ' '});

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> board[i][j];
        }
    }

    std::cin >> answer;

    bool found = false;

    // Traverse board
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 && !found; j++) {
            if (board[i][j] == answer[0]) {
                found = traverseBoard(0, i, j);
            }
        }
    }
    std::cout << (found ? "ADA" : "TIDAK ADA") << std::endl;
}
