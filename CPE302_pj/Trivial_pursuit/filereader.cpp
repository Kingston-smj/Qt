#include "filereader.h"
#include <fstream>
#include <sstream>
#include <iostream>

// Function to read questions from a CSV file
std::vector<std::string> FileReader::readQuestions(const std::string& filename) {
    std::vector<std::string> questions;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return questions;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string question;
        if (std::getline(ss, question, ',')) {
            questions.push_back(question);
        }
    }

    file.close();
    return questions;
}

// Function to read answers from a CSV file
std::vector<std::string> FileReader::readAnswers(const std::string& filename) {
    std::vector<std::string> answers;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return answers;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string answer;
        if (std::getline(ss, answer, ',')) {
            answers.push_back(answer);
        }
    }

    file.close();
    return answers;
}
