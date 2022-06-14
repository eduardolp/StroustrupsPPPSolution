// #include "std_lib_facilities.h"
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>

void PrintVec(const std::vector<int> &vec)
{
    for(auto v:vec)
    {
        std::cout << v << " ";
    }
    std::cout<<std::endl;
}

std::map<std::string, int> CompareVecs(const std::vector<int> &reference, const std::vector<int> &entered)
{
    std::map<std::string, int> output;
    
    int bullCount=0;
    int cowCount=0;
    for(int i=0; i<entered.size(); i++)
    {
        if(entered[i] == reference[i]) bullCount++;
        for(int j=0; j<reference.size(); j++)
        {
            if(j==i) continue;
            if(entered[i] == reference[j]) cowCount++;
        }
    }

    std::cout << "\nReference: ";
    PrintVec(reference);
    std::cout << "\nEntered: ";
    PrintVec(entered);

    std::cout << "Bulls seen: " << bullCount << std::endl;
    std::cout << "Cows seen: " << cowCount << std::endl;

    output["Bull"] = bullCount;
    output["Cow"] = cowCount;

    return output;
}

bool NeedToLoop(const std::map<std::string, int> &seen, const std::vector<int> & reference)
{
    if(seen.at("Bull")==reference.size())
        return false;
    else
        return true;
}

std::vector<int> HandleInput()
{
    std::vector<int> output;
    std::cout << "Enter 4 different digits";
    std::cin.ignore();

    for(char input; std::cin >> input;)
    {   
        std::cout << input << std::endl;
        if(input == '|' || input < '0' || input > '9') break;
        else output.push_back(input-'0');
    }

    return output;
}


int main()
{
    std::vector<int> referenceVec = {1,2,3,4};

    std::vector<int> enteredVec;
    bool keepLooping = true;

    while(keepLooping)
    {
        std::vector<int> enteredVec = HandleInput();

        std::map<std::string, int> seen = CompareVecs(referenceVec, enteredVec);

        keepLooping = NeedToLoop(seen, referenceVec);
    };
    return 0;
}