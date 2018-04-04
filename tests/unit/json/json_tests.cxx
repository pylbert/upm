#include "gtest/gtest.h"
#include "external/json/json.hpp"

namespace
{
    class source
    {
        public:
            std::string unit;
            float max;
            float min;
            float accuracy;
    };

    void to_json(nlohmann::json& j, const source& p) {
        j = nlohmann::json{
            {"unit", p.unit},
                {"min", p.min},
                {"max", p.max},
                {"accuracy", p.accuracy}};
    }

    void from_json(const nlohmann::json& j, source& p) {
        p.unit = j.at("unit").get<std::string>();
        p.min = j.at("min").get<float>();
        p.max = j.at("max").get<float>();
        p.accuracy = j.at("accuracy").get<float>();
    }

    bool operator==(const source& lhs, const source& rhs)
    {
        return lhs.unit == rhs.unit && lhs.min == rhs.min;
    }
}

/* Json test fixture */
class json_unit : public ::testing::Test
{
    protected:
        /* One-time setup logic if needed */
        json_unit() {}

        /* One-time tear-down logic if needed */
        virtual ~json_unit() {}

        /* Per-test setup logic if needed */
        virtual void SetUp() {}

        /* Per-test tear-down logic if needed */
        virtual void TearDown() {}
};

/* Test basic json serialization */
TEST_F(json_unit, test_basic_vector_serialization)
{
    std::vector<std::string> vec = {"one", "two", "three"};
    nlohmann::json j_vec(vec);
    ASSERT_EQ("[\"one\",\"two\",\"three\"]", j_vec.dump());

    std::vector<std::string> vec_clone = j_vec;
    ASSERT_EQ(vec, vec_clone);
}

/* Test basic json serialization */
TEST_F(json_unit, test_basic_map_serialization)
{
    std::map<std::string, int> map = {{"one", 1}, {"two", 2}, {"three", 3}};
    nlohmann::json map_j(map);
    ASSERT_EQ("{\"one\":1,\"three\":3,\"two\":2}", map_j.dump());

    std::map<std::string, int> map_clone = map_j;
    ASSERT_EQ(map, map_clone);
}

/* Test basic json serialization */
TEST_F(json_unit, test_basic_class_serialization)
{
    source s_temp {"C", -40.0, 85.0, 1.0};
    source s_humi {"%", 0.0, 100.0, 1.0};

    /* Create the json objects */
    nlohmann::json j_temp = s_temp;
    nlohmann::json j_humi = s_humi;

    /* Serialize/deserialize the originals */
    source temp_clone = j_temp;
    source humi_clone = j_humi;
    ASSERT_EQ(s_temp, temp_clone);
    ASSERT_EQ(s_humi, humi_clone);

    /* Populate an stl vector */
    std::vector<source> vec = {temp_clone, humi_clone};
    nlohmann::json vec_j(vec);
    ASSERT_EQ("[{\"accuracy\":1.0,\"max\":-40.0,\"min\":85.0,\"unit\":\"C\"},{\"accuracy\":1.0,\"max\":0.0,\"min\":100.0,\"unit\":\"%\"}]", vec_j.dump());

    /* Populate an stl map */
    std::map<std::string, source> sources;
    sources["temperature"] = s_temp;
    sources["humidity-relative"] = s_humi;

    /* Create the json object */
    nlohmann::json j_sources = sources;

    /* Serialize/deserialize the container */
    std::map<std::string, source> clone_sources = j_sources;
    ASSERT_EQ(sources, j_sources);
}

/* Currently no need for a custom main (use gtest's)
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
*/
