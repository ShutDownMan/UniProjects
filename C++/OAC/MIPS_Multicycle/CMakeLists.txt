cmake_minimum_required(VERSION 3.14)
project(MIPS_MULTICYCLE)

set(CMAKE_CXX_STANDARD 14)

add_executable(MIPS_MULTICYCLE
        src/main.cpp
        src/Machine/Machine.cpp
        src/Machine/Machine.h
        src/Machine/Processor.cpp
        src/Machine/Processor.h
        src/Machine/Bus/INBus.cpp
        src/Machine/Bus/INBus.h
        src/Machine/Bus/OUTBus.cpp
        src/Machine/Bus/OUTBus.h
        src/Machine/Processor/Multiplexer/Multiplexer.cpp
        src/Machine/Processor/Multiplexer/Multiplexer.h
        src/Machine/Processor/Memory/Memory.cpp
        src/Machine/Processor/Memory/Memory.h
        src/Machine/Processor/Controller/Controller.cpp
        src/Machine/Processor/Controller/Controller.h
        src/Machine/Processor/Registers/Registers.cpp
        src/Machine/Processor/Registers/Registers.h
        src/Machine/Processor/ShiftLeft2/ShiftLeft2.cpp
        src/Machine/Processor/ShiftLeft2/ShiftLeft2.h
        src/Machine/Processor/SignExtend/SignExtend.cpp
        src/Machine/Processor/SignExtend/SignExtend.h
        src/Machine/Processor/BranchController/BranchController.cpp
        src/Machine/Processor/BranchController/BranchController.h
        src/Machine/Processor/ALUController/ALUController.cpp
        src/Machine/Processor/ALUController/ALUController.h
        src/Machine/Processor/ALU/ALU.cpp
        src/Machine/Processor/ALU/ALU.h
        src/Machine/Processor/Register/Register.cpp
        src/Machine/Processor/Register/Register.h)