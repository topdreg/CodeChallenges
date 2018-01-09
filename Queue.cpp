#include<list> 
#include<string>
#include<iostream>

template<typename T> 
class Queue {

public:

	void add(T data) {
		queue.push_back(data); 
	} 

	T peek(){
		if (queue.empty())
			throw "Queue is empty."; 
		return queue.front();
	}

	T remove(){
		T value = queue.peek(); 
		queue.pop_front; 
		return value; 
	}

	bool isEmpty() {
		return queue.empty(); 
	}

private: 
	
	std::list<T>queue; 

};

class Animal {

public: 

	Animal(std::string name) {
		this->name = name; 
	}

	void setOrder(int order){
		this->order = order; 
	}

	int getOrder(){
		return order; 
	}

	std::string getName() {
		return name; 
	}

private: 

	std::string name;
	int order; 
};

class Cat: public Animal {
	
	using Animal::Animal;

};

class Dog: public Animal {

	using Animal::Animal;

};

class AnimalQueue { 

int orderCounter{0}; 

public:

	void enqueue(Dog&& dog) {
		dog.setOrder(orderCounter); 
		dogs.push_back(dog);
		orderCounter++;
	}

	void enqueue(Cat&& cat) {
		cat.setOrder(orderCounter); 
		cats.push_back(cat);
		orderCounter++; 
	}

	Dog dequeueDog() {
		if (dogs.empty())
			throw "There are no dogs."; 
		Dog dog = dogs.front(); 
		dogs.pop_front(); 
		return dog; 
	}

	Cat dequeueCat() {
		if (cats.empty())
			throw "There are no cats."; 
		Cat cat = cats.front(); 
		cats.pop_front();
		return cat; 
	}

	Animal dequeueAny() {
		if (dogs.front().getOrder() < cats.front().getOrder()) {
			Dog dog = dequeueDog();
			return dog; 
		}
		else {
			Cat cat = dequeueCat(); 
			return cat;
		}
	}

	bool isEmpty(){
		if (dogs.empty() && cats.empty())
			return true;
		else return false; 
	}

	bool dogEmpty(){
		return dogs.empty();
	}


private:

	std::list<Dog> dogs; 
	std::list<Cat> cats; 

};

int main() {
	
	AnimalQueue queue{AnimalQueue()}; 

	queue.enqueue(Dog("Flynn"));
	queue.enqueue(Cat("Heide")); 
	queue.enqueue(Cat("Hi")); 
	queue.enqueue(Dog("Wee")); 

	while (!queue.dogEmpty()){
		std::cout << queue.dequeueDog().getName() << " " <<  std::endl; 
	}
}
