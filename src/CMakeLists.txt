cmake_minimum_required(VERSION 3.0.0)

file(GLOB SOURCE_FILES *.cpp)
file(GLOB HEADER_FILES *.hpp *.ipp)

add_executable(${CMAKE_PROJECT_NAME} 
  ${SOURCE_FILES}
  ${HEADER_FILES}
)