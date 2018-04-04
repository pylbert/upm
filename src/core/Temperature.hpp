#pragma once

#include <map>
#include <vector>

#include "Sensor.hpp"

namespace upm
{
    enum TemperatureType
    {
        Celsius = 0,
        Fahrenheit = 1,
        Kelvin = 2,
        custom
    };

    /* JSON type de/serializer */
    void to_json(nlohmann::json& j, const SensorSource<float, TemperatureType>& p);
    void from_json(const nlohmann::json& j, SensorSource<float, TemperatureType>& p);

    /**
     * Temperature abstract class.
     *
     * Provides a common interface for all sensors which detect temperature.
     */
    class Temperature : public virtual Sensor
    {
        public:
            /**
             * Read and return all values for this sensor as a map of sources
             * to values.
             *
             * @return Map of sources to values.
             */
            virtual std::map<std::string, float> TemperatureAll();

            /**
             * Read and return a single value from the source provided
             *
             * @param source Target source to read
             *
             * @throws std::invalid_argument If source is NOT valid for this sensor
             *
             * @return Single temperature value
             */
            virtual float TemperatureForSource(std::string source);

            /**
             * Read and return a single value from the source provided and return the corresponding units
             *
             * @param source Target source to read
             *
             * @param unit Target unit
             *
             * @throws std::invalid_argument If source is NOT valid for this sensor
             *
             * @return Single temperature value with unit = @param unit
             */
            virtual float TemperatureAs(std::string source, TemperatureType unit);

            /**
             * Read and return all values for this sensor for the provided
             * vector of sources.
             *
             * @param sources Vector of sources to read
             *
             * @return Map of sources to values.
             */
            virtual std::map<std::string, float> TemperatureForSources(std::vector<std::string> sources) = 0;

            /**
             * Add a pointer to this type and a proxy function pointer for
             * serializing all values from this sensor type.
             */
            Temperature();

            /**
             * Read and return all values for this sensor as JSON
             *
             * @return JSON string of temperature values
             */
            virtual std::string JsonTemperature() const;

            std::map<std::string, SensorSource<float, TemperatureType>> &TemperatureSources();

            static float Convert(float value, TemperatureType from, TemperatureType to);
        private:
            /**
             * Provide a means to read and serialize values from this sensor
             * as a static method.  This method, along with a pointer to the
             * class can be called from a base class
             *
             * @param inst Instance of Temperature to call _JsonTemperature on
             *
             * @return JSON string of temperature values (minus wrapping '{' and '}'
             */
            static std::string _JsonTemperature(Gadget * inst);

            static std::string _DeserializeTemperatureSources(Gadget * inst);

            std::map<std::string, upm::SensorSource<float, TemperatureType>> _temp_sources;
    };
}
