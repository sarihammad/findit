#pragma once

#include <string>
#include "SearchResult.hpp"

class Searcher {
public:
	Searcher(const std::string& keyword);
	SearchResult searchInFile(const std::string& filePath);

private:
	std::string keyword;
};