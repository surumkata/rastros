# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/107/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/107/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/spsc/Desktop/Projeto/Rastros/git

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/spsc/Desktop/Projeto/Rastros/git/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/LIProject.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LIProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LIProject.dir/flags.make

CMakeFiles/LIProject.dir/main.c.o: CMakeFiles/LIProject.dir/flags.make
CMakeFiles/LIProject.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spsc/Desktop/Projeto/Rastros/git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/LIProject.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LIProject.dir/main.c.o   -c /home/spsc/Desktop/Projeto/Rastros/git/main.c

CMakeFiles/LIProject.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LIProject.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/spsc/Desktop/Projeto/Rastros/git/main.c > CMakeFiles/LIProject.dir/main.c.i

CMakeFiles/LIProject.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LIProject.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/spsc/Desktop/Projeto/Rastros/git/main.c -o CMakeFiles/LIProject.dir/main.c.s

CMakeFiles/LIProject.dir/interface.c.o: CMakeFiles/LIProject.dir/flags.make
CMakeFiles/LIProject.dir/interface.c.o: ../interface.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spsc/Desktop/Projeto/Rastros/git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/LIProject.dir/interface.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LIProject.dir/interface.c.o   -c /home/spsc/Desktop/Projeto/Rastros/git/interface.c

CMakeFiles/LIProject.dir/interface.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LIProject.dir/interface.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/spsc/Desktop/Projeto/Rastros/git/interface.c > CMakeFiles/LIProject.dir/interface.c.i

CMakeFiles/LIProject.dir/interface.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LIProject.dir/interface.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/spsc/Desktop/Projeto/Rastros/git/interface.c -o CMakeFiles/LIProject.dir/interface.c.s

CMakeFiles/LIProject.dir/logica.c.o: CMakeFiles/LIProject.dir/flags.make
CMakeFiles/LIProject.dir/logica.c.o: ../logica.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spsc/Desktop/Projeto/Rastros/git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/LIProject.dir/logica.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LIProject.dir/logica.c.o   -c /home/spsc/Desktop/Projeto/Rastros/git/logica.c

CMakeFiles/LIProject.dir/logica.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LIProject.dir/logica.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/spsc/Desktop/Projeto/Rastros/git/logica.c > CMakeFiles/LIProject.dir/logica.c.i

CMakeFiles/LIProject.dir/logica.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LIProject.dir/logica.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/spsc/Desktop/Projeto/Rastros/git/logica.c -o CMakeFiles/LIProject.dir/logica.c.s

CMakeFiles/LIProject.dir/dados.c.o: CMakeFiles/LIProject.dir/flags.make
CMakeFiles/LIProject.dir/dados.c.o: ../dados.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spsc/Desktop/Projeto/Rastros/git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/LIProject.dir/dados.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LIProject.dir/dados.c.o   -c /home/spsc/Desktop/Projeto/Rastros/git/dados.c

CMakeFiles/LIProject.dir/dados.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LIProject.dir/dados.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/spsc/Desktop/Projeto/Rastros/git/dados.c > CMakeFiles/LIProject.dir/dados.c.i

CMakeFiles/LIProject.dir/dados.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LIProject.dir/dados.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/spsc/Desktop/Projeto/Rastros/git/dados.c -o CMakeFiles/LIProject.dir/dados.c.s

CMakeFiles/LIProject.dir/listas.c.o: CMakeFiles/LIProject.dir/flags.make
CMakeFiles/LIProject.dir/listas.c.o: ../listas.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/spsc/Desktop/Projeto/Rastros/git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/LIProject.dir/listas.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/LIProject.dir/listas.c.o   -c /home/spsc/Desktop/Projeto/Rastros/git/listas.c

CMakeFiles/LIProject.dir/listas.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/LIProject.dir/listas.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/spsc/Desktop/Projeto/Rastros/git/listas.c > CMakeFiles/LIProject.dir/listas.c.i

CMakeFiles/LIProject.dir/listas.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/LIProject.dir/listas.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/spsc/Desktop/Projeto/Rastros/git/listas.c -o CMakeFiles/LIProject.dir/listas.c.s

# Object files for target LIProject
LIProject_OBJECTS = \
"CMakeFiles/LIProject.dir/main.c.o" \
"CMakeFiles/LIProject.dir/interface.c.o" \
"CMakeFiles/LIProject.dir/logica.c.o" \
"CMakeFiles/LIProject.dir/dados.c.o" \
"CMakeFiles/LIProject.dir/listas.c.o"

# External object files for target LIProject
LIProject_EXTERNAL_OBJECTS =

LIProject: CMakeFiles/LIProject.dir/main.c.o
LIProject: CMakeFiles/LIProject.dir/interface.c.o
LIProject: CMakeFiles/LIProject.dir/logica.c.o
LIProject: CMakeFiles/LIProject.dir/dados.c.o
LIProject: CMakeFiles/LIProject.dir/listas.c.o
LIProject: CMakeFiles/LIProject.dir/build.make
LIProject: CMakeFiles/LIProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/spsc/Desktop/Projeto/Rastros/git/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable LIProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LIProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LIProject.dir/build: LIProject

.PHONY : CMakeFiles/LIProject.dir/build

CMakeFiles/LIProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LIProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LIProject.dir/clean

CMakeFiles/LIProject.dir/depend:
	cd /home/spsc/Desktop/Projeto/Rastros/git/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/spsc/Desktop/Projeto/Rastros/git /home/spsc/Desktop/Projeto/Rastros/git /home/spsc/Desktop/Projeto/Rastros/git/cmake-build-debug /home/spsc/Desktop/Projeto/Rastros/git/cmake-build-debug /home/spsc/Desktop/Projeto/Rastros/git/cmake-build-debug/CMakeFiles/LIProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/LIProject.dir/depend

