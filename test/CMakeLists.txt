cmake_minimum_required(VERSION 3.21)

project(graph-sample CXX)

file(GLOB_RECURSE SOURCE_FILES
  RELATIVE "${CMAKE_CURRENT_LIST_DIR}"
  *.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME}
  PROPERTY
    OUTPUT_NAME sv-${PROJECT_NAME}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
    sv::graph
)
