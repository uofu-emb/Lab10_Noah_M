# This is the main binary. List your C files here.
add_executable(blink_with_thread
    blink_with_thread.c
    )

pico_set_program_name(blink_with_thread "test")
pico_set_program_version(blink_with_thread "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(blink_with_thread 0)
pico_enable_stdio_usb(blink_with_thread 1)

# file(GLOB_RECURSE INCLUDE_FILES "lib/pico_extras/src/rp2_common/**/*.h")

# Add the libraries to the build
target_link_libraries(blink_with_thread PRIVATE
  hardware_sleep
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(blink_with_thread PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(blink_with_thread)



# This is the main binary. List your C files here.
add_executable(blink_with_sleep_ms
blink_with_sleep_ms.c
    )

pico_set_program_name(blink_with_sleep_ms "test")
pico_set_program_version(blink_with_sleep_ms "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(blink_with_sleep_ms 0)
pico_enable_stdio_usb(blink_with_sleep_ms 1)

# Add the libraries to the build
target_link_libraries(blink_with_sleep_ms PRIVATE
  hardware_sleep
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(blink_with_sleep_ms PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(blink_with_sleep_ms)




# This is the main binary. List your C files here.
add_executable(busy_loop
busy_loop.c
    )

pico_set_program_name(busy_loop "test")
pico_set_program_version(busy_loop "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(busy_loop 0)
pico_enable_stdio_usb(busy_loop 1)

# Add the libraries to the build
target_link_libraries(busy_loop PRIVATE
  hardware_sleep
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(busy_loop PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(busy_loop)




# This is the main binary. List your C files here.
add_executable(interrupt_toggle
interrupt_toggle.c
    )

pico_set_program_name(interrupt_toggle "test")
pico_set_program_version(interrupt_toggle "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(interrupt_toggle 0)
pico_enable_stdio_usb(interrupt_toggle 1)

# Add the libraries to the build
target_link_libraries(interrupt_toggle PRIVATE
  hardware_sleep
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(interrupt_toggle PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(interrupt_toggle)





# This is the main binary. List your C files here.
add_executable(hello_sleep_alarm
hello_sleep_alarm.c
    )

pico_set_program_name(hello_sleep_alarm "test")
pico_set_program_version(hello_sleep_alarm "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(hello_sleep_alarm 0)
pico_enable_stdio_usb(hello_sleep_alarm 1)

# Add the libraries to the build
target_link_libraries(hello_sleep_alarm PRIVATE
  hardware_sleep
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(hello_sleep_alarm PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(hello_sleep_alarm)




# This is the main binary. List your C files here.
add_executable(hello_dormant_gpio
hello_dormant_gpio.c
    )

pico_set_program_name(hello_dormant_gpio "test")
pico_set_program_version(hello_dormant_gpio "0.1")

# Modify the below lines to enable/disable output over UART/USB.
# These are mutually exclusive, only set one.
pico_enable_stdio_uart(hello_dormant_gpio 0)
pico_enable_stdio_usb(hello_dormant_gpio 1)

# Add the libraries to the build
target_link_libraries(hello_dormant_gpio PRIVATE
  hardware_sleep
  pico_stdlib
  pico_multicore
  pico_async_context_freertos
  FreeRTOS-Kernel-Heap4
)

# The CYW43 is the Wifi/Bluetooth module. If the board is set to pico_w, this
# variable will be set and the wireless libraries added.
if(PICO_CYW43_SUPPORTED)
    # For led support on pico_w
    target_link_libraries(hello_dormant_gpio PRIVATE
        pico_cyw43_arch_none
    )
endif()

# Another pico macro which generates the uf2 file in addition to the elf
pico_add_extra_outputs(hello_dormant_gpio)