#ifndef STRING_CALCULATOR_H
#define STRING_CALCULATOR_H

#include <string>
#include <vector>
#include <stdexcept>

class StringCalculator {
public:
    int add(const std::string& numbers);

private:
    std::vector<int> parseNumbers(const std::string& numbers, const std::string& delimiter);
    void splitAndParse(const std::string& numbers, const std::string& delims, std::vector<int>& result, std::vector<int>& negatives);
    void addNumber(const std::string& numStr, std::vector<int>& result, std::vector<int>& negatives);
    void handleNegatives(const std::vector<int>& negatives);
    std::string extractDelimiter(std::string& numbers);
    int sumNumbers(const std::vector<int>& numbers);
};

#endif
