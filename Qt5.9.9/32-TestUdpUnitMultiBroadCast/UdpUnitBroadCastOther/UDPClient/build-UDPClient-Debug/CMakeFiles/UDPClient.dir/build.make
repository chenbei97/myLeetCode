# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = C:\cmake-3.23.2-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = C:\cmake-3.23.2-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\build-UDPClient-Debug

# Include any dependencies generated for this target.
include CMakeFiles/UDPClient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/UDPClient.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/UDPClient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UDPClient.dir/flags.make

CMakeFiles/UDPClient.dir/UDPClient_autogen/mocs_compilation.cpp.obj: CMakeFiles/UDPClient.dir/flags.make
CMakeFiles/UDPClient.dir/UDPClient_autogen/mocs_compilation.cpp.obj: CMakeFiles/UDPClient.dir/includes_CXX.rsp
CMakeFiles/UDPClient.dir/UDPClient_autogen/mocs_compilation.cpp.obj: UDPClient_autogen/mocs_compilation.cpp
CMakeFiles/UDPClient.dir/UDPClient_autogen/mocs_compilation.cpp.obj: CMakeFiles/UDPClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\build-UDPClient-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UDPClient.dir/UDPClient_autogen/mocs_compilation.cpp.obj"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/UDPClient.dir/UDPClient_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\UDPClient.dir\UDPClient_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\UDPClient.dir\UDPClient_autogen\mocs_compilation.cpp.obj -c C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\build-UDPClient-Debug\UDPClient_autogen\mocs_compilation.cpp

CMakeFiles/UDPClient.dir/UDPClient_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDPClient.dir/UDPClient_autogen/mocs_compilation.cpp.i"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\build-UDPClient-Debug\UDPClient_autogen\mocs_compilation.cpp > CMakeFiles\UDPClient.dir\UDPClient_autogen\mocs_compilation.cpp.i

CMakeFiles/UDPClient.dir/UDPClient_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDPClient.dir/UDPClient_autogen/mocs_compilation.cpp.s"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\build-UDPClient-Debug\UDPClient_autogen\mocs_compilation.cpp -o CMakeFiles\UDPClient.dir\UDPClient_autogen\mocs_compilation.cpp.s

CMakeFiles/UDPClient.dir/main.cpp.obj: CMakeFiles/UDPClient.dir/flags.make
CMakeFiles/UDPClient.dir/main.cpp.obj: CMakeFiles/UDPClient.dir/includes_CXX.rsp
CMakeFiles/UDPClient.dir/main.cpp.obj: ../main.cpp
CMakeFiles/UDPClient.dir/main.cpp.obj: CMakeFiles/UDPClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\build-UDPClient-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/UDPClient.dir/main.cpp.obj"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/UDPClient.dir/main.cpp.obj -MF CMakeFiles\UDPClient.dir\main.cpp.obj.d -o CMakeFiles\UDPClient.dir\main.cpp.obj -c C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\main.cpp

CMakeFiles/UDPClient.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDPClient.dir/main.cpp.i"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\main.cpp > CMakeFiles\UDPClient.dir\main.cpp.i

CMakeFiles/UDPClient.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDPClient.dir/main.cpp.s"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\main.cpp -o CMakeFiles\UDPClient.dir\main.cpp.s

CMakeFiles/UDPClient.dir/UDPClient.cpp.obj: CMakeFiles/UDPClient.dir/flags.make
CMakeFiles/UDPClient.dir/UDPClient.cpp.obj: CMakeFiles/UDPClient.dir/includes_CXX.rsp
CMakeFiles/UDPClient.dir/UDPClient.cpp.obj: ../UDPClient.cpp
CMakeFiles/UDPClient.dir/UDPClient.cpp.obj: CMakeFiles/UDPClient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\build-UDPClient-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/UDPClient.dir/UDPClient.cpp.obj"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/UDPClient.dir/UDPClient.cpp.obj -MF CMakeFiles\UDPClient.dir\UDPClient.cpp.obj.d -o CMakeFiles\UDPClient.dir\UDPClient.cpp.obj -c C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\UDPClient.cpp

CMakeFiles/UDPClient.dir/UDPClient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDPClient.dir/UDPClient.cpp.i"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\UDPClient.cpp > CMakeFiles\UDPClient.dir\UDPClient.cpp.i

CMakeFiles/UDPClient.dir/UDPClient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDPClient.dir/UDPClient.cpp.s"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\UDPClient.cpp -o CMakeFiles\UDPClient.dir\UDPClient.cpp.s

# Object files for target UDPClient
UDPClient_OBJECTS = \
"CMakeFiles/UDPClient.dir/UDPClient_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/UDPClient.dir/main.cpp.obj" \
"CMakeFiles/UDPClient.dir/UDPClient.cpp.obj"

# External object files for target UDPClient
UDPClient_EXTERNAL_OBJECTS =

UDPClient.exe: CMakeFiles/UDPClient.dir/UDPClient_autogen/mocs_compilation.cpp.obj
UDPClient.exe: CMakeFiles/UDPClient.dir/main.cpp.obj
UDPClient.exe: CMakeFiles/UDPClient.dir/UDPClient.cpp.obj
UDPClient.exe: CMakeFiles/UDPClient.dir/build.make
UDPClient.exe: C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib/libQt5Widgetsd.a
UDPClient.exe: C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib/libQt5Networkd.a
UDPClient.exe: C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib/libQt5Guid.a
UDPClient.exe: C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib/libQt5Cored.a
UDPClient.exe: CMakeFiles/UDPClient.dir/linklibs.rsp
UDPClient.exe: CMakeFiles/UDPClient.dir/objects1.rsp
UDPClient.exe: CMakeFiles/UDPClient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\build-UDPClient-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable UDPClient.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\UDPClient.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UDPClient.dir/build: UDPClient.exe
.PHONY : CMakeFiles/UDPClient.dir/build

CMakeFiles/UDPClient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\UDPClient.dir\cmake_clean.cmake
.PHONY : CMakeFiles/UDPClient.dir/clean

CMakeFiles/UDPClient.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\build-UDPClient-Debug C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\build-UDPClient-Debug C:\Users\chenb\Documents\qt\UdpUnitBroadCastOther\UDPClient\build-UDPClient-Debug\CMakeFiles\UDPClient.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UDPClient.dir/depend
