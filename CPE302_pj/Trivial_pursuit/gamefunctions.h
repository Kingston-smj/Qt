#ifndef GAMEFUNCTIONS_H
#define GAMEFUNCTIONS_H

#include <vector>
#include <string>

class GameFunctions {
public:
    int rollDice();

    // Function to validate a player's answer
    bool validateAnswer(const std::string& answer, const std::string& correctAnswer);

    // Function to calculate the score of a player
    int calculateScore(const std::vector<std::string>& playerAnswers, const std::vector<std::string>& correctAnswers);

    // Function to display the current score
    void displayScore(int score);

    // Function to pick a random question and its corresponding answer
    std::pair<std::string, std::string> pickQuestionAndAnswer(const std::vector<std::string>& questions, const std::vector<std::string>& answers);
};

#endif // GAMEFUNCTIONS_H
