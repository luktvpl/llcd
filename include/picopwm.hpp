#pragma once
//made by ShellAddicted original repo : https://github.com/ShellAddicted
#ifdef foo //pi pico
#include "hardware/clocks.h"
#include "hardware/pwm.h"
#include "pico/stdlib.h"
#else//other
#include "stdlib.h"
#include "stdio.h"
#include "toot.h"
#endif

#ifdef foo
class PicoPwm {
   protected:
    const int TOP_MAX = 65534;
    uint8_t pin = 0;
    uint8_t slice_num = 0;
    uint8_t channel = 0;
    uint32_t duty = 0;
    uint32_t div = 0;
    uint16_t top = 0;

   public:
    PicoPwm(uint8_t pin);
    ~PicoPwm();
    void setFrequency(uint32_t frequency);
    void setDuty(uint32_t duty);
    void setDutyPercentage(uint8_t percentage);
    void setInverted(bool inverted_a, bool inverted_b);

    uint8_t getPin();
    uint8_t getSlice();
    uint8_t getChannel();
    void stop();
};
#else
class PicoPwm {
   protected:
    const int TOP_MAX = 65534;
    u_int8_t pin = 0;
    u_int8_t slice_num = 0;
    u_int8_t channel = 0;
    u_int32_t duty = 0;
    u_int32_t div = 0;
    u_int16_t top = 0;

   public:
    PicoPwm(u_int8_t pin);
    ~PicoPwm();
    void setFrequency(u_int32_t frequency);
    void setDuty(u_int32_t duty);
    void setDutyPercentage(u_int8_t percentage);
    void setInverted(bool inverted_a, bool inverted_b);

    u_int8_t getPin();
    u_int8_t getSlice();
    u_int8_t getChannel();
    void stop();
};

#endif