# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/m_rmarques/University/3ano/Project_CG/Fase2/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/m_rmarques/University/3ano/Project_CG/Fase2/build

# Include any dependencies generated for this target.
include CMakeFiles/engine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/engine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/engine.dir/flags.make

CMakeFiles/engine.dir/engine.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/engine.cpp.o: /home/m_rmarques/University/3ano/Project_CG/Fase2/src/engine.cpp
CMakeFiles/engine.dir/engine.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m_rmarques/University/3ano/Project_CG/Fase2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/engine.dir/engine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/engine.cpp.o -MF CMakeFiles/engine.dir/engine.cpp.o.d -o CMakeFiles/engine.dir/engine.cpp.o -c /home/m_rmarques/University/3ano/Project_CG/Fase2/src/engine.cpp

CMakeFiles/engine.dir/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m_rmarques/University/3ano/Project_CG/Fase2/src/engine.cpp > CMakeFiles/engine.dir/engine.cpp.i

CMakeFiles/engine.dir/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m_rmarques/University/3ano/Project_CG/Fase2/src/engine.cpp -o CMakeFiles/engine.dir/engine.cpp.s

CMakeFiles/engine.dir/tags.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/tags.cpp.o: /home/m_rmarques/University/3ano/Project_CG/Fase2/src/tags.cpp
CMakeFiles/engine.dir/tags.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m_rmarques/University/3ano/Project_CG/Fase2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/engine.dir/tags.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/tags.cpp.o -MF CMakeFiles/engine.dir/tags.cpp.o.d -o CMakeFiles/engine.dir/tags.cpp.o -c /home/m_rmarques/University/3ano/Project_CG/Fase2/src/tags.cpp

CMakeFiles/engine.dir/tags.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/tags.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m_rmarques/University/3ano/Project_CG/Fase2/src/tags.cpp > CMakeFiles/engine.dir/tags.cpp.i

CMakeFiles/engine.dir/tags.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/tags.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m_rmarques/University/3ano/Project_CG/Fase2/src/tags.cpp -o CMakeFiles/engine.dir/tags.cpp.s

CMakeFiles/engine.dir/tinyxml2.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/tinyxml2.cpp.o: /home/m_rmarques/University/3ano/Project_CG/Fase2/src/tinyxml2.cpp
CMakeFiles/engine.dir/tinyxml2.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m_rmarques/University/3ano/Project_CG/Fase2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/engine.dir/tinyxml2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/tinyxml2.cpp.o -MF CMakeFiles/engine.dir/tinyxml2.cpp.o.d -o CMakeFiles/engine.dir/tinyxml2.cpp.o -c /home/m_rmarques/University/3ano/Project_CG/Fase2/src/tinyxml2.cpp

CMakeFiles/engine.dir/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/tinyxml2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m_rmarques/University/3ano/Project_CG/Fase2/src/tinyxml2.cpp > CMakeFiles/engine.dir/tinyxml2.cpp.i

CMakeFiles/engine.dir/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/tinyxml2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m_rmarques/University/3ano/Project_CG/Fase2/src/tinyxml2.cpp -o CMakeFiles/engine.dir/tinyxml2.cpp.s

# Object files for target engine
engine_OBJECTS = \
"CMakeFiles/engine.dir/engine.cpp.o" \
"CMakeFiles/engine.dir/tags.cpp.o" \
"CMakeFiles/engine.dir/tinyxml2.cpp.o"

# External object files for target engine
engine_EXTERNAL_OBJECTS =

engine: CMakeFiles/engine.dir/engine.cpp.o
engine: CMakeFiles/engine.dir/tags.cpp.o
engine: CMakeFiles/engine.dir/tinyxml2.cpp.o
engine: CMakeFiles/engine.dir/build.make
engine: /usr/lib/x86_64-linux-gnu/libOpenGL.so
engine: /usr/lib/x86_64-linux-gnu/libGLX.so
engine: /usr/lib/x86_64-linux-gnu/libGLU.so
engine: /usr/lib/x86_64-linux-gnu/libglut.so
engine: /usr/lib/x86_64-linux-gnu/libXmu.so
engine: /usr/lib/x86_64-linux-gnu/libXi.so
engine: CMakeFiles/engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/m_rmarques/University/3ano/Project_CG/Fase2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/engine.dir/build: engine
.PHONY : CMakeFiles/engine.dir/build

CMakeFiles/engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/engine.dir/clean

CMakeFiles/engine.dir/depend:
	cd /home/m_rmarques/University/3ano/Project_CG/Fase2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/m_rmarques/University/3ano/Project_CG/Fase2/src /home/m_rmarques/University/3ano/Project_CG/Fase2/src /home/m_rmarques/University/3ano/Project_CG/Fase2/build /home/m_rmarques/University/3ano/Project_CG/Fase2/build /home/m_rmarques/University/3ano/Project_CG/Fase2/build/CMakeFiles/engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/engine.dir/depend

