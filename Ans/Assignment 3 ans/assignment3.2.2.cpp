#include<iostream>
#include <chrono> 

using namespace std;
using namespace std::chrono;

int number_of_times(int a,int b)
{
	return a*b;
}

main()
{
	int i,j;
    cout<<("Enter two integers:\n")<<endl;
	cin>>i>>j;
	auto start = high_resolution_clock::now();
	cout<<("Product is: ")<<number_of_times(i,j)<<endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
	return 0;
}
