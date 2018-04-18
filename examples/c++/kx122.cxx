/*
 * The MIT License (MIT)
 *
 * Author: Samuli Rissanen <samuli.rissanen@hotmail.com>
 * Copyright (c) 2018 Rohm Semiconductor.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <iostream>
#include <signal.h>
#include <unistd.h>

#include "kx122.hpp"
#include "upm_utilities.h"

bool ctrl_c = false;

void sig_handler(int signo)
{
    ctrl_c = signo == SIGINT;
}

int main()
{
    signal(SIGINT, sig_handler);

    //! [Interesting]
    upm::KX122 sensor(0, -1, 24);

    /* Initiate blocking device reset */
    sensor.softwareReset();

    /* Initialize to 50 Hz, high resolution mode, 2G */
    sensor.deviceInit(KX122_ODR_50, HIGH_RES, KX122_RANGE_2G);

    /* Get the sample period in microseconds (should be 1/50 Hz = 20000 us) */
    int T_us = sensor.getSamplePeriod() * MICRO_S;
    if (T_us < 0)
    {
        std::cerr << "Failed to read valid sample period" << std::endl;
        return -1;
    }

    std::cout << "Sampling period: " << T_us << " us" << std::endl;

    while (!ctrl_c) {
        std::vector<float> xyz = sensor.getAccelerationDataVector();
        std::cout << "Acceleration X: " << xyz[0] << " m/s²" << std::endl
                  << "Acceleration Y: " << xyz[1] << " m/s²" << std::endl
                  << "Acceleration Z: " << xyz[2] << " m/s²" << std::endl
                  << std::endl;

        upm_delay_us(T_us);
    }
    //! [Interesting]

    return 0;
}
