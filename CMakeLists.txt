cmake_minimum_required(VERSION 3.10)
project(CsvReader)
message("===== ${PROJECT_NAME} =====")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(CsvReaderTestOn "Build CsvReader tests" OFF)

# # Build library
add_library(${PROJECT_NAME} STATIC
  ${PROJECT_SOURCE_DIR}/src/csvreader_impl.cpp
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
  PUBLIC
)


# # Build test executable
if(CsvReaderTestOn)
  message(STATUS "Enable CsvReader tests")
  add_executable(csvreader_test
  ${PROJECT_SOURCE_DIR}/main.cpp
  )

  target_link_libraries(csvreader_test
    PUBLIC
    ${PROJECT_NAME}
  )
endif()