project(tesseract_z_test)

cmake_minimum_required (VERSION 2.6)

SET(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules/")
FIND_PACKAGE( Tesseract REQUIRED )
include_directories(${Tesseract_INCLUDE_DIRS})

ADD_EXECUTABLE( tesseract_z_test  main.cpp )
TARGET_LINK_LIBRARIES(tesseract_z_test
  ${Tesseract_LIBRARIES}
)
