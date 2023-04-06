#include <cppunit/TestCase.h>
#include <cppunit/extensions/HelperMacros.h>

class MyTest : public CppUnit::TestCase
{
public:
    void testAddition()
    {
        int a = 2;
        int b = 3;
        int expected = 5;
        int result = a + b;
        CPPUNIT_ASSERT_EQUAL(expected, result);
    }

    CPPUNIT_TEST_SUITE(MyTest);
    CPPUNIT_TEST(testAddition);
    CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION(MyTest);
