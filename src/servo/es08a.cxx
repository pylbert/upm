/*
 * Author: Yevgeniy Kiveisha <yevgeniy.kiveisha@intel.com>
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

#include <iostream>
#include <unistd.h>

#include "es08a.hpp"

using namespace upm;


ES08A::ES08A (std::string init_str): Servo(init_str)
{
    DEBUG_MSG("XXX");

    m_min_pw_us = 600;
    m_max_pw_us = 2200;
    m_period_us = 20000;
    m_max_angle = 180;

    /* Mraa string constructor parses Mraa types, left-overs need
     * additional parsing */
    if (_pwm.empty())
        throw std::runtime_error(std::string(__FUNCTION__) +
                ": One PWM pin is required.");
}

ES08A::ES08A (int pin) : ES08A(std::to_string(pin)) {
    DEBUG_MSG("XXX");
}

ES08A::~ES08A() {
    DEBUG_MSG("XXX");
}
