#include "gui.hpp"

namespace gui {
void OnCenterBtnPressed() {
    static bool pressed = false;
    pressed = !pressed;
    if (pressed) {
        pros::lcd::set_text(2, "holy fucking shit did you just fucking touch me");
        pros::lcd::set_text(3, "i liked it~");
    } else {
        pros::lcd::clear_line(2);
        pros::lcd::clear_line(3);
    }
}
}  // namespace gui
