#pragma once

#include <map>
#include <vector>

#include "Sensor.hpp"

namespace upm
{
    /**
     * Pressure abstract class.
     *
     * Provides a common interface for all sensors which detect pressure.
     */
    class Pressure : public virtual Sensor
    {
        public:
            /**
             * Read and return all values for this sensor as a map of sources
             * to values.
             *
             * @return Map of sources to values.
             */
            virtual std::map<std::string, float> PressureAll();

            /**
             * Read and return a single value from the source provided
             *
             * @param source Target source to read
             *
             * @throws std::invalid_argument If source is NOT valid for this sensor
             *
             * @return Map of sources to values.
             */
            virtual float PressureForSource(std::string source);

            /**
             * Read and return all values for this sensor for the provided
             * vector of sources.
             *
             * @param sources Vector of sources to read
             *
             * @return Map of sources to values.
             */
            virtual std::map<std::string, float> PressureForSources(std::vector<std::string> sources) = 0;

            /**
             * Add a pointer to this type and a proxy function pointer for
             * serializing all values from this sensor type.
             */
            Pressure();

            /**
             * Read and return all values for this sensor as JSON
             *
             * @return JSON string of pressure values
             */
            virtual std::string JsonPressure() const;

        private:
            /**
             * Provide a means to read and serialize values from this sensor
             * as a static method.  This method, along with a pointer to the
             * class can be called from a base class
             *
             * @param inst Instance of Pressure to call _JsonPressure on
             *
             * @return JSON string of pressure values (minus wrapping '{' and '}'
             */
            static std::string _JsonPressure(Gadget * inst);
    };
}
