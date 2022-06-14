#include "std_lib_facilities.h"

int main()
{
    int n;
    cout << "Please enter the number of values you want to sum:\n";
    cin >> n;

    vector<int> vec;
    cout << "Please enter some integers separated by spaces (enter '|' to stop):\n";
    for(int input; cin>>input;)
        vec.push_back(n);

    if(n > vec.size()) error("Not enough values in the vector.");

    for(int i=0; i<vec.size();i++)
    {
        cout << vec[i] << " ";
    }
    cout<<endl;

    int sum=0; 
    for (int i=0; i<n; i++)
    {
        sum+=vec[i];
    }

    cout << "The sum of the first " << n << " numbers ( ";
    for (int i=0; i<n; i++)
        cout << vec[i] << " ";
    cout << ") is " << sum << "." << endl;

    return 0;
};