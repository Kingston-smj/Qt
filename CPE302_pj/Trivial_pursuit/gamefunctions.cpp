#include "gamefunctions.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <ctime>

// Function to roll a dice (returns a number between 1 and 6)
int GameFunctions::rollDice() {
    std::srand(std::time(nullptr));  // Seed for random number generation
    return std::rand() % 6 + 1;  // Returns a number between 1 and 6
}

// Function to validate a player's answer
bool GameFunctions::validateAnswer(const std::string& answer, const std::string& correctAnswer) {
    std::string answerLower = answer;
    std::string correctAnswerLower = correctAnswer;

    std::transform(answerLower.begin(), answerLower.end(), answerLower.begin(), ::tolower);
    std::transform(correctAnswerLower.begin(), correctAnswerLower.end(), correctAnswerLower.begin(), ::tolower);

    return answerLower == correctAnswerLower;
}

// Function to calculate the score of a player
int GameFunctions::calculateScore(const std::vector<std::string>& playerAnswers, const std::vector<std::string>& correctAnswers) {
    int score = 0;

    for (size_t i = 0; i < playerAnswers.size(); ++i) {
        if (validateAnswer(playerAnswers[i], correctAnswers[i])) {
            score++;
        }
    }

    return score;
}

// Function to display the current score
void GameFunctions::displayScore(int score) {
    std::cout << "Your current score is: " << score << std::endl;
}

// Function to pick a random question and its corresponding answer
std::pair<std::string, std::string> GameFunctions::pickQuestionAndAnswer(const std::vector<std::string>& questions, const std::vector<std::string>& answers) {
    if (questions.empty() || questions.size() != answers.size()) {
        return {"", ""};  // Return empty strings if input is invalid
    }

    std::srand(std::time(nullptr));  // Seed for random number generation
    int randomIndex = std::rand() % questions.size();  // Pick a random index

    return {questions[randomIndex], answers[randomIndex]};
}
