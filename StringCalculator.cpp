#include "StringCalculator.h"
#include <sstream>
#include <algorithm>
#include <regex>

int StringCalculator::add(const std::string& numbers) {
    if (numbers.empty()) {
        return 0;
    }

    std::string numbersCopy = numbers;
    std::string delimiter = extractDelimiter(numbersCopy);
    std::vector<int> parsedNumbers = parseNumbers(numbersCopy, delimiter);
    
    return sumNumbers(parsedNumbers);
}

std::vector<int> StringCalculator::parseNumbers(const std::string& numbers, const std::string& delimiter) {
    std::vector<int> result;
    std::vector<int> negatives;
    std::string delims = delimiter + '\n';
    splitAndParse(numbers, delims, result, negatives);

    if (!negatives.empty()) {
        handleNegatives(negatives);
    }

    return result;
}

void StringCalculator::splitAndParse(const std::string& numbers, const std::string& delims, std::vector<int>& result, std::vector<int>& negatives) {
    size_t start = 0;
    size_t end = numbers.find_first_of(delims);

    while (end != std::string::npos) {
        addNumber(numbers.substr(start, end - start), result, negatives);
        start = end + 1;
        end = numbers.find_first_of(delims, start);
    }

    if (start < numbers.size()) {
        addNumber(numbers.substr(start), result, negatives);
    }
}

void StringCalculator::addNumber(const std::string& numStr, std::vector<int>& result, std::vector<int>& negatives) {
    if (!numStr.empty()) {
        int parsedNum = std::stoi(numStr);
        if (parsedNum < 0) {
            negatives.push_back(parsedNum);
        } else {
            result.push_back(parsedNum);
        }
    }
}

void StringCalculator::handleNegatives(const std::vector<int>& negatives) {
    std::string message = "negatives not allowed: ";
    for (size_t i = 0; i < negatives.size(); ++i) {
        message += std::to_string(negatives[i]);
        if (i != negatives.size() - 1) {
            message += ",";
        }
    }
    throw std::runtime_error(message);
}

std::string StringCalculator::extractDelimiter(std::string& numbers) {
    if (numbers.rfind("//", 0) == 0) {
        size_t delimiterEnd = numbers.find('\n');
        std::string delimiter = numbers.substr(2, delimiterEnd - 2);
        numbers = numbers.substr(delimiterEnd + 1);
        return delimiter;
    }
    return ",";
}

int StringCalculator::sumNumbers(const std::vector<int>& numbers) {
    int sum = 0;
    for (int num : numbers) {
        if (num <= 1000) {
            sum += num;
        }
    }
    return sum;
}
