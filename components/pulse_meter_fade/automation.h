#pragma once

#include "esphome/core/component.h"
#include "esphome/core/automation.h"
#include "pulse_meter_sensor.h"

namespace esphome {

namespace pulse_meter_fade {

template<typename... Ts> class SetTotalPulsesAction : public Action<Ts...> {
 public:
  SetTotalPulsesAction(PulseMeterFadeSensor *pulse_meter_fade) : pulse_meter_fade_(pulse_meter_fade) {}

  TEMPLATABLE_VALUE(uint32_t, total_pulses)

  void play(Ts... x) override { this->pulse_meter_fade_->set_total_pulses(this->total_pulses_.value(x...)); }

 protected:
  PulseMeterFadeSensor *pulse_meter_fade_;
};

}  // namespace pulse_meter_fade
}  // namespace esphome
