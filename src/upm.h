/*
 * Author: Brendan Le Foll <brendan.le.foll@intel.com>
 * Contributions: Mihai Tudor Panu <mihai.tudor.panu@intel.com>
 * Copyright (c) 2014 Intel Corporation.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#pragma once

/// @cond DEV
/**
 * This file only serves to describe sensor groups based on libmraa groups.
 * Sensors may belong to multiple groups. This is purely a documentation header
 * and is not meant to be installed anywhere.
 */
/// @endcond DEV

////////////////////////////////////////////////////////////////// @cond HEA
/// Main group place holders.
////////////////////////////////////////////////////////////////// @endcond HEA

/**
 * @brief Sensors grouped by category
 * @defgroup bycat Sensor Categories
 */

/**
 * @brief Sensors grouped by C++ interface
 * @defgroup byif C++ Interface
 */

/**
 * @brief Sensors grouped by connection type
 * @defgroup bycon Connection Type
 */

/**
 * @brief Sensors grouped by manufacturer
 * @defgroup byman Manufacturer
 */

/**
 * @brief Sensors grouped into starter kits
 * @defgroup bykit Starter Kits
 */

////////////////////////////////////////////////////////////////// @cond CAT
/// Groups for the various Sensor Categories.
////////////////////////////////////////////////////////////////// @endcond CAT

/**
 * @brief Measure acceleration & tilt or collision detection
 * @defgroup accelerometer Accelerometer
 * @ingroup bycat
 */

/**
 * @brief Sensors with a variable voltage output
 * @defgroup ainput Analog Inputs
 * @ingroup bycat
 */

/**
 * @brief Measure pressure and atmospheric conditions
 * @defgroup pressure Atmospheric Pressure
 * @ingroup bycat
 */

/**
 * @brief Button, Switch or Toggle
 * @defgroup button Button
 * @ingroup bycat
 */

/**
 * @brief Light sensors with special function: Color recognition
 * @defgroup color Color Sensor
 * @ingroup bycat
 */

/**
 * @brief Measure magnetic field to give rotation or heading
 * @defgroup compass Compass/Gyro/Magnometers
 * @ingroup bycat
 */

/**
 * @brief Resistive digital to analog converters (DAC)
 * @defgroup digipot Digital Potentiometer
 * @ingroup bycat
 */

/**
 * @brief TFT, LCD, LED display elements
 * @defgroup display Displays
 * @ingroup bycat
 */

/**
 * @brief Measure electric current and ADC converters
 * @defgroup electric Electricity
 * @ingroup bycat
 */

/**
 * @brief Measure bending or detect vibration
 * @defgroup flexfor Flex/Force
 * @ingroup bycat
 */

/**
 * @brief Measure substance concentrations in gases
 * @defgroup gaseous Gas
 * @ingroup bycat
 */

/**
 * @brief Provide positioning capabilities
 * @defgroup gps GPS
 * @ingroup bycat
 */

/**
 * @brief LEDs, LED strips, LED matrix displays & controllers
 * @defgroup led LEDs
 * @ingroup bycat
 */

/**
 * @brief Measure light intensity or distances
 * @defgroup light Light/Proximity/IR
 * @ingroup bycat
 */

/**
 * @brief Measure liquid flow rates or levels
 * @defgroup liquid Liquid Flow
 * @ingroup bycat
 */

/**
 * @brief Sensors with specific medical application
 * @defgroup medical Medical
 * @ingroup bycat
 */

/**
 * @brief Various motors & controllers to get things moving
 * @defgroup motor Motor
 * @ingroup bycat
 */

/**
 * @brief Other types of supported sensors
 * @defgroup other Other
 * @ingroup bycat
 */

/**
 * @brief Different low and high power relays
 * @defgroup relay Relay
 * @ingroup bycat
 */

/**
 * @brief Wireless sensors using RFID tags
 * @defgroup rfid RFID
 * @ingroup bycat
 */

/**
 * @brief Various servo motors & controllers
 * @defgroup servos Servo
 * @ingroup bycat
 */

/**
 * @brief Provide sound recording or playback
 * @defgroup sound Sound
 * @ingroup bycat
 */

/**
 * @brief Measure temperature & humidity
 * @defgroup temp Temperature/Humidity
 * @ingroup bycat
 */

