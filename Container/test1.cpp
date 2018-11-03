#include "./src/Container.hpp"

#include <cassert>
#include <cstdio>

class Test {
    public:
    static void assertTrue(bool val) {
        assert(val);
    }
    static void assertFalse(bool val) {
        assert(!val);
    }
};

int main() {
    Container<int> c;
    Test::assertTrue(c.insert(6));
    Test::assertFalse(c.insert(6));
    Test::assertTrue(c.insert(1));
    Test::assertTrue(c.insert(-9));

    Test::assertTrue(c.size() == 3);

    fprintf(stdout, "All tests passed.\n");
    return 0;
}