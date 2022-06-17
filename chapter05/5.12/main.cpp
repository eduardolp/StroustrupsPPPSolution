// #include "std_lib_facilities.h"
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

void PrintVec(const std::vector<int> &vec)
{
    std::for_each(vec.begin(), vec.end(), [](int x){std::cout << x << " ";});
    std::cout<<std::endl;
}

std::map<std::string, int> CompareVecs(const std::vector<int> &reference, const std::vector<int> &entered)
{
    std::map<std::string, int> output;
    
    int bullCount=0;
    int cowCount=0;

    for(int i=0; i<entered.size(); i++)
    {
        for(int j=0; j<reference.size(); j++)
        {           
            if(entered[i] == reference[j])
            {
                if(j==i) 
                    bullCount++;
                else
                    cowCount++;
            }
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

bool NeedToLoop(const std::map<std::string, int> &seen, 
                const std::vector<int> & reference)
{
    if(seen.at("Bull")==reference.size())
    {
        std::cout << "All numbers correctly found." << std::endl;
        return false;
    }   
    else
        return true;
}

std::vector<int> HandleInput()
{
    std::vector<int> output;
    std::cout << "Enter 4 different digits: ";

    for(int input; output.size()<4;)
    {   
        std::cin >> input;
        if (!std::cin) 
        {
            throw std::runtime_error("Couldn't read integer from input\n");
        }
        output.push_back(input);
    }

    std::cin.ignore();

    return output;
}


int main()
{
    std::vector<int> referenceVec = {1,2,3,4};

    bool keepLooping = true;

    while(keepLooping)
    {
        try
        {        
            std::vector<int> enteredVec = HandleInput();
            std::map<std::string, int> seen = CompareVecs(referenceVec, enteredVec);
            keepLooping = NeedToLoop(seen, referenceVec);
        }
        catch(std::runtime_error &e)
        {
            std::cerr << e.what();
            std::cin.clear();
            std::cin.ignore();
        }
    };

    return 0;
}