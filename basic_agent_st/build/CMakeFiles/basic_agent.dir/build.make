# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build"

# Include any dependencies generated for this target.
include CMakeFiles/basic_agent.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/basic_agent.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/basic_agent.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/basic_agent.dir/flags.make

CMakeFiles/basic_agent.dir/primitives/primitives.c.o: CMakeFiles/basic_agent.dir/flags.make
CMakeFiles/basic_agent.dir/primitives/primitives.c.o: ../primitives/primitives.c
CMakeFiles/basic_agent.dir/primitives/primitives.c.o: CMakeFiles/basic_agent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/basic_agent.dir/primitives/primitives.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/basic_agent.dir/primitives/primitives.c.o -MF CMakeFiles/basic_agent.dir/primitives/primitives.c.o.d -o CMakeFiles/basic_agent.dir/primitives/primitives.c.o -c "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/primitives/primitives.c"

CMakeFiles/basic_agent.dir/primitives/primitives.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/basic_agent.dir/primitives/primitives.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/primitives/primitives.c" > CMakeFiles/basic_agent.dir/primitives/primitives.c.i

CMakeFiles/basic_agent.dir/primitives/primitives.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/basic_agent.dir/primitives/primitives.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/primitives/primitives.c" -o CMakeFiles/basic_agent.dir/primitives/primitives.c.s

CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.o: CMakeFiles/basic_agent.dir/flags.make
CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.o: ../primitives/rtGetNaN.c
CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.o: CMakeFiles/basic_agent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.o -MF CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.o.d -o CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.o -c "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/primitives/rtGetNaN.c"

CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/primitives/rtGetNaN.c" > CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.i

CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/primitives/rtGetNaN.c" -o CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.s

CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.o: CMakeFiles/basic_agent.dir/flags.make
CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.o: ../primitives/rtGetInf.c
CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.o: CMakeFiles/basic_agent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.o -MF CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.o.d -o CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.o -c "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/primitives/rtGetInf.c"

CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/primitives/rtGetInf.c" > CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.i

CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/primitives/rtGetInf.c" -o CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.s

CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.o: CMakeFiles/basic_agent.dir/flags.make
CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.o: ../primitives/rt_nonfinite.c
CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.o: CMakeFiles/basic_agent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.o -MF CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.o.d -o CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.o -c "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/primitives/rt_nonfinite.c"

CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/primitives/rt_nonfinite.c" > CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.i

CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/primitives/rt_nonfinite.c" -o CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.s

CMakeFiles/basic_agent.dir/log/screen_print.c.o: CMakeFiles/basic_agent.dir/flags.make
CMakeFiles/basic_agent.dir/log/screen_print.c.o: ../log/screen_print.c
CMakeFiles/basic_agent.dir/log/screen_print.c.o: CMakeFiles/basic_agent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/basic_agent.dir/log/screen_print.c.o"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/basic_agent.dir/log/screen_print.c.o -MF CMakeFiles/basic_agent.dir/log/screen_print.c.o.d -o CMakeFiles/basic_agent.dir/log/screen_print.c.o -c "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/log/screen_print.c"

CMakeFiles/basic_agent.dir/log/screen_print.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/basic_agent.dir/log/screen_print.c.i"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/log/screen_print.c" > CMakeFiles/basic_agent.dir/log/screen_print.c.i

CMakeFiles/basic_agent.dir/log/screen_print.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/basic_agent.dir/log/screen_print.c.s"
	/usr/bin/clang $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/log/screen_print.c" -o CMakeFiles/basic_agent.dir/log/screen_print.c.s

CMakeFiles/basic_agent.dir/log/logvars.cc.o: CMakeFiles/basic_agent.dir/flags.make
CMakeFiles/basic_agent.dir/log/logvars.cc.o: ../log/logvars.cc
CMakeFiles/basic_agent.dir/log/logvars.cc.o: CMakeFiles/basic_agent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/basic_agent.dir/log/logvars.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_agent.dir/log/logvars.cc.o -MF CMakeFiles/basic_agent.dir/log/logvars.cc.o.d -o CMakeFiles/basic_agent.dir/log/logvars.cc.o -c "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/log/logvars.cc"

CMakeFiles/basic_agent.dir/log/logvars.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_agent.dir/log/logvars.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/log/logvars.cc" > CMakeFiles/basic_agent.dir/log/logvars.cc.i

CMakeFiles/basic_agent.dir/log/logvars.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_agent.dir/log/logvars.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/log/logvars.cc" -o CMakeFiles/basic_agent.dir/log/logvars.cc.s

CMakeFiles/basic_agent.dir/starting_point.cc.o: CMakeFiles/basic_agent.dir/flags.make
CMakeFiles/basic_agent.dir/starting_point.cc.o: ../starting_point.cc
CMakeFiles/basic_agent.dir/starting_point.cc.o: CMakeFiles/basic_agent.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/basic_agent.dir/starting_point.cc.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/basic_agent.dir/starting_point.cc.o -MF CMakeFiles/basic_agent.dir/starting_point.cc.o.d -o CMakeFiles/basic_agent.dir/starting_point.cc.o -c "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/starting_point.cc"

CMakeFiles/basic_agent.dir/starting_point.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/basic_agent.dir/starting_point.cc.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/starting_point.cc" > CMakeFiles/basic_agent.dir/starting_point.cc.i

CMakeFiles/basic_agent.dir/starting_point.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/basic_agent.dir/starting_point.cc.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/starting_point.cc" -o CMakeFiles/basic_agent.dir/starting_point.cc.s

# Object files for target basic_agent
basic_agent_OBJECTS = \
"CMakeFiles/basic_agent.dir/primitives/primitives.c.o" \
"CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.o" \
"CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.o" \
"CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.o" \
"CMakeFiles/basic_agent.dir/log/screen_print.c.o" \
"CMakeFiles/basic_agent.dir/log/logvars.cc.o" \
"CMakeFiles/basic_agent.dir/starting_point.cc.o"

# External object files for target basic_agent
basic_agent_EXTERNAL_OBJECTS =

../bin/basic_agent: CMakeFiles/basic_agent.dir/primitives/primitives.c.o
../bin/basic_agent: CMakeFiles/basic_agent.dir/primitives/rtGetNaN.c.o
../bin/basic_agent: CMakeFiles/basic_agent.dir/primitives/rtGetInf.c.o
../bin/basic_agent: CMakeFiles/basic_agent.dir/primitives/rt_nonfinite.c.o
../bin/basic_agent: CMakeFiles/basic_agent.dir/log/screen_print.c.o
../bin/basic_agent: CMakeFiles/basic_agent.dir/log/logvars.cc.o
../bin/basic_agent: CMakeFiles/basic_agent.dir/starting_point.cc.o
../bin/basic_agent: CMakeFiles/basic_agent.dir/build.make
../bin/basic_agent: CMakeFiles/basic_agent.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../bin/basic_agent"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/basic_agent.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/basic_agent.dir/build: ../bin/basic_agent
.PHONY : CMakeFiles/basic_agent.dir/build

CMakeFiles/basic_agent.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/basic_agent.dir/cmake_clean.cmake
.PHONY : CMakeFiles/basic_agent.dir/clean

CMakeFiles/basic_agent.dir/depend:
	cd "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st" "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st" "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build" "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build" "/home/matteo/Documenti/Intelligent vehicles/Project/basic_agent_st/build/CMakeFiles/basic_agent.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/basic_agent.dir/depend

