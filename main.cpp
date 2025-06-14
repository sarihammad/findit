#include "ThreadedSearchEngine.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		std::cerr << "Usage: " << argv[0] << " <directory> <keyword>" << '\n';
		return 1;
	}

	std::string directory = argv[1];
	std::string keyword = argv[2];

	ThreadedSearchEngine engine;
	engine.search(directory, keyword);

	return 0;
}