/**
 * @brief Sensors using serial communication
 * @defgroup serial Serial
 * @ingroup bycat
 */

/**
 * @brief Real time clocks & time measurement
 * @defgroup time Time
 * @ingroup bycat
 */

/**
 * @brief Capacitive touch sensors
 * @defgroup touch Touch Sensor
 * @ingroup bycat
 */

/**
 * @brief Provide video or video camera access
 * @defgroup video Video
 * @ingroup bycat
 */

/**
 * @brief Provide WiFi, Bluetooth, RF communication
 * @defgroup wifi Wireless Communication
 * @ingroup bycat
 */

////////////////////////////////////////////////////////////////// @cond IF
/// Groups for the various Sensor C++ Interfaces.
////////////////////////////////////////////////////////////////// @endcond IF

/**
 * @brief Implements ILightSensor
 * @defgroup ilightsensor ILightSensor
 * @ingroup byif
 */

 /**
 * @brief Implements ILightController
 * @defgroup ilightcontroller ILightController
 * @ingroup byif
 */

/**
 * @brief Implements IPressureSensor
 * @defgroup ipressuresensor IPressureSensor
 * @ingroup byif
 */

 /**
 * @brief Implements ITemperatureSensor
 * @defgroup itemperaturesensor ITemperatureSensor
 * @ingroup byif
 */

/**
 * @brief Implements IADC
 * @defgroup iadc IADC
 * @ingroup byif
 */

 /**
 * @brief Implements ICOSensor
 * @defgroup ic02sensor ICOSensor
 * @ingroup byif
 */


////////////////////////////////////////////////////////////////// @cond CON
/// Groups for the various Connection Types.
////////////////////////////////////////////////////////////////// @endcond CON

/**
 * @brief Sensors requiring an ADC value to be read
 * @defgroup analog AIO
 * @ingroup bycon
 */

/**
 * @brief Modules using the i2c bus
 * @defgroup i2c I2C
 * @ingroup bycon
 */

/**
 * @brief Modules using the SPI bus
 * @defgroup spi SPI
 * @ingroup bycon
 */

/**
 * @brief Modules using GPIOs directly
 * @defgroup gpio GPIO
 * @ingroup bycon
 */

/**
 * @brief Modules using a PWM capable GPIO pin
 * @defgroup pwm PWM
 * @ingroup bycon
 */

/**
 * @brief Modules using a serial connection (RX/TX)
 * @defgroup uart UART
 * @ingroup bycon
 */

////////////////////////////////////////////////////////////////// @cond MAN
/// Groups for the various Manufacturers.
////////////////////////////////////////////////////////////////// @endcond MAN

/**
 * @brief Adafruit Industries
 * @defgroup adafruit Adafruit
 * @ingroup byman
 */

/**
 * @brief EMax
 * @defgroup emax EMax
 * @ingroup byman
 */

/**
 * @brief DFRobot
 * @defgroup dfrobot DFRobot
 * @ingroup byman
 */

/**
 * @brief Comet System
 * @defgroup comet Comet
 * @ingroup byman
 */

/**
 * @brief EpicTinker
 * @defgroup epict EpicTinker
 * @ingroup byman
 */

/**
 * @brief Freescale
 * @defgroup freescale Freescale
 * @ingroup byman
 */
 
/**
 * @brief Generic Brands
 * @defgroup generic Generic
 * @ingroup byman
 */

/**
 * @brief Honeywell
 * @defgroup honeywell Honeywell
 * @ingroup byman
 */

/**
 * @brief Maxim Integrated
 * @defgroup maxim Maxim Integrated
 * @ingroup byman
 */

/**
 * @brief Numato Labs
 * @defgroup numatolabs Numato Labs
 * @ingroup byman
 */

/**
 * @brief Mouser
 * @defgroup mouser Mouser
 * @ingroup byman
 */

/**
 * @brief Omega
 * @defgroup omega Omega
 * @ingroup byman
 */

/**
 * @brief SeeedStudio - Grove Sensors
 * @defgroup seeed SeeedStudio
 * @ingroup byman
 */

/**
 * @brief Sparkfun
 * @defgroup sparkfun Sparkfun
 * @ingroup byman
 */

/**
 * @brief Texas Instruments
 * @defgroup ti Texas Instruments
 * @ingroup byman
 */

