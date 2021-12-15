#include<iostream>
#include <sys/utsname.h>
using namespace std;

int main()
{
	utsname u;
	if(uname(&u)!=0)
		return 1;
	cout << "Hello Docker from " << u.nodename <<"!!!\n";
	return 0;
}
