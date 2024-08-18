#ifndef FILEREADER_H
#define FILEREADER_H

#include <vector>
#include <string>

class FileReader {
public:
    // Function to read questions from a file
    std::vector<std::string> readQuestions(const std::string& geography);

    // Function to read answers from a file
    std::vector<std::string> readAnswers(const std::string& geography);
};

#endif // FILEREADER_H
