#include "gamesetup.h"

GameSetup::GameSetup(std::string name, int lives, int questions)
    : playerName(name), maxLives(lives), maxQuestions(questions), lives(lives), score(0)
{
    this->questions = fileReader.readQuestions("questions.csv");
    this->answers = fileReader.readAnswers("answers.csv");
}

std::pair<std::string, std::string> GameSetup::startRound() {
    return gameFunctions.pickQuestionAndAnswer(questions, answers);
}

bool GameSetup::submitAnswer(const std::string &answer) {
    bool correct = gameFunctions.validateAnswer(answer, answers.back());
    if (correct) {
        score++;
    } else {
        lives--;
    }
    return correct;
}

int GameSetup::getScore() const {
    return score;
}

int GameSetup::getLives() const {
    return lives;
}

bool GameSetup::isGameOver() const {
    return lives == 0 || score == maxQuestions;
}
