#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE("node stores  link")
{
    Link link("steel");
    Node node(link);

    REQUIRE(node.get_link().get_material() == "steel");
    REQUIRE(node.get_next() == nullptr);
}

TEST_CASE("node points to another node")
{
    Link link1("steel");
    Link link2("silver");

    Node first(link1);
    Node second(link2);

    first.set_next(&second);

    REQUIRE(first.get_next() == &second);
}

TEST_CASE("chain of nodes")
{
    Link link1("steel");
    Link link2("silver");
    Link link3("gold");

    Node head(link1);
    Node second(link2);
    Node third(link3);

    head.set_next(&second);
    second.set_next(&third);

    Node* current = &head;
    REQUIRE(current->get_link().get_material() == "steel");

    current = current->get_next();
    REQUIRE(current->get_link().get_material() == "silver");

    current = current->get_next();
    REQUIRE(current->get_link().get_material() == "gold");

    current = current->get_next();
    REQUIRE(current == nullptr);
}
