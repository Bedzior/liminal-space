###
# MIT License
# Copyright (C) 2019, by Matvey Cherevko (blackmatov@gmail.com)
# Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
# The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
###

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(GBA_FLAGS "\
    -mthumb-interwork\
    -mthumb\
    -mcpu=arm7tdmi\
    -mtune=arm7tdmi\
    -specs=gba.specs")

set(CMAKE_C_FLAGS "\
    ${GBA_FLAGS}\
    -Wall\
    -Wextra\
    -ffast-math\
    -fno-strict-aliasing")

set(CMAKE_CXX_FLAGS "\
    ${CMAKE_C_FLAGS}\
    -fno-rtti\
    -fno-exceptions")

set(CMAKE_C_COMPILER "${DEVKITARM_PATH}/bin/arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "${DEVKITARM_PATH}/bin/arm-none-eabi-g++")
