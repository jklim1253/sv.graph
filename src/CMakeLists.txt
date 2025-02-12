cmake_minimum_required(VERSION 3.0.0)

file(GLOB_RECURSE SOURCE_FILES
  RELATIVE "${CMAKE_CURRENT_LIST_DIR}"
  *.cpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
add_library(sv::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME}
  PROPERTY
    OUTPUT_NAME sv-${PROJECT_NAME}
)

target_link_libraries(${PROJECT_NAME}
  PRIVATE
)

target_include_directories(${PROJECT_NAME}
  PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}>
  $<INSTALL_INTERFACE:include>
)

export(TARGETS ${PROJECT_NAME}
  NAMESPACE sv::
  FILE "share/sv-${PROJECT_NAME}-export.cmake"
)
