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
CMAKE_SOURCE_DIR = C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug

# Include any dependencies generated for this target.
include CMakeFiles/TCPServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TCPServer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TCPServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TCPServer.dir/flags.make

CMakeFiles/TCPServer.dir/TCPServer_autogen/mocs_compilation.cpp.obj: CMakeFiles/TCPServer.dir/flags.make
CMakeFiles/TCPServer.dir/TCPServer_autogen/mocs_compilation.cpp.obj: CMakeFiles/TCPServer.dir/includes_CXX.rsp
CMakeFiles/TCPServer.dir/TCPServer_autogen/mocs_compilation.cpp.obj: TCPServer_autogen/mocs_compilation.cpp
CMakeFiles/TCPServer.dir/TCPServer_autogen/mocs_compilation.cpp.obj: CMakeFiles/TCPServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TCPServer.dir/TCPServer_autogen/mocs_compilation.cpp.obj"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TCPServer.dir/TCPServer_autogen/mocs_compilation.cpp.obj -MF CMakeFiles\TCPServer.dir\TCPServer_autogen\mocs_compilation.cpp.obj.d -o CMakeFiles\TCPServer.dir\TCPServer_autogen\mocs_compilation.cpp.obj -c C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug\TCPServer_autogen\mocs_compilation.cpp

CMakeFiles/TCPServer.dir/TCPServer_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPServer.dir/TCPServer_autogen/mocs_compilation.cpp.i"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug\TCPServer_autogen\mocs_compilation.cpp > CMakeFiles\TCPServer.dir\TCPServer_autogen\mocs_compilation.cpp.i

CMakeFiles/TCPServer.dir/TCPServer_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPServer.dir/TCPServer_autogen/mocs_compilation.cpp.s"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug\TCPServer_autogen\mocs_compilation.cpp -o CMakeFiles\TCPServer.dir\TCPServer_autogen\mocs_compilation.cpp.s

CMakeFiles/TCPServer.dir/main.cpp.obj: CMakeFiles/TCPServer.dir/flags.make
CMakeFiles/TCPServer.dir/main.cpp.obj: CMakeFiles/TCPServer.dir/includes_CXX.rsp
CMakeFiles/TCPServer.dir/main.cpp.obj: ../main.cpp
CMakeFiles/TCPServer.dir/main.cpp.obj: CMakeFiles/TCPServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TCPServer.dir/main.cpp.obj"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TCPServer.dir/main.cpp.obj -MF CMakeFiles\TCPServer.dir\main.cpp.obj.d -o CMakeFiles\TCPServer.dir\main.cpp.obj -c C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\main.cpp

CMakeFiles/TCPServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPServer.dir/main.cpp.i"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\main.cpp > CMakeFiles\TCPServer.dir\main.cpp.i

CMakeFiles/TCPServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPServer.dir/main.cpp.s"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\main.cpp -o CMakeFiles\TCPServer.dir\main.cpp.s

CMakeFiles/TCPServer.dir/TCPServer.cpp.obj: CMakeFiles/TCPServer.dir/flags.make
CMakeFiles/TCPServer.dir/TCPServer.cpp.obj: CMakeFiles/TCPServer.dir/includes_CXX.rsp
CMakeFiles/TCPServer.dir/TCPServer.cpp.obj: ../TCPServer.cpp
CMakeFiles/TCPServer.dir/TCPServer.cpp.obj: CMakeFiles/TCPServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TCPServer.dir/TCPServer.cpp.obj"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TCPServer.dir/TCPServer.cpp.obj -MF CMakeFiles\TCPServer.dir\TCPServer.cpp.obj.d -o CMakeFiles\TCPServer.dir\TCPServer.cpp.obj -c C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\TCPServer.cpp

CMakeFiles/TCPServer.dir/TCPServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPServer.dir/TCPServer.cpp.i"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\TCPServer.cpp > CMakeFiles\TCPServer.dir\TCPServer.cpp.i

CMakeFiles/TCPServer.dir/TCPServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPServer.dir/TCPServer.cpp.s"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\TCPServer.cpp -o CMakeFiles\TCPServer.dir\TCPServer.cpp.s

