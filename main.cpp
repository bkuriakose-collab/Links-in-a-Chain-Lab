#include <iostream>

#include "src/hello.hpp"

using namespace std;

int main() {
    Link link1("steel");
    Link link2("silver");
    Link link3("gold");

    Node head(link1);
    Node second(link2);
    Node third(link3);

    head.set_next(&second);
    second.set_next(&third);

    Node* current = &head;

    while (current != nullptr) {
        cout << current->get_link().get_material() << endl;
        current = current->get_next();
    }

    return 0;
}
