# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rezbanandrei/documents/IEP2020/lucrarea5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rezbanandrei/documents/IEP2020/lucrarea5/build

# Include any dependencies generated for this target.
include library/CMakeFiles/operations.dir/depend.make

# Include the progress variables for this target.
include library/CMakeFiles/operations.dir/progress.make

# Include the compile flags for this target's objects.
include library/CMakeFiles/operations.dir/flags.make

library/CMakeFiles/operations.dir/operations/operations.cpp.o: library/CMakeFiles/operations.dir/flags.make
library/CMakeFiles/operations.dir/operations/operations.cpp.o: ../library/operations/operations.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rezbanandrei/documents/IEP2020/lucrarea5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object library/CMakeFiles/operations.dir/operations/operations.cpp.o"
	cd /Users/rezbanandrei/documents/IEP2020/lucrarea5/build/library && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/operations.dir/operations/operations.cpp.o -c /Users/rezbanandrei/documents/IEP2020/lucrarea5/library/operations/operations.cpp

library/CMakeFiles/operations.dir/operations/operations.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/operations.dir/operations/operations.cpp.i"
	cd /Users/rezbanandrei/documents/IEP2020/lucrarea5/build/library && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rezbanandrei/documents/IEP2020/lucrarea5/library/operations/operations.cpp > CMakeFiles/operations.dir/operations/operations.cpp.i

library/CMakeFiles/operations.dir/operations/operations.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/operations.dir/operations/operations.cpp.s"
	cd /Users/rezbanandrei/documents/IEP2020/lucrarea5/build/library && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rezbanandrei/documents/IEP2020/lucrarea5/library/operations/operations.cpp -o CMakeFiles/operations.dir/operations/operations.cpp.s

# Object files for target operations
operations_OBJECTS = \
"CMakeFiles/operations.dir/operations/operations.cpp.o"

# External object files for target operations
operations_EXTERNAL_OBJECTS =

library/liboperations.a: library/CMakeFiles/operations.dir/operations/operations.cpp.o
library/liboperations.a: library/CMakeFiles/operations.dir/build.make
library/liboperations.a: library/CMakeFiles/operations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rezbanandrei/documents/IEP2020/lucrarea5/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liboperations.a"
	cd /Users/rezbanandrei/documents/IEP2020/lucrarea5/build/library && $(CMAKE_COMMAND) -P CMakeFiles/operations.dir/cmake_clean_target.cmake
	cd /Users/rezbanandrei/documents/IEP2020/lucrarea5/build/library && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/operations.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
library/CMakeFiles/operations.dir/build: library/liboperations.a

.PHONY : library/CMakeFiles/operations.dir/build

library/CMakeFiles/operations.dir/clean:
	cd /Users/rezbanandrei/documents/IEP2020/lucrarea5/build/library && $(CMAKE_COMMAND) -P CMakeFiles/operations.dir/cmake_clean.cmake
.PHONY : library/CMakeFiles/operations.dir/clean

library/CMakeFiles/operations.dir/depend:
	cd /Users/rezbanandrei/documents/IEP2020/lucrarea5/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rezbanandrei/documents/IEP2020/lucrarea5 /Users/rezbanandrei/documents/IEP2020/lucrarea5/library /Users/rezbanandrei/documents/IEP2020/lucrarea5/build /Users/rezbanandrei/documents/IEP2020/lucrarea5/build/library /Users/rezbanandrei/documents/IEP2020/lucrarea5/build/library/CMakeFiles/operations.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : library/CMakeFiles/operations.dir/depend

