
#ifndef __AP_HAL_SITL_RCOUTPUT_H__
#define __AP_HAL_SITL_RCOUTPUT_H__

#include <AP_HAL/AP_HAL.h>
#if CONFIG_HAL_BOARD == HAL_BOARD_SITL
#include "AP_HAL_SITL.h"

class HALSITL::SITLRCOutput : public AP_HAL::RCOutput {
public:
    SITLRCOutput(SITL_State *sitlState) {
        _sitlState = sitlState;
        _freq_hz = 50;
    }
    void     init() override;
    void     set_freq(uint32_t chmask, uint16_t freq_hz) override;
    uint16_t get_freq(uint8_t ch) override;
    void     enable_ch(uint8_t ch) override;
    void     disable_ch(uint8_t ch) override;
    void     write(uint8_t ch, uint16_t period_us) override;
    uint16_t read(uint8_t ch) override;
    void     read(uint16_t* period_us, uint8_t len) override;

private:
    SITL_State *_sitlState;
    uint16_t _freq_hz;
    uint16_t _enable_mask;
};

#endif
#endif // __AP_HAL_SITL_RCOUTPUT_H__

