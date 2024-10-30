#include <iostream>
#include <cstdlib>

int main() {
    int number = std::rand() % 100 + 1;
    int guess;

    std::cout << "Guess a number between 1 and 100: ";
    while (std::cin >> guess) {
        if (guess < number) {
            std::cout << "Too low! Try again: ";
        } else if (guess > number) {
            std::cout << "Too high! Try again: ";
        } else {
            std::cout << "You got it!" << std::endl;
            break;
        }
    }
    return 0;
}