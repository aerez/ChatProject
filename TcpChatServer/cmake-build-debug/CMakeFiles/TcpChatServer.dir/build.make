# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/aerez/Downloads/clion-2019.1.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/aerez/Downloads/clion-2019.1.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aerez/CLionProjects/TcpChatServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aerez/CLionProjects/TcpChatServer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TcpChatServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TcpChatServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TcpChatServer.dir/flags.make

CMakeFiles/TcpChatServer.dir/main.cpp.o: CMakeFiles/TcpChatServer.dir/flags.make
CMakeFiles/TcpChatServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aerez/CLionProjects/TcpChatServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TcpChatServer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TcpChatServer.dir/main.cpp.o -c /home/aerez/CLionProjects/TcpChatServer/main.cpp

CMakeFiles/TcpChatServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TcpChatServer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aerez/CLionProjects/TcpChatServer/main.cpp > CMakeFiles/TcpChatServer.dir/main.cpp.i

CMakeFiles/TcpChatServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TcpChatServer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aerez/CLionProjects/TcpChatServer/main.cpp -o CMakeFiles/TcpChatServer.dir/main.cpp.s

CMakeFiles/TcpChatServer.dir/TcpServer.cpp.o: CMakeFiles/TcpChatServer.dir/flags.make
CMakeFiles/TcpChatServer.dir/TcpServer.cpp.o: ../TcpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aerez/CLionProjects/TcpChatServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TcpChatServer.dir/TcpServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TcpChatServer.dir/TcpServer.cpp.o -c /home/aerez/CLionProjects/TcpChatServer/TcpServer.cpp

CMakeFiles/TcpChatServer.dir/TcpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TcpChatServer.dir/TcpServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aerez/CLionProjects/TcpChatServer/TcpServer.cpp > CMakeFiles/TcpChatServer.dir/TcpServer.cpp.i

CMakeFiles/TcpChatServer.dir/TcpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TcpChatServer.dir/TcpServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aerez/CLionProjects/TcpChatServer/TcpServer.cpp -o CMakeFiles/TcpChatServer.dir/TcpServer.cpp.s

CMakeFiles/TcpChatServer.dir/Client.cpp.o: CMakeFiles/TcpChatServer.dir/flags.make
CMakeFiles/TcpChatServer.dir/Client.cpp.o: ../Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aerez/CLionProjects/TcpChatServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TcpChatServer.dir/Client.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TcpChatServer.dir/Client.cpp.o -c /home/aerez/CLionProjects/TcpChatServer/Client.cpp

CMakeFiles/TcpChatServer.dir/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TcpChatServer.dir/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aerez/CLionProjects/TcpChatServer/Client.cpp > CMakeFiles/TcpChatServer.dir/Client.cpp.i

CMakeFiles/TcpChatServer.dir/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TcpChatServer.dir/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aerez/CLionProjects/TcpChatServer/Client.cpp -o CMakeFiles/TcpChatServer.dir/Client.cpp.s

# Object files for target TcpChatServer
TcpChatServer_OBJECTS = \
"CMakeFiles/TcpChatServer.dir/main.cpp.o" \
"CMakeFiles/TcpChatServer.dir/TcpServer.cpp.o" \
"CMakeFiles/TcpChatServer.dir/Client.cpp.o"

# External object files for target TcpChatServer
TcpChatServer_EXTERNAL_OBJECTS =

TcpChatServer: CMakeFiles/TcpChatServer.dir/main.cpp.o
TcpChatServer: CMakeFiles/TcpChatServer.dir/TcpServer.cpp.o
TcpChatServer: CMakeFiles/TcpChatServer.dir/Client.cpp.o
TcpChatServer: CMakeFiles/TcpChatServer.dir/build.make
TcpChatServer: CMakeFiles/TcpChatServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aerez/CLionProjects/TcpChatServer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable TcpChatServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TcpChatServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TcpChatServer.dir/build: TcpChatServer

.PHONY : CMakeFiles/TcpChatServer.dir/build

CMakeFiles/TcpChatServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TcpChatServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TcpChatServer.dir/clean

CMakeFiles/TcpChatServer.dir/depend:
	cd /home/aerez/CLionProjects/TcpChatServer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aerez/CLionProjects/TcpChatServer /home/aerez/CLionProjects/TcpChatServer /home/aerez/CLionProjects/TcpChatServer/cmake-build-debug /home/aerez/CLionProjects/TcpChatServer/cmake-build-debug /home/aerez/CLionProjects/TcpChatServer/cmake-build-debug/CMakeFiles/TcpChatServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TcpChatServer.dir/depend

