#include <forward_list> 
#include <vector> 
#include <queue> 
#include <iostream>

template <typename T> 
struct Node {
	
	bool marked{false};
	T data; 
	std::forward_list<Node<T>> adj; 

	Node(T label) {
		this->data = data; 
	}

	void addAdj(Node<T> node) {
		adj.push_front(node);
	}
	
};


template <typename T> 
struct Graph { 	 

	void addNode(Node<T>& node) {
		nodes.push_back(node); 
	}

	std::vector<Node<T>> nodes;  

};

template<typename T>
bool visit(Node<T> node) {

}

template<typename T> 
void BFS(Graph<T>& graph) {
	//insert nodes into queue
	std::queue<Node<T>> queue; 
	Node<T> currentNode; 

	for (auto it = graph.nodes.begin(); it != graph.nodes.end(); it++) {
		queue.push(*it); 
	}

	while (!queue.empty()) { 
		/*if node has not been visited already, change marked status of node and 		visit it*/
		Node<T> currNode{queue.pop()}; 
		if (currNode.marked == false) { 
			currNode.marked = true;
			visit(currNode);
		}

		//now iterate through the adjacency list of the node
		for (auto it = currNode.adj.begin(); it != currNode.adj.end(); it++) { 
			*it.marked = true; 
			visit(*it); 
			queue.push(*it); 
		}
	}

}

//Route between nodes
template<typename T> 
bool route(Node<T> node1, Node<T> node2) {
	//insert nodes into queue
	std::queue<Node<T>> queue; 
	Node<T> currentNode; 
	queue.push(node1); 

	while (!queue.empty()) { 
		/*if node has not been visited already, change marked status of node and 		visit it*/
		Node<T> currNode{queue.pop()}; 
		if (currNode.marked == false) { 
			currNode.marked = true;
			visit(currNode);
		}

		//now iterate through the adjacency list of the node
		for (auto it = currNode.adj.begin(); it != currNode.adj.end(); it++) { 
			*it.marked = true; 
			if (*it == node2) 
				return true; 
			queue.push(*it); 
		}
	}
	return false; 
}



int main() { 
	
	bool string{false};
	int value; 
	Graph<int> graph; 

	while (1) {
		
		std::cout << "Add a node" << std::endl; 
		
		std::cin >> value; 
		
		Node<int> node{Node<int>(value)}; 
		graph.addNode(node); 

		while (1) {
			
			std::cout << "Would you like to an adjacency node?" << std::endl; 
			std::cin >> flag; 
			if (flag == "no") 
				break; 
			std::cout << "Add adjacency node" << std::endl;

			std::cin >> value; 
		
			Node<int> adjNode{Node<int>(value)}; 
			graph.addNode(adjNode);
			node.addAdj(adjNode); 

		}

		std::cout << "Would you like to add another node?" << std::endl; 
		std::cin >> flag; 
		if (flag == "no") 
			break; 
	}
	
}
