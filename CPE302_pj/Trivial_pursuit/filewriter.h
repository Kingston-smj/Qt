#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>

class FileWriter {
public:
    // Function to write game results to a file
    void writeResults(const std::string& filename, const std::string& results);
};

#endif // FILEWRITER_H
