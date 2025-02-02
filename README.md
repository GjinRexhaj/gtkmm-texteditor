# GTKmm-texteditor				 
								 


## General Information/Usage
A simple text-editor program that uses GTK, and is built in C++ via GTKmm. 

This project uses CMake to handle building and library linking. 
Whilst this program is cross-platform in nature, it's intended to be used on Linux systems that use Gnome as their desktop environment.

Additionally, Cambalache was used in conjunction with GTK::Builder to design the UI. 

## Development Requirements
Prerequisites:

- An IDE that supports C++ development and CMake (CLion, Eclipse CDT, etc.)

- Cambalache (if planning on altering the UI)


This project uses gtkmm-4.0, which is fetched using pkg-config as specified in the top-level CMakeLists.txt file. GTKmm is then included and linked via the innermost CMake file (src/CMakeLists.txt).
Once you've configured CMake for this project, all dependencies should automatically be resolved.


## Source Structure
This section of the readme will document each and every file found in the root/src/ directory.

### main.cpp
Launching point of the program which contains all logic and functionality of the program.

### CMakeLists.txt
Inner-most CMakeLists.txt file, specifies include and linkage directories for GTKmm and that the executable will be built on main.cpp.

### ui/gtk-texteditor.cmb
Cambalache UI file -- Intended to be opened via Cambalache to allow for the altering of the UI.

### ui/gtk-texteditor.ui
XML file containing UI data generated from exporting the previously mentioned file in Cambalache. This file is fed into GTK::Builder to create the UI.
