#include "gtest/gtest.h"
#include "Gadget.hpp"
#include "Sensor.hpp"

class TestSensorClass : public virtual upm::Gadget
{
};

/* Interfaces test fixture */
class Gadget_unit : public ::testing::Test
{
    protected:
        /* One-time setup logic if needed */
        Gadget_unit()
        {
            /* Load a specific JSON library descriptor file */
            obj.initFromJsonLibDesc("./sensortype_example.json");
        }

        /* One-time tear-down logic if needed */
        virtual ~Gadget_unit() {}

        /* Per-test setup logic if needed */
        virtual void SetUp() {}

        /* Per-test tear-down logic if needed */
        virtual void TearDown() {}

        /* Instance of the test class */
        TestSensorClass obj;
};

TEST_F(Gadget_unit, test_json_basic)
{
    /* Basic checking */
    ASSERT_EQ(obj.DerivedClassName(), "TestSensorClass");
    ASSERT_EQ(obj.Description(), "This is a description");
    ASSERT_EQ(obj.LibraryBaseName(), "core_tests");
    ASSERT_EQ(obj.Name(), "TestSensorClass");
}

TEST_F(Gadget_unit, test_json_deserialize_basic)
{
    /* Basic checking */
    ASSERT_EQ(obj.Name(), "TestSensorClass");
    ASSERT_EQ(obj.Description(), "This is a description");
}

/* Currently no need for a custom main (use gtest's)
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
*/
