# e-bot - Example module
Example which will allow you to create your own plugin to e-bot

## Building
`` mkdir build && cmake .. && make``

## First step, edit CMakeLists.txt
Find these lines and put your plugin name in place ``your_module_name``
``` CMake
add_library(your_module_name MODULE ${SRCS})

# Link TeamSpeak3-C-Query-API library
target_link_libraries(your_module_name teamspeak-api-${BUILD_ARCH})
```

## Second step, edit source files
By default, there is only one source file ``main.cpp``. You can add any number of files. Header files you should put in ``src/includes`` and source files in ``src``.
If you added any source file you must add this file to ``CMakeLists.txt``. To do this follow these steps:

#### 1. Find these lines 
```CMake
# Set of e-bot cpp files
set(SRCS
  src/main.cpp
)
```
#### 2. Put your new source file. For example: 
```CMake
# Set of e-bot cpp files
set(SRCS
  src/main.cpp
  src/my_new_source_file.cpp
)
```
#### 3. Build your project

