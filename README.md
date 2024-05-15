# Arduino HomeKit ESP8266 


[中文说明](translations/README_cn.md) | [Português Brasileiro](translations/README-ptbr.md) | [Русский](translations/README-ru.md)


## Apple HomeKit accessory server library for ESP8266 Arduino

This Arduino library is a native Apple HomeKit accessory implementation for the [ESP8266 Arduino core](https://github.com/esp8266/Arduino), and works without any additional bridges.

This project is mainly based on [esp-homekit](https://github.com/maximkulkin/esp-homekit) for [ESP-OPEN-RTOS](https://github.com/SuperHouse/esp-open-rtos).

I ported the RTOS-based implementation of [esp-homekit](https://github.com/maximkulkin/esp-homekit) to the pure Arduino environment, aimed at easy and fast building project using Arduino IDE (or Eclipse with sloeber, PlatformIO).

Enjoy the "one-key" build, "one-key" upload, and work to link various other Arduino libraries with Apple HomeKit!

Here is a [discussion](https://github.com/HomeACcessoryKid/Arduino-HomeKit/issues/1) about the RTOS is required for running Apple HomeKit, and this project is a proof of concept that Apple HomeKit can be implemented and work fine without the RTOS.

This library is built with ESP8266 Arduino Core 2.6.3. Lower versions may compile with errors.

For ESP32, see [Arduino-HomeKit-ESP32](https://github.com/Mixiaoxiao/Arduino-HomeKit-ESP32). The HomeKit running on ESP32 has a **GREAT PERFORMANCE** which is 10x faster than ESP8266.

## Preview

![Preview](https://raw.github.com/Mixiaoxiao/Arduino-HomeKit-ESP8266/master/extras/preview.jpg) 


## Setup code of the example sketch

``111-11-111``


## Usage

1. Define your accessory in a .c file to enjoy the  convenient "Macro" style declaration. You can also define your accessory in a .ino file using C++ code.
	```C
		homekit_accessory_t *accessories[] = ...
		homekit_server_config_t config = {
			.accessories = accessories,
			.password = "111-11-111",
			//.on_event = on_homekit_event, //optional
			//.setupId = "ABCD" //optional
		};
	```
2. In your sketch
	```C
		#include <arduino_homekit_server.h>;
		
		//access the config defined in C code
		extern "C" homekit_server_config_t config; 
		
		void setup() {
			WiFi.begin(ssid, password);
			arduino_homekit_setup(&config);
		}
		
		void loop() {
			arduino_homekit_loop();
		}
	```
Done.










