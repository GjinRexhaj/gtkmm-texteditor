cmake_minimum_required(VERSION 3.30.5)

# Set some basic project attributes
project (gtkmm-texteditor
	VERSION 0.1
	DESCRIPTION "A Basic Text Editor written with GTKmm")


# find GTKMM lib
find_package(PkgConfig)
pkg_check_modules(GTKMM gtkmm-4.0)


# Add subdir src
add_subdirectory(src)