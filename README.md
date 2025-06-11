# ESPHome Pulse Meter Fade
Modified the pulse meter code to smooth the output when no pulse is detected - when a pulse is not detected for a longer time than the previous one, the output should be decreased accordingly (Author of modification: github.com/TrentHouliston/esphome/tree/pulse_fade , updated and prepared for direct import as external component by VeeoN)

# Example config:
- platform: pulse_meter_fade
    pin: 
      number: GPIO15 
    name: "Rainfall Rate"
    id: rainfall_rate
    icon: 'mdi:weather-rainy'
    device_class: "precipitation_intensity"
    accuracy_decimals: 1
    unit_of_measurement: "mm/h"
    timeout: 30min #after this time state=0
    internal_filter: 25ms
    fade: true #enable fading
    fade_interval: 1.05 #update state if last state = current_state * fade_interval - basicly how many samples to output durring fading (1=update state every loop iteration, 2=every new state is 50% of last)
    filters:
      - throttle_average: 15s #reduce updates rate
    total: #total works exacly as in pulse_meter
      unit_of_measurement: 'mm'
      id: rainfall_today
      name: 'Rainfall Today'
      icon: 'mdi:weather-rainy'
      device_class: "precipitation"
      accuracy_decimals: 1
      filters:
        - multiply: 0.1999