# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\Orsi\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Orsi\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Ford_Fulkerson.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Ford_Fulkerson.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ford_Fulkerson.dir/flags.make

CMakeFiles/Ford_Fulkerson.dir/main.cpp.obj: CMakeFiles/Ford_Fulkerson.dir/flags.make
CMakeFiles/Ford_Fulkerson.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ford_Fulkerson.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Ford_Fulkerson.dir\main.cpp.obj -c "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\main.cpp"

CMakeFiles/Ford_Fulkerson.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ford_Fulkerson.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\main.cpp" > CMakeFiles\Ford_Fulkerson.dir\main.cpp.i

CMakeFiles/Ford_Fulkerson.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ford_Fulkerson.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\main.cpp" -o CMakeFiles\Ford_Fulkerson.dir\main.cpp.s

CMakeFiles/Ford_Fulkerson.dir/FordFulkerson.cpp.obj: CMakeFiles/Ford_Fulkerson.dir/flags.make
CMakeFiles/Ford_Fulkerson.dir/FordFulkerson.cpp.obj: ../FordFulkerson.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Ford_Fulkerson.dir/FordFulkerson.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Ford_Fulkerson.dir\FordFulkerson.cpp.obj -c "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\FordFulkerson.cpp"

CMakeFiles/Ford_Fulkerson.dir/FordFulkerson.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ford_Fulkerson.dir/FordFulkerson.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\FordFulkerson.cpp" > CMakeFiles\Ford_Fulkerson.dir\FordFulkerson.cpp.i

CMakeFiles/Ford_Fulkerson.dir/FordFulkerson.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ford_Fulkerson.dir/FordFulkerson.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\FordFulkerson.cpp" -o CMakeFiles\Ford_Fulkerson.dir\FordFulkerson.cpp.s

# Object files for target Ford_Fulkerson
Ford_Fulkerson_OBJECTS = \
"CMakeFiles/Ford_Fulkerson.dir/main.cpp.obj" \
"CMakeFiles/Ford_Fulkerson.dir/FordFulkerson.cpp.obj"

# External object files for target Ford_Fulkerson
Ford_Fulkerson_EXTERNAL_OBJECTS =

Ford_Fulkerson.exe: CMakeFiles/Ford_Fulkerson.dir/main.cpp.obj
Ford_Fulkerson.exe: CMakeFiles/Ford_Fulkerson.dir/FordFulkerson.cpp.obj
Ford_Fulkerson.exe: CMakeFiles/Ford_Fulkerson.dir/build.make
Ford_Fulkerson.exe: CMakeFiles/Ford_Fulkerson.dir/linklibs.rsp
Ford_Fulkerson.exe: CMakeFiles/Ford_Fulkerson.dir/objects1.rsp
Ford_Fulkerson.exe: CMakeFiles/Ford_Fulkerson.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Ford_Fulkerson.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Ford_Fulkerson.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ford_Fulkerson.dir/build: Ford_Fulkerson.exe
.PHONY : CMakeFiles/Ford_Fulkerson.dir/build

CMakeFiles/Ford_Fulkerson.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Ford_Fulkerson.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Ford_Fulkerson.dir/clean

CMakeFiles/Ford_Fulkerson.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\cmake-build-debug" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\cmake-build-debug" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Ford_Fulkerson\cmake-build-debug\CMakeFiles\Ford_Fulkerson.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Ford_Fulkerson.dir/depend

