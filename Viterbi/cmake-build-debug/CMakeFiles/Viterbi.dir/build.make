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
CMAKE_SOURCE_DIR = "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Viterbi.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Viterbi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Viterbi.dir/flags.make

CMakeFiles/Viterbi.dir/main.cpp.obj: CMakeFiles/Viterbi.dir/flags.make
CMakeFiles/Viterbi.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Viterbi.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Viterbi.dir\main.cpp.obj -c "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\main.cpp"

CMakeFiles/Viterbi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Viterbi.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\main.cpp" > CMakeFiles\Viterbi.dir\main.cpp.i

CMakeFiles/Viterbi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Viterbi.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\main.cpp" -o CMakeFiles\Viterbi.dir\main.cpp.s

CMakeFiles/Viterbi.dir/Viterbi.cpp.obj: CMakeFiles/Viterbi.dir/flags.make
CMakeFiles/Viterbi.dir/Viterbi.cpp.obj: ../Viterbi.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Viterbi.dir/Viterbi.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Viterbi.dir\Viterbi.cpp.obj -c "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\Viterbi.cpp"

CMakeFiles/Viterbi.dir/Viterbi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Viterbi.dir/Viterbi.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\Viterbi.cpp" > CMakeFiles\Viterbi.dir\Viterbi.cpp.i

CMakeFiles/Viterbi.dir/Viterbi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Viterbi.dir/Viterbi.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\Viterbi.cpp" -o CMakeFiles\Viterbi.dir\Viterbi.cpp.s

# Object files for target Viterbi
Viterbi_OBJECTS = \
"CMakeFiles/Viterbi.dir/main.cpp.obj" \
"CMakeFiles/Viterbi.dir/Viterbi.cpp.obj"

# External object files for target Viterbi
Viterbi_EXTERNAL_OBJECTS =

Viterbi.exe: CMakeFiles/Viterbi.dir/main.cpp.obj
Viterbi.exe: CMakeFiles/Viterbi.dir/Viterbi.cpp.obj
Viterbi.exe: CMakeFiles/Viterbi.dir/build.make
Viterbi.exe: CMakeFiles/Viterbi.dir/linklibs.rsp
Viterbi.exe: CMakeFiles/Viterbi.dir/objects1.rsp
Viterbi.exe: CMakeFiles/Viterbi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Viterbi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Viterbi.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Viterbi.dir/build: Viterbi.exe
.PHONY : CMakeFiles/Viterbi.dir/build

CMakeFiles/Viterbi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Viterbi.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Viterbi.dir/clean

CMakeFiles/Viterbi.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\cmake-build-debug" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\cmake-build-debug" "C:\Users\Orsi\Desktop\Egyetem\Graf algoritmusok\Graph\Viterbi\cmake-build-debug\CMakeFiles\Viterbi.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Viterbi.dir/depend
