#ifndef _UPM_SENSOR_PRESSURE_H_
#define _UPM_SENSOR_PRESSURE_H_

#include <stdarg.h>
#include "upm.h"
#include "mraa/types.h"

// Pressure sensor function table
typedef struct upm_ft_pressure {
    void (*get_upm_descriptor) (upm_sensor_descriptor* desc);
    void* (*upm_pressure_init) (int num,...);
    mraa_result_t (*upm_pressure_close) (void* dev);
    int32_t (*upm_pressure_get_pressure) (void* dev);
} upm_ft_pressure;

// Pressure sensor helper methods
typedef upm_ft_pressure (*func_get_upm_ft_pressure)();

#endif /* _UPM_SENSOR_PRESSURE_H_ */
