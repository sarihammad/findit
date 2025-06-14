#include "FileManager.hpp"
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::vector<std::string> FileManager::getAllFiles(const std::string& directoryPath) {
	std::vector<std::string> files;
	
	try {
		for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {
			if (entry.is_regular_file()) {
				files.push_back(entry.path().string());
			}
		}
	} catch (const fs::filesystem_error& e) {
		std::cerr << "Filesystem error: " << e.what() << '\n'; 
	}

	return files;
}