CMakeFiles/TCPServer.dir/mSocket.cpp.obj: CMakeFiles/TCPServer.dir/flags.make
CMakeFiles/TCPServer.dir/mSocket.cpp.obj: CMakeFiles/TCPServer.dir/includes_CXX.rsp
CMakeFiles/TCPServer.dir/mSocket.cpp.obj: ../mSocket.cpp
CMakeFiles/TCPServer.dir/mSocket.cpp.obj: CMakeFiles/TCPServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TCPServer.dir/mSocket.cpp.obj"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TCPServer.dir/mSocket.cpp.obj -MF CMakeFiles\TCPServer.dir\mSocket.cpp.obj.d -o CMakeFiles\TCPServer.dir\mSocket.cpp.obj -c C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\mSocket.cpp

CMakeFiles/TCPServer.dir/mSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPServer.dir/mSocket.cpp.i"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\mSocket.cpp > CMakeFiles\TCPServer.dir\mSocket.cpp.i

CMakeFiles/TCPServer.dir/mSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPServer.dir/mSocket.cpp.s"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\mSocket.cpp -o CMakeFiles\TCPServer.dir\mSocket.cpp.s

CMakeFiles/TCPServer.dir/mServer.cpp.obj: CMakeFiles/TCPServer.dir/flags.make
CMakeFiles/TCPServer.dir/mServer.cpp.obj: CMakeFiles/TCPServer.dir/includes_CXX.rsp
CMakeFiles/TCPServer.dir/mServer.cpp.obj: ../mServer.cpp
CMakeFiles/TCPServer.dir/mServer.cpp.obj: CMakeFiles/TCPServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TCPServer.dir/mServer.cpp.obj"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TCPServer.dir/mServer.cpp.obj -MF CMakeFiles\TCPServer.dir\mServer.cpp.obj.d -o CMakeFiles\TCPServer.dir\mServer.cpp.obj -c C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\mServer.cpp

CMakeFiles/TCPServer.dir/mServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TCPServer.dir/mServer.cpp.i"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\mServer.cpp > CMakeFiles\TCPServer.dir\mServer.cpp.i

CMakeFiles/TCPServer.dir/mServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TCPServer.dir/mServer.cpp.s"
	C:\Qt\Qt5.9.9\Tools\mingw530_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\mServer.cpp -o CMakeFiles\TCPServer.dir\mServer.cpp.s

# Object files for target TCPServer
TCPServer_OBJECTS = \
"CMakeFiles/TCPServer.dir/TCPServer_autogen/mocs_compilation.cpp.obj" \
"CMakeFiles/TCPServer.dir/main.cpp.obj" \
"CMakeFiles/TCPServer.dir/TCPServer.cpp.obj" \
"CMakeFiles/TCPServer.dir/mSocket.cpp.obj" \
"CMakeFiles/TCPServer.dir/mServer.cpp.obj"

# External object files for target TCPServer
TCPServer_EXTERNAL_OBJECTS =

TCPServer.exe: CMakeFiles/TCPServer.dir/TCPServer_autogen/mocs_compilation.cpp.obj
TCPServer.exe: CMakeFiles/TCPServer.dir/main.cpp.obj
TCPServer.exe: CMakeFiles/TCPServer.dir/TCPServer.cpp.obj
TCPServer.exe: CMakeFiles/TCPServer.dir/mSocket.cpp.obj
TCPServer.exe: CMakeFiles/TCPServer.dir/mServer.cpp.obj
TCPServer.exe: CMakeFiles/TCPServer.dir/build.make
TCPServer.exe: C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib/libQt5Widgetsd.a
TCPServer.exe: C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib/libQt5Networkd.a
TCPServer.exe: C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib/libQt5Guid.a
TCPServer.exe: C:/Qt/Qt5.9.9/5.9.9/mingw53_32/lib/libQt5Cored.a
TCPServer.exe: CMakeFiles/TCPServer.dir/linklibs.rsp
TCPServer.exe: CMakeFiles/TCPServer.dir/objects1.rsp
TCPServer.exe: CMakeFiles/TCPServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable TCPServer.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TCPServer.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TCPServer.dir/build: TCPServer.exe
.PHONY : CMakeFiles/TCPServer.dir/build

CMakeFiles/TCPServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TCPServer.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TCPServer.dir/clean

CMakeFiles/TCPServer.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug C:\Users\chenb\Documents\qt\TCPServerClientOther\TCPServer\build-TCPServer-Debug\CMakeFiles\TCPServer.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TCPServer.dir/depend

