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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion1 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion1 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Dima\CLionProjects\LabaAll

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Dima\CLionProjects\LabaAll\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LabaAll.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LabaAll.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LabaAll.dir/flags.make

CMakeFiles/LabaAll.dir/main.cpp.obj: CMakeFiles/LabaAll.dir/flags.make
CMakeFiles/LabaAll.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Dima\CLionProjects\LabaAll\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LabaAll.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\LabaAll.dir\main.cpp.obj -c C:\Users\Dima\CLionProjects\LabaAll\main.cpp

CMakeFiles/LabaAll.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LabaAll.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Dima\CLionProjects\LabaAll\main.cpp > CMakeFiles\LabaAll.dir\main.cpp.i

CMakeFiles/LabaAll.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LabaAll.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Dima\CLionProjects\LabaAll\main.cpp -o CMakeFiles\LabaAll.dir\main.cpp.s

# Object files for target LabaAll
LabaAll_OBJECTS = \
"CMakeFiles/LabaAll.dir/main.cpp.obj"

# External object files for target LabaAll
LabaAll_EXTERNAL_OBJECTS =

LabaAll.exe: CMakeFiles/LabaAll.dir/main.cpp.obj
LabaAll.exe: CMakeFiles/LabaAll.dir/build.make
LabaAll.exe: CMakeFiles/LabaAll.dir/linklibs.rsp
LabaAll.exe: CMakeFiles/LabaAll.dir/objects1.rsp
LabaAll.exe: CMakeFiles/LabaAll.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Dima\CLionProjects\LabaAll\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable LabaAll.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\LabaAll.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LabaAll.dir/build: LabaAll.exe

.PHONY : CMakeFiles/LabaAll.dir/build

CMakeFiles/LabaAll.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\LabaAll.dir\cmake_clean.cmake
.PHONY : CMakeFiles/LabaAll.dir/clean

CMakeFiles/LabaAll.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Dima\CLionProjects\LabaAll C:\Users\Dima\CLionProjects\LabaAll C:\Users\Dima\CLionProjects\LabaAll\cmake-build-debug C:\Users\Dima\CLionProjects\LabaAll\cmake-build-debug C:\Users\Dima\CLionProjects\LabaAll\cmake-build-debug\CMakeFiles\LabaAll.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LabaAll.dir/depend
