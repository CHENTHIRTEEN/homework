# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/10303/Desktop/数据结构/实验/work06

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/10303/Desktop/数据结构/实验/work06/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/work06.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/work06.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/work06.dir/flags.make

CMakeFiles/work06.dir/demo.cpp.o: CMakeFiles/work06.dir/flags.make
CMakeFiles/work06.dir/demo.cpp.o: ../demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/10303/Desktop/数据结构/实验/work06/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/work06.dir/demo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/work06.dir/demo.cpp.o -c /mnt/c/Users/10303/Desktop/数据结构/实验/work06/demo.cpp

CMakeFiles/work06.dir/demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/work06.dir/demo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/10303/Desktop/数据结构/实验/work06/demo.cpp > CMakeFiles/work06.dir/demo.cpp.i

CMakeFiles/work06.dir/demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/work06.dir/demo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/10303/Desktop/数据结构/实验/work06/demo.cpp -o CMakeFiles/work06.dir/demo.cpp.s

# Object files for target work06
work06_OBJECTS = \
"CMakeFiles/work06.dir/demo.cpp.o"

# External object files for target work06
work06_EXTERNAL_OBJECTS =

work06: CMakeFiles/work06.dir/demo.cpp.o
work06: CMakeFiles/work06.dir/build.make
work06: CMakeFiles/work06.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/10303/Desktop/数据结构/实验/work06/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable work06"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/work06.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/work06.dir/build: work06

.PHONY : CMakeFiles/work06.dir/build

CMakeFiles/work06.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/work06.dir/cmake_clean.cmake
.PHONY : CMakeFiles/work06.dir/clean

CMakeFiles/work06.dir/depend:
	cd /mnt/c/Users/10303/Desktop/数据结构/实验/work06/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/10303/Desktop/数据结构/实验/work06 /mnt/c/Users/10303/Desktop/数据结构/实验/work06 /mnt/c/Users/10303/Desktop/数据结构/实验/work06/cmake-build-debug /mnt/c/Users/10303/Desktop/数据结构/实验/work06/cmake-build-debug /mnt/c/Users/10303/Desktop/数据结构/实验/work06/cmake-build-debug/CMakeFiles/work06.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/work06.dir/depend

