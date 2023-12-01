#include "../headers/bwtUtil.h"
// Steps:

// 1. Get cyclic rotations
// 2. Sort cyclic rotations
// 3. Get last column

std::vector<std::string> getCyclicRotations(const std::string &data) {
    if (data.size() == 0) {
        return {};
    }
    std::vector<std::string> rotations(data.size());
    rotations[0] = data;
    for (size_t i = 0; i != data.size() - 1; ++i) {
        rotations[i + 1] = data.substr(data.size() - i - 1) +
            data.substr(0, data.size() - i - 1);
    }
    return rotations;
}

std::string getLastColumn(const std::vector<std::string> &rotations) {
    std::string lastColumn;
    for (const auto &rotation : rotations) {
        lastColumn += rotation.back();
    }
    return lastColumn;
}

std::pair<size_t, std::string> getBWTransofrmedData(const std::string &data) {
    std::vector<std::string> rotations = getCyclicRotations(data);
    std::sort(rotations.begin(), rotations.end());
    size_t idx = 0;
    for (const auto &rotation : rotations) {
        if (rotation == data) {
            break;
        }
        idx++;
    }
    std::string lastColumn = getLastColumn(rotations);
    return {idx, lastColumn};
}

// Linear complexity algorithm
std::string getBWTRestoredData(const std::string &data, size_t idx) {
    if (data.empty() || data.size() == 1) {
        return data;
    }
    size_t size = data.size();
    std::map<char, size_t> frequency;
    std::map<char, size_t> numSmallerTable;
    std::vector<size_t> frequencyTable(size);
    for (size_t i = 0; i != size; ++i) {
        frequencyTable[i] = frequency[data[i]];
        frequency[data[i]]++;
    }
    size_t prevNum = -1;
    char prevSymb;
    for (const auto [symb, _] : frequency) {
        if (prevNum == -1) {
            numSmallerTable[symb] = 0;
            prevSymb = symb;
            prevNum = 0;
        } else {
            numSmallerTable[symb] = prevNum + frequency[prevSymb];
            prevNum = numSmallerTable[symb];
            prevSymb = symb;
        }
    }
    std::string restoredData(data.size(), ' ');
    
    restoredData[size - 1] = data[idx];
    prevSymb = data[idx];
    size_t prevIdx = idx;
    size_t nextIdx = frequencyTable[prevIdx] + numSmallerTable[prevSymb];
    for (size_t i = size - 2; i != 0; --i) {
        restoredData[i] = data[nextIdx];
        prevSymb = data[nextIdx];
        prevIdx = nextIdx;
        nextIdx = frequencyTable[prevIdx] + numSmallerTable[prevSymb];
    }
    restoredData[0] = data[nextIdx];
    return restoredData;
}



