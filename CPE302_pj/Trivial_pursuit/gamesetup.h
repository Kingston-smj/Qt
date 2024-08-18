#ifndef GAMESETUP_H
#define GAMESETUP_H

#include "filereader.h"
#include "gamefunctions.h"

class GameSetup {
private:
    std::string playerName;
    int maxLives;
    int maxQuestions;
    int lives;
    int score;

    FileReader fileReader;
    GameFunctions gameFunctions;
    std::vector<std::string> questions;
    std::vector<std::string> answers;

public:
    GameSetup(std::string name, int lives, int questions);
    std::pair<std::string, std::string> startRound();
    bool submitAnswer(const std::string &answer);
    int getScore() const;
    int getLives() const;
    bool isGameOver() const;
};

#endif // GAMESETUP_H
