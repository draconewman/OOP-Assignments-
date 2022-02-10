#include<iostream>
#define max(x,y) ((a>b)?a:b)
using namespace std;

main()
{
    char a='A',b='B';
	char *i,*j;
	i=&a;
	j=&b;
    std::cout<<("Max number is ");
	std::cout<<max(i,j);
	return 0;
}
