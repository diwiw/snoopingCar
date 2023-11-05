# Find the package for Qt5 if you're using Qt
find_package(Qt6 COMPONENTS Widgets REQUIRED)

# Check if the package has been found
if(Qt6_FOUND)
	message(STATUS "Qt6 found successfully.")
	# Add Qt targets and link against the Qt libraries
	# add_executable()
	# target_link_libraries()
else()
	message(WARNING "Qt6 not found on this system.")
endif()

# Add GUI targets here 
qt6_wrap_ui(UIS_HDRS MainWindows.ui)

#add_library(gui MainWindow.cpp ${UIS_HDRS})
#target_link_libraries(gui Qt6::Widgets)