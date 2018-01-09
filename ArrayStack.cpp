class ArrayStack{

	public: 

	ArrayStack(int stackSize){
		this->stackSize = stackSize; 
		values[stacks*stackSize]; 
		sizes[stacks];
		
		for (int i = 0; i < stacks; i++){
			sizes[i] = 0; 
		}
	}

	void push(int stackNum, int value){
		if (isEmpty(stackNum)) 
			throw "Stack is full"; 
		values[indexOfTop(stackNum)] = value; 
		sizes[stackNum]++; 
	}

	int pop(int stackNum){ 
		if (isEmpty(stackNum)) 
			throw "Stack is empty";
		int temp = values[indexOfTop(stackNum)]; 
		values[indexOfTop(stackNum)] = 0; 
		sizes[stackNum]--; 
		return temp; 	
	}

	int peek(int stackNum){
		if (isEmpty(stackNum))
			throw "Stack is empty."; 
		return values[indexOfTop(stackNum)];
	}

	

	private:

	int stacks = 3; 
	int stackSize = 0; 
	int values[];
	int sizes[];

	bool isEmpty(int stackNum){
		if (sizes[stackNum] == 0) 
			return true; 
		else return false; 	
	}

	bool isFull(int stackNum){
		if (sizes[stackNum] == stackSize) 
			return true; 
		else return false; 
	}

	int indexOfTop(int stackNum){
		int offset = stackSize*stackNum; 
		int topIndex = offset + sizes[stackNum] - 1; 
		return topIndex; 
	}
};
