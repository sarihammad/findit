#pragma once

#include <vector>
#include <string>

class FileManager {
public:
	std::vector<std::string> getAllFiles(const std::string& directoryPath);
};