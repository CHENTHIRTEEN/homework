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
CMAKE_SOURCE_DIR = /mnt/c/Users/10303/Desktop/数据结构/实验/work01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/10303/Desktop/数据结构/实验/work01/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/work01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/work01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/work01.dir/flags.make

CMakeFiles/work01.dir/sqlist.cpp.o: CMakeFiles/work01.dir/flags.make
CMakeFiles/work01.dir/sqlist.cpp.o: ../sqlist.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/10303/Desktop/数据结构/实验/work01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/work01.dir/sqlist.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/work01.dir/sqlist.cpp.o -c /mnt/c/Users/10303/Desktop/数据结构/实验/work01/sqlist.cpp

CMakeFiles/work01.dir/sqlist.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/work01.dir/sqlist.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/10303/Desktop/数据结构/实验/work01/sqlist.cpp > CMakeFiles/work01.dir/sqlist.cpp.i

CMakeFiles/work01.dir/sqlist.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/work01.dir/sqlist.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/10303/Desktop/数据结构/实验/work01/sqlist.cpp -o CMakeFiles/work01.dir/sqlist.cpp.s

# Object files for target work01
work01_OBJECTS = \
"CMakeFiles/work01.dir/sqlist.cpp.o"

# External object files for target work01
work01_EXTERNAL_OBJECTS =

work01: CMakeFiles/work01.dir/sqlist.cpp.o
work01: CMakeFiles/work01.dir/build.make
work01: CMakeFiles/work01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/10303/Desktop/数据结构/实验/work01/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable work01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/work01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/work01.dir/build: work01

.PHONY : CMakeFiles/work01.dir/build

CMakeFiles/work01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/work01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/work01.dir/clean

CMakeFiles/work01.dir/depend:
	cd /mnt/c/Users/10303/Desktop/数据结构/实验/work01/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/10303/Desktop/数据结构/实验/work01 /mnt/c/Users/10303/Desktop/数据结构/实验/work01 /mnt/c/Users/10303/Desktop/数据结构/实验/work01/cmake-build-debug /mnt/c/Users/10303/Desktop/数据结构/实验/work01/cmake-build-debug /mnt/c/Users/10303/Desktop/数据结构/实验/work01/cmake-build-debug/CMakeFiles/work01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/work01.dir/depend

