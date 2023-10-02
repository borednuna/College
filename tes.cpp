#include <iostream>
#include <string>

void print(std::string str) {
    std::cout << str << std::endl;
    return;
}

int main() {
    std::string str = "Hello World!";
    bool me = false;
    print("Here " + me ? str : "no");
    return 0;
}