#include "gtest/gtest.h"
#include "Gadget.hpp"
#include "Sensor.hpp"
#include "Temperature.hpp"
#include "external/json/json.hpp"
#include <vector>

using namespace upm;

/* Interfaces test fixture */
class Sensor_unit : public ::testing::Test, public virtual upm::Sensor
{
protected:
    /* One-time setup logic if needed */
    Sensor_unit()
    {
        this->initFromJsonLibDesc("./Sensor_example.json");
    }

    /* One-time tear-down logic if needed */
    virtual ~Sensor_unit() {}

    /* Per-test setup logic if needed */
    virtual void SetUp() {}

    /* Per-test tear-down logic if needed */
    virtual void TearDown() {}
};


TEST_F(Sensor_unit, test_sources_deserialize)
{
    /* Deserialize the JSON to a map of sources */
    std::map<std::string, upm::SensorSource<std::string, std::string>> sources =
        LibraryJson()["Sensor Class"]["TestSensorClass"]["Sources"];

    ASSERT_EQ(2, sources.size());

    ASSERT_TRUE(sources.find("temperature") != sources.end());
    ASSERT_TRUE(sources.find("humidity-relative") != sources.end());
    ASSERT_EQ("C", sources["temperature"].unit);
    //    ASSERT_EQ("-17.0", sources["temperature"].min);
    //    ASSERT_EQ("49.0", sources["temperature"].max);
    //    ASSERT_EQ("1.0", sources["temperature"].accuracy);
}
