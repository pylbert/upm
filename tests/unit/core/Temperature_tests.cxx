#include "gtest/gtest.h"
#include "Gadget.hpp"
#include "Sensor.hpp"
#include "Temperature.hpp"
#include "external/json/json.hpp"
#include <vector>

using namespace upm;

/* Mock RHUSB class */
class RHUSB : public virtual upm::Temperature
{
public:
    std::map<std::string, float> TemperatureForSources(std::vector<std::string> sources)
    {
        std::map<std::string, float> fake_temps;

        if (std::find(sources.begin(), sources.end(), "temperature") != sources.end())
            fake_temps["temperature"] = 25.5;

        return fake_temps;
    }
};

/* Interfaces test fixture */
class Temperature_unit : public ::testing::Test
{
 public:
        /* One-time setup logic if needed */
        Temperature_unit() : _rhusb(new RHUSB())
        {
            _rhusb->initFromJsonLibDesc("../../../src/rhusb/rhusb.json");
        }

        /* One-time tear-down logic if needed */
        virtual ~Temperature_unit() { delete _rhusb;}

        /* Per-test setup logic if needed */
        virtual void SetUp() {}

        /* Per-test tear-down logic if needed */
        virtual void TearDown() {}

        RHUSB* _rhusb;
};

TEST_F(Temperature_unit, test_Temperature)
{
    /* Two sources but only one is a temperature source */
    EXPECT_EQ(1, _rhusb->Sources().size());

    EXPECT_FLOAT_EQ(25.5, _rhusb->TemperatureForSource("temperature"));
}

TEST_F(Temperature_unit, test_temp_as_Celsius)
{
    EXPECT_FLOAT_EQ(25.5, _rhusb->TemperatureAs("temperature", TemperatureType::Celsius));
}

TEST_F(Temperature_unit, test_temp_as_Fahrenheit)
{
    EXPECT_FLOAT_EQ(77.9, _rhusb->TemperatureAs("temperature", TemperatureType::Fahrenheit));
}

TEST_F(Temperature_unit, test_temp_as_Kelvin)
{
    EXPECT_FLOAT_EQ(298.65, _rhusb->TemperatureAs("temperature", TemperatureType::Kelvin));
}

TEST_F(Temperature_unit, test_temp_Convert_All)
{
    float one = 1.0;

    /* From C */
    EXPECT_FLOAT_EQ(one, RHUSB::Convert(one, TemperatureType::Celsius, TemperatureType::Celsius));
    EXPECT_FLOAT_EQ(one * 9/5.0 + 32.0, RHUSB::Convert(one, TemperatureType::Celsius, TemperatureType::Fahrenheit));
    EXPECT_FLOAT_EQ(one + 273.15, RHUSB::Convert(one, TemperatureType::Celsius, TemperatureType::Kelvin));
    EXPECT_FLOAT_EQ(one, RHUSB::Convert(one, TemperatureType::Celsius, TemperatureType::custom));

    /* From F */
    EXPECT_FLOAT_EQ((one - 32) * 5.0/9, RHUSB::Convert(one, TemperatureType::Fahrenheit, TemperatureType::Celsius));
    EXPECT_FLOAT_EQ(one, RHUSB::Convert(one, TemperatureType::Fahrenheit, TemperatureType::Fahrenheit));
    EXPECT_FLOAT_EQ((one + 459.67) * 5.0/9, RHUSB::Convert(one, TemperatureType::Fahrenheit, TemperatureType::Kelvin));
    EXPECT_FLOAT_EQ(one, RHUSB::Convert(one, TemperatureType::Fahrenheit, TemperatureType::custom));

    /* From K */
    EXPECT_FLOAT_EQ(one - 273.15, RHUSB::Convert(one, TemperatureType::Kelvin, TemperatureType::Celsius));
    EXPECT_FLOAT_EQ(one * 9/5.0 - 459.67, RHUSB::Convert(one, TemperatureType::Kelvin, TemperatureType::Fahrenheit));
    EXPECT_FLOAT_EQ(one, RHUSB::Convert(one, TemperatureType::Kelvin, TemperatureType::Kelvin));
    EXPECT_FLOAT_EQ(one, RHUSB::Convert(one, TemperatureType::Kelvin, TemperatureType::custom));

    /* From custom */
    EXPECT_FLOAT_EQ(one, RHUSB::Convert(one, TemperatureType::custom, TemperatureType::Celsius));
    EXPECT_FLOAT_EQ(one, RHUSB::Convert(one, TemperatureType::custom, TemperatureType::Fahrenheit));
    EXPECT_FLOAT_EQ(one, RHUSB::Convert(one, TemperatureType::custom, TemperatureType::Kelvin));
    EXPECT_FLOAT_EQ(one, RHUSB::Convert(one, TemperatureType::custom, TemperatureType::custom));
}