/**
 * @brief Veris Industries
 * @defgroup veris Veris Industries
 * @ingroup byman
 */

 /**
 * @brief Silicon Labs
 * @defgroup silabs Silicon Labs
 * @ingroup byman
 */

/**
 * @brief Bosch
 * @defgroup bosch Bosch
 * @ingroup byman
 */

/**
 * @brief Amphenol
 * @defgroup amphenol Amphenol
 * @ingroup byman
 */
 
/**
 * @brief Open Electrons
 * @defgroup openelectrons Open Electrons
 * @ingroup byman
 */ 

////////////////////////////////////////////////////////////////// @cond KIT
/// Groups for the various Starter Kits.
////////////////////////////////////////////////////////////////// @endcond KIT

/**
 * @brief Grove Starter Kit - Contains basic sensors
 * @defgroup gsk Grove Starter Kit
 * @ingroup bykit
 */
 
/**
 * @brief Home Automation Kit - For projects around the house
 * @defgroup hak Home Automation Kit
 * @ingroup bykit
 */ 

/**
 * @brief Environment & Agriculture Kit - For outdoor projects
 * @defgroup eak Environment & Agriculture Kit
 * @ingroup bykit
 */
 
/**
 * @brief Transportation & Safety Kit - Used mostly on vehicles 
 * @defgroup tsk Transportation & Safety Kit
 * @ingroup bykit
 */
 
/**
 * @brief Robotics Kit - Sensors for your robot
 * @defgroup robok Robotics Kit
 * @ingroup bykit
 */

#define upm_sensor_category_invalid 0
#define upm_sensor_category_size 5

// Sensor categories (all sensors have *at least* 1)
typedef enum {
    UPM_INVALID = 0,
    UPM_PH,
    UPM_PRESSURE,
    UPM_SERVO,
    UPM_TEMPERATURE
} upm_sensor_category;

// Sensor descriptor
typedef struct upm_sensor_descriptor {
    char name[20];
    char description[100];
    upm_sensor_category category[upm_sensor_category_size];
} upm_sensor_descriptor;

// UPM helper methods
typedef void (*func_get_upm_descriptor)(upm_sensor_descriptor* desc);

const char * to_char(upm_sensor_category category)
{
    switch(category) {
        case UPM_PH:
            return "PH";
            break;
        case UPM_PRESSURE:
            return "PRESSURE";
            break;
        case UPM_SERVO:
            return "SERVO";
            break;
        case UPM_TEMPERATURE:
            return "TEMPERATURE";
            break;
        default:
            return "INVALID";
    }
}

/**
 * UPM return codes, copied from MRAA
 * TODO: Find a better solution here
 */
typedef enum {
    UPM_SUCCESS = 0,                             /**< Expected response */
    UPM_ERROR_FEATURE_NOT_IMPLEMENTED = 1,       /**< Feature TODO */
    UPM_ERROR_FEATURE_NOT_SUPPORTED = 2,         /**< Feature not supported by HW */
    UPM_ERROR_INVALID_VERBOSITY_LEVEL = 3,       /**< Verbosity level wrong */
    UPM_ERROR_INVALID_PARAMETER = 4,             /**< Parameter invalid */
    UPM_ERROR_INVALID_HANDLE = 5,                /**< Handle invalid */
    UPM_ERROR_NO_RESOURCES = 6,                  /**< No resource of that type avail */
    UPM_ERROR_INVALID_RESOURCE = 7,              /**< Resource invalid */
    UPM_ERROR_INVALID_QUEUE_TYPE = 8,            /**< Queue type incorrect */
    UPM_ERROR_NO_DATA_AVAILABLE = 9,             /**< No data available */
    UPM_ERROR_INVALID_PLATFORM = 10,             /**< Platform not recognised */
    UPM_ERROR_PLATFORM_NOT_INITIALISED = 11,     /**< Board information not initialised */
    UPM_ERROR_UART_OW_SHORTED = 12,              /**< UART OW Short Circuit Detected*/
    UPM_ERROR_UART_OW_NO_DEVICES = 13,           /**< UART OW No devices detected */
    UPM_ERROR_UART_OW_DATA_ERROR = 14,           /**< UART OW Data/Bus error detected */

    UPM_ERROR_UNSPECIFIED = 99 /**< Unknown Error */
} upm_result_t;

#define upm_perror(...) perror(args, __VA_ARGS__)
