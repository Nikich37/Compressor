#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <map>

std::vector<std::string> getCyclicRotations(const std::string &data);

std::string getLastColumn(const std::vector<std::string> &rotations);

std::pair<size_t, std::string> getBWTransofrmedData(const std::string &data);

std::string getBWTRestoredData(const std::string &data, size_t idx);