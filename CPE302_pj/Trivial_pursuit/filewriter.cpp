#include "filewriter.h"
#include <fstream>
#include <iostream>

// Function to write game results to a file
void FileWriter::writeResults(const std::string& filename, const std::string& results) {
    std::ofstream file(filename, std::ios::app);

    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    file << results << std::endl;
    file.close();
}
