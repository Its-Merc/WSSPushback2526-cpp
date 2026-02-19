#include <functional>

#include "api.h"
#include "ctrler.hpp"

using ToggleBtnCallback = std::function<void(int8_t)>;

class ToggleButton {
   private:
    int8_t state_;  // -1 = off, other states are for buttons

    const std::vector<pros::controller_digital_e_t> kBtns;
    const ToggleBtnCallback* kCallback;
    const uint32_t kCallbackUpdateRate;  // ms

    static pros::Controller& kCtrler;

   public:
    ToggleButton(std::vector<pros::controller_digital_e_t>& btns, int8_t init_state = -1,
                 ToggleBtnCallback* callback = nullptr, uint32_t callback_update_rate = 20);

    bool getState() const;

    void checkState();
};