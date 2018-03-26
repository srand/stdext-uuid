project(shell)
cmake_minimum_required(VERSION 3.5)

set(CMAKE_CXX_STANDARD 11)
include_directories(include)

add_library(stdext-uuid
  src/uuid.cpp
)

add_executable(stdext-uuid-test
  test/test.cpp
)

target_link_libraries(stdext-uuid-test stdext-uuid)
