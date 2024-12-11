#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

std::vector<std::string> crackCorrectCodes(
    const std::vector<std::string> &codes, int code_length);
bool isCorrectCode(const std::string &code,
                   const std::vector<std::string> &obfuscated_codes);

int main()
{
    // The first line will contain the length of correct codes, and the number
    // of observations made on thieves entering
    int code_length, num_observations;
    std::cin >> code_length >> num_observations;

    std::vector<std::string> obfuscated_codes;
    // Read in all observations
    for (int i{0}; i < num_observations; i++)
    {
        std::string obfuscated_code;
        std::cin >> obfuscated_code;
        obfuscated_codes.push_back(obfuscated_code);
    }

    // Find all correct codes
    std::vector<std::string> correct_codes{
        crackCorrectCodes(obfuscated_codes, code_length)};

    // Count the number of correct codes
    unsigned long num_correct{correct_codes.size()};

    std::cout << num_correct << std::endl;

    // Print all correct codes
    for (const std::string &code : correct_codes)
    {
        std::cout << code << std::endl;
    }
}

/*

Generate all possible codes of the given length, and check if they are correct.
Return all correct codes.

*/
std::vector<std::string> crackCorrectCodes(
    const std::vector<std::string> &codes, int code_length)
{
    std::vector<std::string> correct_codes;
    int num_possible_codes{static_cast<int>(pow(10, code_length))};
    // For each possible code
    for (int i{0}; i < num_possible_codes; i++)
    {
        // Convert the number to a string
        std::string code{std::to_string(i)};

        // If the code is not the correct length, pad it with zeros
        if (code.size() < code_length)
        {
            code = std::string(code_length - code.size(), '0') + code;
        }

        // Check if the code is correct for all observations
        if (isCorrectCode(code, codes))
        {
            correct_codes.push_back(code);
        }
    }
    return correct_codes;
}

/*

A code is correct if, for each digit in the code, they appear in the same order
in the obfuscated code. For example, the code "123" is correct for the
obfuscated code "1234", or "7212389456" but not for "1324" or "1245".

*/
bool isCorrectCode(const std::string &code, const std::vector<std::string> &obfuscated_codes)
{
    bool all_correct{true};
    // For each obfuscated code
    for (const std::string &obfuscated_code : obfuscated_codes)
    {
        // The index we will read at
        int code_index{0};
        // For each digit in the obfuscated code
        for (char digit : obfuscated_code)
        {
            // Check if it matches our tested code
            if (digit == code[code_index])
            {
                // If it does, carry on checking our code
                code_index++;
            }
        }
        // If we have checked all the digits in the code, then it is correct
        all_correct = code_index == code.size();

        if (!all_correct)
        {
            break;
        }
    }
    return all_correct;
}