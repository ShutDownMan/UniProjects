# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles\Arquivo_Inverso.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\Arquivo_Inverso.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\Arquivo_Inverso.dir\flags.make

CMakeFiles\Arquivo_Inverso.dir\main.c.obj: CMakeFiles\Arquivo_Inverso.dir\flags.make
CMakeFiles\Arquivo_Inverso.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Arquivo_Inverso.dir/main.c.obj"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Arquivo_Inverso.dir\main.c.obj   -c "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\main.c"

CMakeFiles\Arquivo_Inverso.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Arquivo_Inverso.dir/main.c.i"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\main.c" > CMakeFiles\Arquivo_Inverso.dir\main.c.i

CMakeFiles\Arquivo_Inverso.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Arquivo_Inverso.dir/main.c.s"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\main.c" -o CMakeFiles\Arquivo_Inverso.dir\main.c.s

CMakeFiles\Arquivo_Inverso.dir\BTree.c.obj: CMakeFiles\Arquivo_Inverso.dir\flags.make
CMakeFiles\Arquivo_Inverso.dir\BTree.c.obj: ..\BTree.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Arquivo_Inverso.dir/BTree.c.obj"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Arquivo_Inverso.dir\BTree.c.obj   -c "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\BTree.c"

CMakeFiles\Arquivo_Inverso.dir\BTree.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Arquivo_Inverso.dir/BTree.c.i"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\BTree.c" > CMakeFiles\Arquivo_Inverso.dir\BTree.c.i

CMakeFiles\Arquivo_Inverso.dir\BTree.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Arquivo_Inverso.dir/BTree.c.s"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\BTree.c" -o CMakeFiles\Arquivo_Inverso.dir\BTree.c.s

CMakeFiles\Arquivo_Inverso.dir\Queue.c.obj: CMakeFiles\Arquivo_Inverso.dir\flags.make
CMakeFiles\Arquivo_Inverso.dir\Queue.c.obj: ..\Queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Arquivo_Inverso.dir/Queue.c.obj"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Arquivo_Inverso.dir\Queue.c.obj   -c "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\Queue.c"

CMakeFiles\Arquivo_Inverso.dir\Queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Arquivo_Inverso.dir/Queue.c.i"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\Queue.c" > CMakeFiles\Arquivo_Inverso.dir\Queue.c.i

CMakeFiles\Arquivo_Inverso.dir\Queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Arquivo_Inverso.dir/Queue.c.s"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\Queue.c" -o CMakeFiles\Arquivo_Inverso.dir\Queue.c.s

CMakeFiles\Arquivo_Inverso.dir\InvertionFileManipulation.c.obj: CMakeFiles\Arquivo_Inverso.dir\flags.make
CMakeFiles\Arquivo_Inverso.dir\InvertionFileManipulation.c.obj: ..\InvertionFileManipulation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Arquivo_Inverso.dir/InvertionFileManipulation.c.obj"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Arquivo_Inverso.dir\InvertionFileManipulation.c.obj   -c "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\InvertionFileManipulation.c"

CMakeFiles\Arquivo_Inverso.dir\InvertionFileManipulation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Arquivo_Inverso.dir/InvertionFileManipulation.c.i"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\InvertionFileManipulation.c" > CMakeFiles\Arquivo_Inverso.dir\InvertionFileManipulation.c.i

CMakeFiles\Arquivo_Inverso.dir\InvertionFileManipulation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Arquivo_Inverso.dir/InvertionFileManipulation.c.s"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\InvertionFileManipulation.c" -o CMakeFiles\Arquivo_Inverso.dir\InvertionFileManipulation.c.s

CMakeFiles\Arquivo_Inverso.dir\Registy.c.obj: CMakeFiles\Arquivo_Inverso.dir\flags.make
CMakeFiles\Arquivo_Inverso.dir\Registy.c.obj: ..\Registy.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Arquivo_Inverso.dir/Registy.c.obj"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Arquivo_Inverso.dir\Registy.c.obj   -c "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\Registy.c"

CMakeFiles\Arquivo_Inverso.dir\Registy.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Arquivo_Inverso.dir/Registy.c.i"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\Registy.c" > CMakeFiles\Arquivo_Inverso.dir\Registy.c.i

CMakeFiles\Arquivo_Inverso.dir\Registy.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Arquivo_Inverso.dir/Registy.c.s"
	C:\TDM-GCC-64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\Registy.c" -o CMakeFiles\Arquivo_Inverso.dir\Registy.c.s

# Object files for target Arquivo_Inverso
Arquivo_Inverso_OBJECTS = \
"CMakeFiles\Arquivo_Inverso.dir\main.c.obj" \
"CMakeFiles\Arquivo_Inverso.dir\BTree.c.obj" \
"CMakeFiles\Arquivo_Inverso.dir\Queue.c.obj" \
"CMakeFiles\Arquivo_Inverso.dir\InvertionFileManipulation.c.obj" \
"CMakeFiles\Arquivo_Inverso.dir\Registy.c.obj"

# External object files for target Arquivo_Inverso
Arquivo_Inverso_EXTERNAL_OBJECTS =

Arquivo_Inverso.exe: CMakeFiles\Arquivo_Inverso.dir\main.c.obj
Arquivo_Inverso.exe: CMakeFiles\Arquivo_Inverso.dir\BTree.c.obj
Arquivo_Inverso.exe: CMakeFiles\Arquivo_Inverso.dir\Queue.c.obj
Arquivo_Inverso.exe: CMakeFiles\Arquivo_Inverso.dir\InvertionFileManipulation.c.obj
Arquivo_Inverso.exe: CMakeFiles\Arquivo_Inverso.dir\Registy.c.obj
Arquivo_Inverso.exe: CMakeFiles\Arquivo_Inverso.dir\build.make
Arquivo_Inverso.exe: CMakeFiles\Arquivo_Inverso.dir\linklibs.rsp
Arquivo_Inverso.exe: CMakeFiles\Arquivo_Inverso.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable Arquivo_Inverso.exe"
	"C:\Program Files\CMake\bin\cmake.exe" -E remove -f CMakeFiles\Arquivo_Inverso.dir/objects.a
	C:\TDM-GCC-64\bin\ar.exe cr CMakeFiles\Arquivo_Inverso.dir/objects.a @CMakeFiles\Arquivo_Inverso.dir\objects1.rsp
	C:\TDM-GCC-64\bin\gcc.exe -g   -Wl,--whole-archive CMakeFiles\Arquivo_Inverso.dir/objects.a -Wl,--no-whole-archive  -o Arquivo_Inverso.exe -Wl,--out-implib,libArquivo_Inverso.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles\Arquivo_Inverso.dir\linklibs.rsp

# Rule to build all files generated by this target.
CMakeFiles\Arquivo_Inverso.dir\build: Arquivo_Inverso.exe

.PHONY : CMakeFiles\Arquivo_Inverso.dir\build

CMakeFiles\Arquivo_Inverso.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Arquivo_Inverso.dir\cmake_clean.cmake
.PHONY : CMakeFiles\Arquivo_Inverso.dir\clean

CMakeFiles\Arquivo_Inverso.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso" "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso" "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\cmake-build-debug" "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\cmake-build-debug" "D:\Jedson\Documents\GitHub\UniProjects\C\AED\Trabalhos\Arquivo Inverso\cmake-build-debug\CMakeFiles\Arquivo_Inverso.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles\Arquivo_Inverso.dir\depend

