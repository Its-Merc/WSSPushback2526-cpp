#include "togglebutton.hpp"

ToggleButton::ToggleButton(std::vector<pros::controller_digital_e_t>& btns, int8_t init_state,
                           ToggleBtnCallback* callback = nullptr, uint32_t callback_update_rate)
    : kBtns(btns[0]), state_(init_state), kCallback(callback), kCallbackUpdateRate(callback_update_rate) {
    kCtrler = ctrler::get();
}

bool ToggleButton::getState() const {
    return state_;
}

void ToggleButton::checkState() {
    static int8_t prev_state = state_;

    // get state from which button has been most recently pressed
    for (size_t i = 0; i < kBtns.size(); i++) {
        if (kCtrler.get_digital_new_press(kBtns[i])) {
            state_ = prev_state == state_ ? -1 : i;
            break;
        }
    }

    if (kCallback) (*kCallback)(state_);
}
