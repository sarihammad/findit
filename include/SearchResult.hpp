#pragma once

#include <string>
#include <vector>

class SearchResult {
public:
	std::string fileName;
	std::vector<int> matchingLines;

	SearchResult(const std::string& name);
	void addMatch(int lineNumber);
	bool hasMatches() const;
};