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
CMAKE_SOURCE_DIR = /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/build

# Include any dependencies generated for this target.
include CMakeFiles/engine.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/engine.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/engine.dir/flags.make

CMakeFiles/engine.dir/engine/engine.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/engine/engine.cpp.o: /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/engine.cpp
CMakeFiles/engine.dir/engine/engine.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m_rmarques/University/3ano/CG/Project_CG/Fase4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/engine.dir/engine/engine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/engine/engine.cpp.o -MF CMakeFiles/engine.dir/engine/engine.cpp.o.d -o CMakeFiles/engine.dir/engine/engine.cpp.o -c /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/engine.cpp

CMakeFiles/engine.dir/engine/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/engine/engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/engine.cpp > CMakeFiles/engine.dir/engine/engine.cpp.i

CMakeFiles/engine.dir/engine/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/engine/engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/engine.cpp -o CMakeFiles/engine.dir/engine/engine.cpp.s

CMakeFiles/engine.dir/engine/window.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/engine/window.cpp.o: /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/window.cpp
CMakeFiles/engine.dir/engine/window.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m_rmarques/University/3ano/CG/Project_CG/Fase4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/engine.dir/engine/window.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/engine/window.cpp.o -MF CMakeFiles/engine.dir/engine/window.cpp.o.d -o CMakeFiles/engine.dir/engine/window.cpp.o -c /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/window.cpp

CMakeFiles/engine.dir/engine/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/engine/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/window.cpp > CMakeFiles/engine.dir/engine/window.cpp.i

CMakeFiles/engine.dir/engine/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/engine/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/window.cpp -o CMakeFiles/engine.dir/engine/window.cpp.s

CMakeFiles/engine.dir/engine/camera.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/engine/camera.cpp.o: /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/camera.cpp
CMakeFiles/engine.dir/engine/camera.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m_rmarques/University/3ano/CG/Project_CG/Fase4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/engine.dir/engine/camera.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/engine/camera.cpp.o -MF CMakeFiles/engine.dir/engine/camera.cpp.o.d -o CMakeFiles/engine.dir/engine/camera.cpp.o -c /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/camera.cpp

CMakeFiles/engine.dir/engine/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/engine/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/camera.cpp > CMakeFiles/engine.dir/engine/camera.cpp.i

CMakeFiles/engine.dir/engine/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/engine/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/camera.cpp -o CMakeFiles/engine.dir/engine/camera.cpp.s

CMakeFiles/engine.dir/engine/light.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/engine/light.cpp.o: /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/light.cpp
CMakeFiles/engine.dir/engine/light.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m_rmarques/University/3ano/CG/Project_CG/Fase4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/engine.dir/engine/light.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/engine/light.cpp.o -MF CMakeFiles/engine.dir/engine/light.cpp.o.d -o CMakeFiles/engine.dir/engine/light.cpp.o -c /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/light.cpp

CMakeFiles/engine.dir/engine/light.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/engine/light.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/light.cpp > CMakeFiles/engine.dir/engine/light.cpp.i

CMakeFiles/engine.dir/engine/light.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/engine/light.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/light.cpp -o CMakeFiles/engine.dir/engine/light.cpp.s

CMakeFiles/engine.dir/engine/group.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/engine/group.cpp.o: /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/group.cpp
CMakeFiles/engine.dir/engine/group.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m_rmarques/University/3ano/CG/Project_CG/Fase4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/engine.dir/engine/group.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/engine/group.cpp.o -MF CMakeFiles/engine.dir/engine/group.cpp.o.d -o CMakeFiles/engine.dir/engine/group.cpp.o -c /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/group.cpp

CMakeFiles/engine.dir/engine/group.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/engine/group.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/group.cpp > CMakeFiles/engine.dir/engine/group.cpp.i

CMakeFiles/engine.dir/engine/group.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/engine/group.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/engine/group.cpp -o CMakeFiles/engine.dir/engine/group.cpp.s

CMakeFiles/engine.dir/utils/tinyxml2.cpp.o: CMakeFiles/engine.dir/flags.make
CMakeFiles/engine.dir/utils/tinyxml2.cpp.o: /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/utils/tinyxml2.cpp
CMakeFiles/engine.dir/utils/tinyxml2.cpp.o: CMakeFiles/engine.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/m_rmarques/University/3ano/CG/Project_CG/Fase4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/engine.dir/utils/tinyxml2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/engine.dir/utils/tinyxml2.cpp.o -MF CMakeFiles/engine.dir/utils/tinyxml2.cpp.o.d -o CMakeFiles/engine.dir/utils/tinyxml2.cpp.o -c /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/utils/tinyxml2.cpp

CMakeFiles/engine.dir/utils/tinyxml2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/utils/tinyxml2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/utils/tinyxml2.cpp > CMakeFiles/engine.dir/utils/tinyxml2.cpp.i

CMakeFiles/engine.dir/utils/tinyxml2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/utils/tinyxml2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src/utils/tinyxml2.cpp -o CMakeFiles/engine.dir/utils/tinyxml2.cpp.s

# Object files for target engine
engine_OBJECTS = \
"CMakeFiles/engine.dir/engine/engine.cpp.o" \
"CMakeFiles/engine.dir/engine/window.cpp.o" \
"CMakeFiles/engine.dir/engine/camera.cpp.o" \
"CMakeFiles/engine.dir/engine/light.cpp.o" \
"CMakeFiles/engine.dir/engine/group.cpp.o" \
"CMakeFiles/engine.dir/utils/tinyxml2.cpp.o"

# External object files for target engine
engine_EXTERNAL_OBJECTS =

engine: CMakeFiles/engine.dir/engine/engine.cpp.o
engine: CMakeFiles/engine.dir/engine/window.cpp.o
engine: CMakeFiles/engine.dir/engine/camera.cpp.o
engine: CMakeFiles/engine.dir/engine/light.cpp.o
engine: CMakeFiles/engine.dir/engine/group.cpp.o
engine: CMakeFiles/engine.dir/utils/tinyxml2.cpp.o
engine: CMakeFiles/engine.dir/build.make
engine: /usr/lib/x86_64-linux-gnu/libGLEW.so
engine: /usr/lib/x86_64-linux-gnu/libOpenGL.so
engine: /usr/lib/x86_64-linux-gnu/libGLX.so
engine: /usr/lib/x86_64-linux-gnu/libGLU.so
engine: /usr/lib/x86_64-linux-gnu/libglut.so
engine: /usr/lib/x86_64-linux-gnu/libXmu.so
engine: /usr/lib/x86_64-linux-gnu/libXi.so
engine: CMakeFiles/engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/m_rmarques/University/3ano/CG/Project_CG/Fase4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable engine"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/engine.dir/build: engine
.PHONY : CMakeFiles/engine.dir/build

CMakeFiles/engine.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean.cmake
.PHONY : CMakeFiles/engine.dir/clean

CMakeFiles/engine.dir/depend:
	cd /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/src /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/build /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/build /home/m_rmarques/University/3ano/CG/Project_CG/Fase4/build/CMakeFiles/engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/engine.dir/depend
