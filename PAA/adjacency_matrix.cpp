/*
Hanun Shaka P - 5025211051

Problem:
In a social network, there are N users represented by integers from 0 to N-1.
Each user can have connections (friendship) with other users.
Given the friendship connections between users in the form of an adjacency matrix:
a. How many friends does user A has ?
b. Find the user who has the most friends.
c. Find the user who has the least friends.
d. How many mutual friends do user C and user D have ?
*/

#include <bits/stdc++.h>
#include <vector>

int get_number_of_friends(char, std::vector<std::vector<int>>);
std::vector<char> get_most_friends(std::vector<std::vector<int>>);
std::vector<char> get_least_friends(std::vector<std::vector<int>>);
std::vector<char> get_mutual_friends(char, char, std::vector<std::vector<int>>);

int main() {
    // Two-dimensional vector for adjacency matrix
    std::vector<std::vector<int>> adj_matrix;

    // Append row to the matrix
    adj_matrix.push_back({0, 1, 0, 1, 0, 0});
    adj_matrix.push_back({1, 0, 1, 0, 0, 0});   
    adj_matrix.push_back({0, 1, 0, 0, 1, 0});
    adj_matrix.push_back({1, 0, 0, 0, 1, 0});
    adj_matrix.push_back({0, 0, 1, 1, 0, 1});
    adj_matrix.push_back({0, 0, 0, 0, 1, 0});

    // Print header
    std::cout << "  A B C D E F" << std::endl;

    // Print the adjacency matrix
    for (int i = 0; i < adj_matrix.size(); i++) {
        std::cout << char(i + 65) << " ";
        for (int j = 0; j < adj_matrix[i].size(); j++) {
            std::cout << adj_matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    // Get the number of friends of user A
    std::cout << "a. User A has " << get_number_of_friends('A', adj_matrix) << " friends." << std::endl;

    // Get the user who has the most friends
    std::vector<char> most_friends = get_most_friends(adj_matrix);
    std::cout << "b. User(s) who has the most friends: " << std::endl;
    for (int i = 0; i < most_friends.size(); i++) {
        std::cout << "   " << most_friends[i] << " has " << get_number_of_friends(most_friends[i], adj_matrix) << " friends" << std::endl;
    }

    // Get the user who has the least friends
    std::vector<char> least_friends = get_least_friends(adj_matrix);
    std::cout << "c. User(s) who has the least friends: " << std::endl;
    for (int i = 0; i < least_friends.size(); i++) {
        std::cout << "   " << least_friends[i] << " has " << get_number_of_friends(least_friends[i], adj_matrix) << " friends" << std::endl;
    }

    // Get the number of mutual friends of user C and user D
    std::vector<char> mutual_friends = get_mutual_friends('C', 'D', adj_matrix);
    std::cout << "d. User C and user D have " << mutual_friends.size() << " mutual friends: ";
    for (int i = 0; i < mutual_friends.size(); i++) {
        std::cout << mutual_friends[i] << " ";
    }
    std::cout << std::endl;
}

// Get the number of friends of a user
int get_number_of_friends(char user, std::vector<std::vector<int>> adj_matrix) {
    int user_index = int(user) - 65;
    int num_of_friends = 0;

    for (int i = 0; i < adj_matrix[user_index].size(); i++) {
        if (adj_matrix[user_index][i] == 1) {
            num_of_friends++;
        }
    }

    return num_of_friends;
}

// Get the user who has the most friends
std::vector<char> get_most_friends(std::vector<std::vector<int>> adj_matrix) {
    int max_friends = 0;

    // throw if matrix is empty
    if (adj_matrix.size() == 0) {
        std::cout << "Matrix is empty" << std::endl;
        return {};
    }

    // Get the maximum number of friends
    for (int i = 0; i < adj_matrix.size(); i++) {
        int num_of_friends = 0;
        for (int j = 0; j < adj_matrix[i].size(); j++) {
            if (adj_matrix[i][j] == 1) {
                num_of_friends++;
            }
        }
        if (num_of_friends > max_friends) {
            max_friends = num_of_friends;
        }
    }

    // Get the user who has the maximum number of friends
    std::vector<char> most_friends;
    for (int i = 0; i < adj_matrix.size(); i++) {
        int num_of_friends = 0;
        for (int j = 0; j < adj_matrix[i].size(); j++) {
            if (adj_matrix[i][j] == 1) {
                num_of_friends++;
            }
        }
        if (num_of_friends == max_friends) {
            most_friends.push_back(char(i + 65));
        }
    }

    return most_friends;
}

// Get the user who has the least friends
std::vector<char> get_least_friends(std::vector<std::vector<int>> adj_matrix) {
    int min_friends = 1024;

    // throw if matrix is empty
    if (adj_matrix.size() == 0) {
        std::cout << "Matrix is empty" << std::endl;
        return {};
    }

    // Get the minimum number of friends
    for (int i = 0; i < adj_matrix.size(); i++) {
        int num_of_friends = 0;
        for (int j = 0; j < adj_matrix[i].size(); j++) {
            if (adj_matrix[i][j] == 1) {
                num_of_friends++;
            }
        }
        if (num_of_friends < min_friends) {
            min_friends = num_of_friends;
        }
    }

    // Get the user who has the minimum number of friends
    std::vector<char> least_friends;
    for (int i = 0; i < adj_matrix.size(); i++) {
        int num_of_friends = 0;
        for (int j = 0; j < adj_matrix[i].size(); j++) {
            if (adj_matrix[i][j] == 1) {
                num_of_friends++;
            }
        }
        if (num_of_friends == min_friends) {
            least_friends.push_back(char(i + 65));
        }
    }

    return least_friends;
}

std::vector<char> get_mutual_friends(char user1, char user2, std::vector<std::vector<int>> adj_matrix) {
    std::vector<char> mutual_friends;
    int user1_index = int(user1) - 65;
    int user2_index = int(user2) - 65;

    // iterate through the user1's row and push to vector if both user1 and user2 values are 1
    for (int i = 0; i < adj_matrix[user1_index].size(); i++) {
        if (adj_matrix[user1_index][i] == 1 && adj_matrix[user2_index][i] == 1) {
            mutual_friends.push_back(char(i + 65));
        }
    }

    return mutual_friends;
}