
#include "link.hpp"

class Node {

private:

	Link link;

	Node* next;

public:
	Node(Link link);

	void set_next(Node* next);
	Node* get_next() const;
	Link get_link() const;


};

