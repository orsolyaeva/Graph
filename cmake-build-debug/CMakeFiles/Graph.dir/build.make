# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Graph.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Graph.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Graph.dir/flags.make

CMakeFiles/Graph.dir/main.cpp.obj: CMakeFiles/Graph.dir/flags.make
CMakeFiles/Graph.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Graph.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Graph.dir\main.cpp.obj -c "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\main.cpp"

CMakeFiles/Graph.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Graph.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\main.cpp" > CMakeFiles\Graph.dir\main.cpp.i

CMakeFiles/Graph.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Graph.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\main.cpp" -o CMakeFiles\Graph.dir\main.cpp.s

# Object files for target Graph
Graph_OBJECTS = \
"CMakeFiles/Graph.dir/main.cpp.obj"

# External object files for target Graph
Graph_EXTERNAL_OBJECTS =

Graph.exe: CMakeFiles/Graph.dir/main.cpp.obj
Graph.exe: CMakeFiles/Graph.dir/build.make
Graph.exe: CMakeFiles/Graph.dir/linklibs.rsp
Graph.exe: CMakeFiles/Graph.dir/objects1.rsp
Graph.exe: CMakeFiles/Graph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Graph.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Graph.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Graph.dir/build: Graph.exe

.PHONY : CMakeFiles/Graph.dir/build

CMakeFiles/Graph.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Graph.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Graph.dir/clean

CMakeFiles/Graph.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\cmake-build-debug" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\cmake-build-debug" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\cmake-build-debug\CMakeFiles\Graph.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Graph.dir/depend

