#pragma once

#include <map>
#include <vector>

#include "Sensor.hpp"

namespace upm
{
    /**
     * Gas abstract class.
     *
     * Provides a common interface for all sensors which detect gases.
     */
    class Gas : public virtual upm::Sensor
    {
        public:
            /**
             * Read and return all values for this sensor as a map of sources
             * to values.
             *
             * @return Map of sources to values.
             */
            virtual std::map<std::string, float> GasAll();

            /**
             * Read and return a single value from the source provided
             *
             * @param source Target source to read
             *
             * @throws std::invalid_argument If source is NOT valid for this sensor
             *
             * @return Map of sources to values.
             */
            virtual float GasForSource(std::string source);

            /**
             * Read and return all values for this sensor for the provided
             * vector of sources.
             *
             * @param sources Vector of sources to read
             *
             * @return Map of sources to values.
             */
            virtual std::map<std::string, float> GasForSources(std::vector<std::string> sources) = 0;

            /**
             * Add a pointer to this type and a proxy function pointer for
             * serializing all values from this sensor type.
             */
            Gas();

            /**
             * Read and return all values for this sensor as JSON
             *
             * @return JSON string of gas values
             */
            virtual std::string JsonGas() const;

        private:
            /**
             * Provide a means to read and serialize values from this sensor
             * as a static method.  This method, along with a pointer to the
             * class can be called from a base class
             *
             * @param inst Instance of Gas to call _JsonGas on
             *
             * @return JSON string of gas values (minus wrapping '{' and '}'
             */
            static std::string _JsonGas(Gadget * inst);
    };
}
