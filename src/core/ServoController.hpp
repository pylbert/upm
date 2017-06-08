#pragma once

#include "Actuator.hpp"

namespace upm
{
    /**
     * ServoController abstract class.
     *
     * Provides a common interface for all sensors which detect light.
     */
    class ServoController : public virtual Actuator
    {
        public:
            /**
             * Add a pointer to this type and a proxy function pointer for
             * serializing all values from this sensor type.
             */
            ServoController();

            /* Provide a virtual destructor */
            virtual ~ServoController();

            /**
             * Read and return all values for this sensor as a map of commands
             * to values.
             *
             * @return Map of commands to values.
             */
            virtual void AngleAll(float angle);

            /**
             * Read and return a single value from the command provided
             *
             * @param command Target command to read
             *
             * @throws std::invalid_argument If command is NOT valid for this sensor
             *
             * @return Map of commands to values.
             */
            virtual void AngleForCommand(float angle, std::string command);

            /**
             * Read and return all values for this sensor for the provided
             * vector of commands.
             *
             * @param commands Vector of commands to read
             *
             * @return Map of commands to values.
             */
            virtual void AngleForCommands(std::map<std::string, float> commands) = 0;

            virtual void AngleFromJson(std::string json_commands);

        private:
            static std::string _DeserializeAngleCommands(Gadget * inst);
    };
}
