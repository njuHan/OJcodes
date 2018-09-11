#include <string>
#include <iostream>
using namespace std;


/*
runtime_error是C++标准异常类，其类定义为:

class runtime_error : public exception {
public:
explicit runtime_error (const string& what_arg);
};
*/
int divide(int a, int b)
{

	try
	{
		if (b == 0)
		{
			throw runtime_error("Division by zero");
		}
	}
	catch (runtime_error err) {
		cerr << "catch exception" << err.what() << endl;
	}
	return a / b;
}

int main()
{
	cout << divide(2, 0);
	system("pause");
	return 0;
}
