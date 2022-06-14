#include "./std_lib_facilities.h"

// #include <iostream>

class Bad_area{};

int area(int length, int width)
{
//     if(length <=0 || width <=0) 
//     {
//         throw Bad_area{};
//     };
    return length * width;
}

int framed_area( int x, int y)
{
    constexpr int frame_width = 2;
    return area(x-frame_width, y-frame_width);
}

int f(int x, int y, int z)
{
    int area1 = area(x,y);
    std::cout << "area1: " << area1 << std::endl;
    if(area1 <= 0) error( "non positive area");
    int area2 = framed_area(1,z);
    std::cout << "area2: " << area2 << std::endl;
    int area3 = framed_area(y,z);
    std::cout << "area3: " << area3 << std::endl;
    double ratio = double(area1)/area2;
    std::cout << "ratio: " << ratio << std::endl;

    return 1;
}


void try_this1()
{
    // int s1 = area(7;
    // int s2 = area(7)
    // Int s3 = area(7);
    // int s4 = area('7);
    // int s5 = area(7, 7);
    // int s6 = area(10.7, 9.4);
}


int main()
{
    error("error");
    // f(4, 4, 4);
    // try
    // {
    //     int x = -1;
    //     int y = 2;
    //     int z = 4;

    //     int area1 = area(x,y);
    // }
    // catch(Bad_area)
    // {
    //     std::cout << "Oops. Bad argument for area()" << std::endl;
    // };
    return 0;
}