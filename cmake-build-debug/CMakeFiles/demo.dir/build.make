# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/151/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/151/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/amit/CLionProjects/binarytree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/amit/CLionProjects/binarytree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/demo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/demo.dir/flags.make

CMakeFiles/demo.dir/Demo.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/Demo.cpp.o: ../Demo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amit/CLionProjects/binarytree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/demo.dir/Demo.cpp.o"
	/usr/bin/clang++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/Demo.cpp.o -c /home/amit/CLionProjects/binarytree/Demo.cpp

CMakeFiles/demo.dir/Demo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/Demo.cpp.i"
	/usr/bin/clang++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amit/CLionProjects/binarytree/Demo.cpp > CMakeFiles/demo.dir/Demo.cpp.i

CMakeFiles/demo.dir/Demo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/Demo.cpp.s"
	/usr/bin/clang++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amit/CLionProjects/binarytree/Demo.cpp -o CMakeFiles/demo.dir/Demo.cpp.s

CMakeFiles/demo.dir/sources/BinaryTree.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/sources/BinaryTree.cpp.o: ../sources/BinaryTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amit/CLionProjects/binarytree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/demo.dir/sources/BinaryTree.cpp.o"
	/usr/bin/clang++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/sources/BinaryTree.cpp.o -c /home/amit/CLionProjects/binarytree/sources/BinaryTree.cpp

CMakeFiles/demo.dir/sources/BinaryTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/sources/BinaryTree.cpp.i"
	/usr/bin/clang++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amit/CLionProjects/binarytree/sources/BinaryTree.cpp > CMakeFiles/demo.dir/sources/BinaryTree.cpp.i

CMakeFiles/demo.dir/sources/BinaryTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/sources/BinaryTree.cpp.s"
	/usr/bin/clang++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amit/CLionProjects/binarytree/sources/BinaryTree.cpp -o CMakeFiles/demo.dir/sources/BinaryTree.cpp.s

CMakeFiles/demo.dir/sources/BTIterator.cpp.o: CMakeFiles/demo.dir/flags.make
CMakeFiles/demo.dir/sources/BTIterator.cpp.o: ../sources/BTIterator.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/amit/CLionProjects/binarytree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/demo.dir/sources/BTIterator.cpp.o"
	/usr/bin/clang++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/demo.dir/sources/BTIterator.cpp.o -c /home/amit/CLionProjects/binarytree/sources/BTIterator.cpp

CMakeFiles/demo.dir/sources/BTIterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/demo.dir/sources/BTIterator.cpp.i"
	/usr/bin/clang++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/amit/CLionProjects/binarytree/sources/BTIterator.cpp > CMakeFiles/demo.dir/sources/BTIterator.cpp.i

CMakeFiles/demo.dir/sources/BTIterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/demo.dir/sources/BTIterator.cpp.s"
	/usr/bin/clang++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/amit/CLionProjects/binarytree/sources/BTIterator.cpp -o CMakeFiles/demo.dir/sources/BTIterator.cpp.s

# Object files for target demo
demo_OBJECTS = \
"CMakeFiles/demo.dir/Demo.cpp.o" \
"CMakeFiles/demo.dir/sources/BinaryTree.cpp.o" \
"CMakeFiles/demo.dir/sources/BTIterator.cpp.o"

# External object files for target demo
demo_EXTERNAL_OBJECTS =

demo: CMakeFiles/demo.dir/Demo.cpp.o
demo: CMakeFiles/demo.dir/sources/BinaryTree.cpp.o
demo: CMakeFiles/demo.dir/sources/BTIterator.cpp.o
demo: CMakeFiles/demo.dir/build.make
demo: CMakeFiles/demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/amit/CLionProjects/binarytree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable demo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/demo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/demo.dir/build: demo

.PHONY : CMakeFiles/demo.dir/build

CMakeFiles/demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/demo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/demo.dir/clean

CMakeFiles/demo.dir/depend:
	cd /home/amit/CLionProjects/binarytree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/amit/CLionProjects/binarytree /home/amit/CLionProjects/binarytree /home/amit/CLionProjects/binarytree/cmake-build-debug /home/amit/CLionProjects/binarytree/cmake-build-debug /home/amit/CLionProjects/binarytree/cmake-build-debug/CMakeFiles/demo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/demo.dir/depend

