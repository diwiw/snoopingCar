cmake_minimum_required(VERSION 3.16)
project("snoopingCar")

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include the subdirectories
add_subdirectory(src)
#add_subdirectory(libs)
# add_subdirectory()

# Enable testing if you have tests in the 'tests' directory
# enable_testing()
# add_subdirectory(tests)

# add_subdirectory(docs)

