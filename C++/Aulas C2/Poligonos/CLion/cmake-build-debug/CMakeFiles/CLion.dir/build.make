# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.11

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\CLion.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\CLion.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\CLion.dir\flags.make

CMakeFiles\CLion.dir\main.cpp.obj: CMakeFiles\CLion.dir\flags.make
CMakeFiles\CLion.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CLion.dir/main.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CLion.dir\main.cpp.obj -c "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\main.cpp"

CMakeFiles\CLion.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/main.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\main.cpp" > CMakeFiles\CLion.dir\main.cpp.i

CMakeFiles\CLion.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/main.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\main.cpp" -o CMakeFiles\CLion.dir\main.cpp.s

CMakeFiles\CLion.dir\polygon.cpp.obj: CMakeFiles\CLion.dir\flags.make
CMakeFiles\CLion.dir\polygon.cpp.obj: ..\polygon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CLion.dir/polygon.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CLion.dir\polygon.cpp.obj -c "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\polygon.cpp"

CMakeFiles\CLion.dir\polygon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/polygon.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\polygon.cpp" > CMakeFiles\CLion.dir\polygon.cpp.i

CMakeFiles\CLion.dir\polygon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/polygon.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\polygon.cpp" -o CMakeFiles\CLion.dir\polygon.cpp.s

CMakeFiles\CLion.dir\circle.cpp.obj: CMakeFiles\CLion.dir\flags.make
CMakeFiles\CLion.dir\circle.cpp.obj: ..\circle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CLion.dir/circle.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CLion.dir\circle.cpp.obj -c "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\circle.cpp"

CMakeFiles\CLion.dir\circle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/circle.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\circle.cpp" > CMakeFiles\CLion.dir\circle.cpp.i

CMakeFiles\CLion.dir\circle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/circle.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\circle.cpp" -o CMakeFiles\CLion.dir\circle.cpp.s

CMakeFiles\CLion.dir\complexpolygon.cpp.obj: CMakeFiles\CLion.dir\flags.make
CMakeFiles\CLion.dir\complexpolygon.cpp.obj: ..\complexpolygon.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CLion.dir/complexpolygon.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CLion.dir\complexpolygon.cpp.obj -c "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\complexpolygon.cpp"

CMakeFiles\CLion.dir\complexpolygon.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/complexpolygon.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\complexpolygon.cpp" > CMakeFiles\CLion.dir\complexpolygon.cpp.i

CMakeFiles\CLion.dir\complexpolygon.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/complexpolygon.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\complexpolygon.cpp" -o CMakeFiles\CLion.dir\complexpolygon.cpp.s

CMakeFiles\CLion.dir\Triangle.cpp.obj: CMakeFiles\CLion.dir\flags.make
CMakeFiles\CLion.dir\Triangle.cpp.obj: ..\Triangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CLion.dir/Triangle.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CLion.dir\Triangle.cpp.obj -c "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\Triangle.cpp"

CMakeFiles\CLion.dir\Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/Triangle.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\Triangle.cpp" > CMakeFiles\CLion.dir\Triangle.cpp.i

CMakeFiles\CLion.dir\Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/Triangle.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\Triangle.cpp" -o CMakeFiles\CLion.dir\Triangle.cpp.s

CMakeFiles\CLion.dir\Rectangle.cpp.obj: CMakeFiles\CLion.dir\flags.make
CMakeFiles\CLion.dir\Rectangle.cpp.obj: ..\Rectangle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CLion.dir/Rectangle.cpp.obj"
	C:\TDM-GCC-64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CLion.dir\Rectangle.cpp.obj -c "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\Rectangle.cpp"

CMakeFiles\CLion.dir\Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CLion.dir/Rectangle.cpp.i"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\Rectangle.cpp" > CMakeFiles\CLion.dir\Rectangle.cpp.i

CMakeFiles\CLion.dir\Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CLion.dir/Rectangle.cpp.s"
	C:\TDM-GCC-64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\Rectangle.cpp" -o CMakeFiles\CLion.dir\Rectangle.cpp.s

# Object files for target CLion
CLion_OBJECTS = \
"CMakeFiles\CLion.dir\main.cpp.obj" \
"CMakeFiles\CLion.dir\polygon.cpp.obj" \
"CMakeFiles\CLion.dir\circle.cpp.obj" \
"CMakeFiles\CLion.dir\complexpolygon.cpp.obj" \
"CMakeFiles\CLion.dir\Triangle.cpp.obj" \
"CMakeFiles\CLion.dir\Rectangle.cpp.obj"

# External object files for target CLion
CLion_EXTERNAL_OBJECTS =

CLion.exe: CMakeFiles\CLion.dir\main.cpp.obj
CLion.exe: CMakeFiles\CLion.dir\polygon.cpp.obj
CLion.exe: CMakeFiles\CLion.dir\circle.cpp.obj
CLion.exe: CMakeFiles\CLion.dir\complexpolygon.cpp.obj
CLion.exe: CMakeFiles\CLion.dir\Triangle.cpp.obj
CLion.exe: CMakeFiles\CLion.dir\Rectangle.cpp.obj
CLion.exe: CMakeFiles\CLion.dir\build.make
CLion.exe: CMakeFiles\CLion.dir\linklibs.rsp
CLion.exe: CMakeFiles\CLion.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable CLion.exe"
	"C:\Program Files\CMake\bin\cmake.exe" -E remove -f CMakeFiles\CLion.dir/objects.a
	C:\TDM-GCC-64\bin\ar.exe cr CMakeFiles\CLion.dir/objects.a @CMakeFiles\CLion.dir\objects1.rsp
	C:\TDM-GCC-64\bin\g++.exe -g   -Wl,--whole-archive CMakeFiles\CLion.dir/objects.a -Wl,--no-whole-archive  -o CLion.exe -Wl,--out-implib,libCLion.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles\CLion.dir\linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles\CLion.dir\build: CLion.exe

.PHONY : CMakeFiles\CLion.dir\build

CMakeFiles\CLion.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CLion.dir\cmake_clean.cmake
.PHONY : CMakeFiles\CLion.dir\clean

CMakeFiles\CLion.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion" "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion" "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\cmake-build-debug" "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\cmake-build-debug" "D:\Jedson\Documents\GitHub\UniProjects\C++\Aulas C2\Poligonos\CLion\cmake-build-debug\CMakeFiles\CLion.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\CLion.dir\depend
