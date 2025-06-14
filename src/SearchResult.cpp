#include "SearchResult.hpp"

SearchResult::SearchResult(const std::string& name) 
    : fileName(name) {}


void SearchResult::addMatch(int lineNumber) {
    matchingLines.push_back(lineNumber);
}

bool SearchResult::hasMatches() const {
    return !matchingLines.empty();
}