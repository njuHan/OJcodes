
#include <vector>  //standard vector class template: vector<>
#include <stdexcept>  //stadard exception class

//Declaration of Class Template
template<typename T>
class Stack
{
private:
	std::vector<T> elems; //elements
public:
	void push(T const&); //push element
	void pop();    //pop element
	T top() const;   //return top element
	bool empty() const
	{
		return elems.empty();
	}
};

//Implementation of Member Functions
template <typename T>
void Stack<T>::push(T const &elem)
{
	elems.push_back(elem); //append copy of passed elem
}

template <typename T>
void Stack<T>::pop()
{
	if (elems.empty()) {
		throw std::out_of_range("Stack<>::pop():empty stack");
	}
	elems.pop_back();  //remove last element
}

template <typename T>
T Stack<T>::top() const
{
	if (elems.empty())
	{
		throw std::out_of_range("Stack<>::top() : empty stack");
	}
	return elems.back(); //return copy of last element
}

int main()
{
	
	system("pause");
	return 0;
}