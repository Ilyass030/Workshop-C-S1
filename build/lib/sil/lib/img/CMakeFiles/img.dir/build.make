# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/remmane/PROG/workshop/Workshop-C-S1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/remmane/PROG/workshop/Workshop-C-S1/build

# Include any dependencies generated for this target.
include lib/sil/lib/img/CMakeFiles/img.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/sil/lib/img/CMakeFiles/img.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/sil/lib/img/CMakeFiles/img.dir/progress.make

# Include the compile flags for this target's objects.
include lib/sil/lib/img/CMakeFiles/img.dir/flags.make

lib/sil/lib/img/CMakeFiles/img.dir/src/Load.cpp.o: lib/sil/lib/img/CMakeFiles/img.dir/flags.make
lib/sil/lib/img/CMakeFiles/img.dir/src/Load.cpp.o: /Users/remmane/PROG/workshop/Workshop-C-S1/lib/sil/lib/img/src/Load.cpp
lib/sil/lib/img/CMakeFiles/img.dir/src/Load.cpp.o: lib/sil/lib/img/CMakeFiles/img.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/remmane/PROG/workshop/Workshop-C-S1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/sil/lib/img/CMakeFiles/img.dir/src/Load.cpp.o"
	cd /Users/remmane/PROG/workshop/Workshop-C-S1/build/lib/sil/lib/img && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/sil/lib/img/CMakeFiles/img.dir/src/Load.cpp.o -MF CMakeFiles/img.dir/src/Load.cpp.o.d -o CMakeFiles/img.dir/src/Load.cpp.o -c /Users/remmane/PROG/workshop/Workshop-C-S1/lib/sil/lib/img/src/Load.cpp

lib/sil/lib/img/CMakeFiles/img.dir/src/Load.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/img.dir/src/Load.cpp.i"
	cd /Users/remmane/PROG/workshop/Workshop-C-S1/build/lib/sil/lib/img && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/remmane/PROG/workshop/Workshop-C-S1/lib/sil/lib/img/src/Load.cpp > CMakeFiles/img.dir/src/Load.cpp.i

lib/sil/lib/img/CMakeFiles/img.dir/src/Load.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/img.dir/src/Load.cpp.s"
	cd /Users/remmane/PROG/workshop/Workshop-C-S1/build/lib/sil/lib/img && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/remmane/PROG/workshop/Workshop-C-S1/lib/sil/lib/img/src/Load.cpp -o CMakeFiles/img.dir/src/Load.cpp.s

lib/sil/lib/img/CMakeFiles/img.dir/src/Save.cpp.o: lib/sil/lib/img/CMakeFiles/img.dir/flags.make
lib/sil/lib/img/CMakeFiles/img.dir/src/Save.cpp.o: /Users/remmane/PROG/workshop/Workshop-C-S1/lib/sil/lib/img/src/Save.cpp
lib/sil/lib/img/CMakeFiles/img.dir/src/Save.cpp.o: lib/sil/lib/img/CMakeFiles/img.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/remmane/PROG/workshop/Workshop-C-S1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/sil/lib/img/CMakeFiles/img.dir/src/Save.cpp.o"
	cd /Users/remmane/PROG/workshop/Workshop-C-S1/build/lib/sil/lib/img && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/sil/lib/img/CMakeFiles/img.dir/src/Save.cpp.o -MF CMakeFiles/img.dir/src/Save.cpp.o.d -o CMakeFiles/img.dir/src/Save.cpp.o -c /Users/remmane/PROG/workshop/Workshop-C-S1/lib/sil/lib/img/src/Save.cpp

lib/sil/lib/img/CMakeFiles/img.dir/src/Save.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/img.dir/src/Save.cpp.i"
	cd /Users/remmane/PROG/workshop/Workshop-C-S1/build/lib/sil/lib/img && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/remmane/PROG/workshop/Workshop-C-S1/lib/sil/lib/img/src/Save.cpp > CMakeFiles/img.dir/src/Save.cpp.i

lib/sil/lib/img/CMakeFiles/img.dir/src/Save.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/img.dir/src/Save.cpp.s"
	cd /Users/remmane/PROG/workshop/Workshop-C-S1/build/lib/sil/lib/img && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/remmane/PROG/workshop/Workshop-C-S1/lib/sil/lib/img/src/Save.cpp -o CMakeFiles/img.dir/src/Save.cpp.s

# Object files for target img
img_OBJECTS = \
"CMakeFiles/img.dir/src/Load.cpp.o" \
"CMakeFiles/img.dir/src/Save.cpp.o"

# External object files for target img
img_EXTERNAL_OBJECTS =

lib/sil/lib/img/libimg.a: lib/sil/lib/img/CMakeFiles/img.dir/src/Load.cpp.o
lib/sil/lib/img/libimg.a: lib/sil/lib/img/CMakeFiles/img.dir/src/Save.cpp.o
lib/sil/lib/img/libimg.a: lib/sil/lib/img/CMakeFiles/img.dir/build.make
lib/sil/lib/img/libimg.a: lib/sil/lib/img/CMakeFiles/img.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/remmane/PROG/workshop/Workshop-C-S1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libimg.a"
	cd /Users/remmane/PROG/workshop/Workshop-C-S1/build/lib/sil/lib/img && $(CMAKE_COMMAND) -P CMakeFiles/img.dir/cmake_clean_target.cmake
	cd /Users/remmane/PROG/workshop/Workshop-C-S1/build/lib/sil/lib/img && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/img.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/sil/lib/img/CMakeFiles/img.dir/build: lib/sil/lib/img/libimg.a
.PHONY : lib/sil/lib/img/CMakeFiles/img.dir/build

lib/sil/lib/img/CMakeFiles/img.dir/clean:
	cd /Users/remmane/PROG/workshop/Workshop-C-S1/build/lib/sil/lib/img && $(CMAKE_COMMAND) -P CMakeFiles/img.dir/cmake_clean.cmake
.PHONY : lib/sil/lib/img/CMakeFiles/img.dir/clean

lib/sil/lib/img/CMakeFiles/img.dir/depend:
	cd /Users/remmane/PROG/workshop/Workshop-C-S1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/remmane/PROG/workshop/Workshop-C-S1 /Users/remmane/PROG/workshop/Workshop-C-S1/lib/sil/lib/img /Users/remmane/PROG/workshop/Workshop-C-S1/build /Users/remmane/PROG/workshop/Workshop-C-S1/build/lib/sil/lib/img /Users/remmane/PROG/workshop/Workshop-C-S1/build/lib/sil/lib/img/CMakeFiles/img.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/sil/lib/img/CMakeFiles/img.dir/depend

