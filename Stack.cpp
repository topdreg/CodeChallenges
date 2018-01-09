#include <memory>
#include <iostream>
#include <vector>

template<typename T> 
class Stack {

public: 

	void push(T data) {
		std::shared_ptr<StackNode> node{new StackNode(data)};
		if (top == nullptr) 
			top = node; 
		else {
			node->next = top; 
			top = node; 
		}
			 	
	}

	T pop(){
		if (isEmpty()) 
			throw "Stack is empty."; 
		T item = top->data; 
		top = top->next; 
		return item; 
	}

	T peek(){ 
		if (isEmpty()) 
			throw "Stack is empty."; 
		return top->data; 
	}

	bool isEmpty() {
		if (top == nullptr) 
			return true; 
		else return false; 
	}

protected:
	
	struct StackNode { 
		T data;  
		std::shared_ptr<StackNode> next{nullptr}; 
		
		explicit StackNode(T data){
			this->data = data; 
		}
	};

	std::shared_ptr<StackNode> top{nullptr};


};

template <typename T> 
class minStack : public Stack<T> {

public: 
	void push(T data){
		std::shared_ptr<StackNode> node{new StackNode(data)}; 
		if (top == nullptr) 
			top = node;
		else { 
			node->next = top;
			top = node; 
		}
		if (top->next == nullptr) 
			top->min = node->data; 
		else if (top->data < top->next->min) 
			top->min = node->data;
		else top->min = top->next->min; 
	}

	T min(){
		if (top == nullptr)
			throw "Stack is empty."; 
		return top->min; 
	}

private: 

	struct StackNode { 
		T data;
		T min; 
		std::shared_ptr<StackNode> next{nullptr}; 

		explicit StackNode(T data){ 
			this->data = data; 
		}
	};

	std::shared_ptr<StackNode> top{nullptr}; 

};

template<typename T> 
class minStack2 : public Stack<T> {

public: 

	Stack<T> s2;  

	void push(T data){ 
		Stack<T>::push(data); 
		if (s2.isEmpty() || data < s2.peek()) 
			s2.push(data);
	}

	T pop(){ 
		if (Stack<T>::peek() == s2.peek())
			s2.pop(); 
		return Stack<T>::pop(); 
	}

	T min(){
		
		return s2.peek(); 

	}
	

};

template<typename T>
class MultiStack : public Stack<T> {
	int maxCapacity{5}; 
	std::vector<Stack<T>> stacks;
	std::vector<int> sizes; 
	Stack<T> nextAvailable; 
	int index = 0; 

	MultiStack(){
		Stack<T> stack{new Stack<T>};
		stacks.push_back(stack);
		nextAvailable.push(index); 
	}
	
	void push(T data){  
		if (sizes[index] > maxCapacity) 
			if (nextAvailable.isEmpty()){
				stacks.push_back(new Stack<T>);
				sizes.push_back(0);  
				index = stacks.size() - 1;
				nextAvailable.push(index);  	
			}
			else {
				index = nextAvailable.pop(); 
			}
		stacks[index].push(data); 
		sizes[index]++; 	 
	} 

	T pop(){
		if (stacks.size() == 0)
			throw "There are no elements in the stack."; 
		T value = stacks[index].pop(); 
		sizes[index]--; 
		if (sizes[index] == 0) {
			stacks.erase[index];
			if (nextAvailable.isEmpty())
				return value;  
			else index = nextAvailable.pop();  
		}
		return value; 
	}

	T peek(){ 
		return stacks[index].peek(); 
	} 
	
	
};



int main() {
	
	int number{0};
	int value{0}; 
	minStack2<int> stack; 

	std::cout << "How many values do you want to enter?" << std::endl;

	std::cin >> number; 

	std::cout << std::endl; 

	std::cout << "Enter values: " << std::endl; 

	for (int i = 0; i < number; i++) {
		std::cin >> value;
		stack.push(value);
		std::cout << std::endl; 
	}

	std::cout << "The min value is: " << stack.min() << std::endl; 

}

