#pragma once

#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include "Searcher.hpp"
#include "SearchResult.hpp"
#include "FileManager.hpp"

class ThreadedSearchEngine {
public:
	void search(const std::string& directory, const std::string& keyword);

private:
	void workerThread(std::vector<std::string> filesChunk, const std::string& keyword);
	std::mutex resultMutex;
	std::vector<SearchResult> results;
};