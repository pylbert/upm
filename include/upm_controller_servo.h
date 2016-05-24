/*
 * upm_controller_servo.h
 *
 *  Created on: May 4, 2016
 *  Modified: Abhishek Malik <abhishek.malik@intel.com>
 */
#ifndef _UPM_CONTROLLER_SERVO_H_
#define _UPM_CONTROLLER_SERVO_H_

#include <stdarg.h>
#include <mraa/pwm.h>

#include "upm.h"

//#include "another.h"
//#define UPM_SERVO_MOTOR es08a

// Servo function table
typedef struct upm_ft_servo {
    void (*get_upm_descriptor) (upm_sensor_descriptor* desc);
    void* (*upm_servo_init) (int num,...);
    mraa_result_t (*upm_servo_close) (void* dev);
    mraa_result_t (*upm_servo_setangle) (void* dev, int32_t angle);
    int32_t (*upm_servo_calcpulsetravel) (void* dev, int32_t value);
    void (*upm_servo_setminpw) (void* dev, int width);
    void (*upm_servo_setmaxpw) (void* dev, int width);
    int (*upm_servo_getminpw) (void* dev);
    int (*upm_servo_getmaxpw) (void* dev);
} upm_ft_servo;

// Servo method helpers
typedef upm_ft_servo (*func_get_upm_ft_servo)();

#endif /* _UPM_CONTROLLER_SERVO_H_ */

