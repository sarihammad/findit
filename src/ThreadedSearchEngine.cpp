#include "ThreadedSearchEngine.hpp"
#include <iostream>
// #include 

void ThreadedSearchEngine::search(const std::string& directory, const std::string& keyword) {
    FileManager fm;
    auto allFiles = fm.getAllFiles(directory);

    const unsigned int numThreads = std::min(4u, std::thread::hardware_concurrency());
    const size_t chunkSize = allFiles.size() / numThreads + 1;

    std::vector<std::thread> threads;

    for (unsigned int i = 0; i < numThreads; ++i) {
        auto start = allFiles.begin() + i * chunkSize;
        auto end = (i + 1) * chunkSize < allFiles.size() ? start + chunkSize : allFiles.end();
        std::vector<std::string> chunk(start, end);

        threads.emplace_back(&ThreadedSearchEngine::workerThread, this, chunk, keyword);
    }

    for (auto& thread : threads) {
        thread.join();
    }

    for (const auto& res: results) {
        if (res.hasMatches()) {
            std::cout << "File: " << res.fileName << '\n';
            for (int line : res.matchingLines) {
                std::cout << " Line: " << line << '\n';
            }
        }
    }
}

void ThreadedSearchEngine::workerThread(std::vector<std::string> filesChunk, const std::string& keyword) {
    Searcher searcher(keyword);

    for (const auto& file : filesChunk) {
        SearchResult res = searcher.searchInFile(file);
        if (res.hasMatches()) {
            std::lock_guard<std::mutex> lock(resultMutex);
            results.push_back(res);
        }
    }
}