# == DO NEVER EDIT THE NEXT LINES for Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.0.0)
set(toolchainVersion 13_2_Rel1)
set(picotoolVersion 2.0.0)
if(EXISTS ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
    include(${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
elseif(DEFINED ENV{PICO_SDK_PATH})
    set(PICO_SDK_PATH $ENV{PICO_SDK_PATH})
else()
    set(PICO_SDK_PATH lib/pico-sdk)
endif()

if(DEFINED ENV{FREERTOS_PATH})
    set(FREERTOS_PATH $ENV{FREERTOS_PATH})
else()
    set(FREERTOS_PATH lib/freertos)
endif()

if(DEFINED ENV{UNITY_PATH})
    set(UNITY_PATH $ENV{UNITY_PATH})
else()
    set(UNITY_PATH lib/unity)
endif()

if(DEFINED ENV{PICO_EX_PATH})
    set(PICO_EX_PATH $ENV{PICO_EX_PATH})
else()
    set(PICO_EX_PATH lib/pico_extras)
endif()

# ====================================================================================
cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# This sets the variant of the board. We are using the pico_w
set(PICO_BOARD pico_w CACHE STRING "Board type")

# This imports the Pico SDK (must be included before the project)
include(${PICO_SDK_PATH}/pico_sdk_init.cmake)

add_subdirectory(${PICO_EX_PATH} pico-extras)
# include(${PICO_EX_PATH}/external/pico_extras_import.cmake)

# This imports the library configuration for FreeRTOS
include(${FREERTOS_PATH}/portable/ThirdParty/GCC/RP2040/FreeRTOS_Kernel_import.cmake)

# This sets up the unity library. They don't provide a library export, so it's defined locally.
include(unity.cmake)

# This defines your project name, you can name it anything you want.
project(myproject C CXX ASM)

# These are some macros from the pico SDK that do some setup.
pico_sdk_init()

# This sets a preprocessor value for use in our code.
add_compile_definitions(
    configNUMBER_OF_CORES=1
    PICO_ENTER_USB_BOOT_ON_EXIT=1
    )

# This is where your project header files are located.
include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
# file(GLOB_RECURSE INCLUDE_FILES "lib/pico_extras/src/rp2_common/**/*.h")
include_directories(${CMAKE_CURRENT_LIST_DIR}/lib/pico_extras/src/rp2_common)
# include_directories(${CMAKE_CURRENT_LIST_DIR}/lib/pico_extras/src/rp2_common/pico_audio_
# include_directories(${INCLUDE_FILES})

# The main executable is defined inside the src directory.
add_subdirectory(src)

# The test configuration is inside the test directory.
include(CTest)
add_subdirectory(test)
