#include "hello.hpp"

Node::Node(Link link) : link(link)
{
    next = nullptr;
}

void Node::set_next(Node* next)
{
    this->next = next;
}

Node* Node::get_next() const
{
    return next;
}

Link Node::get_link() const
{
    return link;
}