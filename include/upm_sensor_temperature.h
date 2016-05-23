#ifndef _UPM_TEMPERATURE_H_
#define _UPM_TEMPERATURE_H_

#include <stdarg.h>
#include "upm.h"
#include "mraa/types.h"

// Temperature sensor function table
typedef struct upm_ft_temperature {
    void (*get_upm_descriptor) (upm_sensor_descriptor* desc);
    void* (*upm_temperature_init) (int num, ...);
    mraa_result_t (*upm_temperature_close) (void* dev);
    mraa_result_t (*upm_temperature_get_temperature) (void* dev);
} upm_ft_temperature;

// Temperature sensor helper methods
typedef upm_ft_temperature (*func_get_upm_ft_temperature)();

#endif /* _UPM_TEMPERATURE_H_ */
