
#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
using namespace family;



TEST_CASE("empty"){
    family::Tree* t = new Tree();
    for (int i = 0; i <= 100; i++) {
    CHECK(t->root);
    CHECK(!t->root->Father);
    CHECK(!t->root->Mother);
   
    }
}
