#include "Searcher.hpp"
#include <fstream>
#include <iostream>

Searcher::Searcher(const std::string& keyword) 
    : keyword(keyword) {}

SearchResult Searcher::searchInFile(const std::string& filePath) {
    SearchResult result(filePath);
    std::ifstream file(filePath);
 
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filePath << '\n';
        return result;
    }

    std::string line;
    int lineNumber = 1;
    while (std::getline(file, line)) {
        if (line.find(keyword) != std::string::npos) {
            result.addMatch(lineNumber);
        }
        ++lineNumber;
    }
    
    return result;
}