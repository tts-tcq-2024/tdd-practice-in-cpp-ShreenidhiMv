#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    std::string input = "";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    std::string input = "0";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    std::string input = "1,2";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    std::string input = "1\n2,3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectExceptionForNegativeNumbers) {
    StringCalculator objUnderTest;
    try {
        std::string input = "-1,2";
        objUnderTest.add(input);
        FAIL() << "Expected std::runtime_error";
    } catch (const std::runtime_error& e) {
        EXPECT_STREQ("negatives not allowed: -1", e.what());
    } catch (...) {
        FAIL() << "Expected std::runtime_error";
    }
}

TEST(StringCalculatorAddTests, ExpectExceptionForMultipleNegativeNumbers) {
    StringCalculator objUnderTest;
    try {
        std::string input = "-1,-2,3";
        objUnderTest.add(input);
        FAIL() << "Expected std::runtime_error";
    } catch (const std::runtime_error& e) {
        EXPECT_STREQ("negatives not allowed: -1,-2", e.what());
    } catch (...) {
        FAIL() << "Expected std::runtime_error";
    }
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 2;
    std::string input = "2,1001";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    std::string input = "//;\n1;2";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, ExpectSumWithCustomDelimiterOfAnyLength) {
    int expectedresult = 6;
    std::string input = "//[***]\n1***2***3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, EmptyNumberBetweenDelimiters) {
    int expectedresult = 1;
    std::string input = "1,\n";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, MultipleDelimitersIncludingNewline) {
    int expectedresult = 10;
    std::string input = "1\n2,3\n4";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, MultipleDelimitersWithCustomDelimiter) {
    int expectedresult = 6;
    std::string input = "//[;]\n1;2;3";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorAddTests, CustomDelimiterWithNoNumbers) {
    int expectedresult = 0;
    std::string input = "//;\n";
    StringCalculator objUnderTest;
    int result = objUnderTest.add(input);

    ASSERT_EQ(result, expectedresult);
}
