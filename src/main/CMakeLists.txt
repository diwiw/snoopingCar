add_executable(snoopingCar main.cpp)

# Link the executable with other components, if they are libraries
target_link_libraries(snoopingCar gui network image_processing hardware utils)