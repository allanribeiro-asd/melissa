
Remember to pull up the DHT11 data pin, and to use gpio4 (d4) as data pin


```
+-.-.-.-+
| . . . |
. . . . .
. . . . .
| . . . |
. . . . .
+|-|-|-|+
 | | |  \__ GND
 | |  \
 |  \  \___ NC
 |   \
  \   \____ DATA
   \
    \______ VCC

```

Hold boot0 button, and press nrst

openocd must have warned you

[Cool guy](https://mcturra2000.wordpress.com/2021/11/07/stm32f411-blink-sketch-using-cmsis-vim-and-a-makefile/)
This guy is nice because he taught in doing what I wanted: use only vim, gcc and gdb,
with no HAL trash running, or any bloated IDE.

[dbridges](https://github.com/dbridges/stm32f4-discovery-lib/)
This repo contains all STM32F411 libraries files used in this application



(See the README.md file in the upper level 'examples' directory for more information about examples.)

FreeRTOS provides the function `vTaskGetRunTimeStats()` to obtain CPU usage statistics of tasks. However, these statistics are with respect to the entire runtime of FreeRTOS (i.e. **run time stats**). Furthermore, statistics of `vTaskGetRunTimeStats()` are only valid whilst the timer for run time statistics has not overflowed.

This example demonstrates how to get CPU usage statistics of tasks with respect to a specified duration (i.e. **real time stats**) rather than over the entire runtime of FreeRTOS. The `print_real_time_stats()` function of this example demonstrates how this can be achieved.

## How to use example

### Hardware Required

This example should be able to run on any commonly available ESP32 development board.

### Configure the project

```
idf.py menuconfig
```

* Select `Enable FreeRTOS to collect run time stats` under `Component Config > FreeRTOS` (this should be enabled in the example by default)

* `Choose the clock source for run time stats` configured under `Component Config > FreeRTOS`. The `esp_timer` should be selected be default. This option will affect the time unit resolution in which the statistics are measured with respect to.

### Build and Flash

Build the project and flash it to the board, then run monitor tool to view serial output:

```
idf.py -p PORT flash monitor
```

(Replace PORT with the name of the serial port to use.)

(To exit the serial monitor, type ``Ctrl-]``.)

See the Getting Started Guide for full steps to configure and use ESP-IDF to build projects.

## Example Output

The example should have the following log output:

```
```
