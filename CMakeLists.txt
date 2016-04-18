cmake_minimum_required(VERSION 2.6)

# project title
project(boolex CXX)

# gcc flag for compiling c++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb")

include_directories("include")

# source files of calc part
file(GLOB_RECURSE boolex_calc_src
    "src/calc/*.cpp"
)

# source files of shunting_yard part
file(GLOB_RECURSE boolex_shunting_yard_src
    "src/shunting_yard/*.cpp"
)

# source files of lexan part
file(GLOB_RECURSE boolex_lexan_src
    "src/lexan/*.cpp"
)

# source files of util part
file(GLOB_RECURSE boolex_util_src
    "src/util/*.cpp"
)

# all source files
file(GLOB_RECURSE boolex_src
    "src/*.cpp"
)

add_library(calc OBJECT ${boolex_calc_src})
add_library(shunting_yard OBJECT ${boolex_shunting_yard_src})
add_library(lexan OBJECT ${boolex_lexan_src})

add_executable(boolex ${boolex_src})

add_executable(lexan_test test/lexan/lexan_test.cpp ${boolex_lexan_src} ${boolex_util_src})

add_executable(shunting_yard_test test/shunting_yard/shunting_yard_test.cpp ${boolex_shunting_yard_src} ${boolex_util_src})

add_executable(calc_test test/calc/binary_operand_test.cpp ${boolex_calc_src} ${boolex_util_src})

add_executable(boolex_test test/boolex_test.cpp ${boolex_calc_src} ${boolex_lexan_src} ${boolex_shunting_yard_src} ${boolex_util_src})