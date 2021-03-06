cmake_minimum_required(VERSION 3.14)
project(MIPS_MONOCYCLE)

set(CMAKE_CXX_STANDARD 14)

add_executable(MIPS_MONOCYCLE
		src/main.cpp
		src/Machine/Machine.cpp
		src/Machine/Machine.h
		src/Machine/Processor.cpp
		src/Machine/Processor.h
		src/Machine/Processor/PCRegister/PCRegister.cpp
		src/Machine/Processor/PCRegister/PCRegister.h
		src/Machine/Processor/Adder/Adder.cpp
		src/Machine/Processor/Adder/Adder.h
		src/Machine/Processor/InstructionMemory/InstructionMemory.cpp
		src/Machine/Processor/InstructionMemory/InstructionMemory.h
		src/Machine/Processor/Control/Control.cpp
		src/Machine/Processor/Control/Control.h
		src/Machine/Processor/Multiplexer/Multiplexer.cpp
		src/Machine/Processor/Multiplexer/Multiplexer.h
		src/Machine/Processor/Registers/Registers.cpp
		src/Machine/Processor/Registers/Registers.h
		src/Machine/Processor/SignExtend/SignExtend.cpp
		src/Machine/Processor/SignExtend/SignExtend.h
		src/Machine/Processor/ShiftLeft2/ShiftLeft2.cpp
		src/Machine/Processor/ShiftLeft2/ShiftLeft2.h
		src/Machine/Processor/ALUControl/ALUControl.cpp
		src/Machine/Processor/ALUControl/ALUControl.h
		src/Machine/Processor/ALU/ALU.cpp
		src/Machine/Processor/ALU/ALU.h
		src/Machine/Processor/DataMemory/DataMemory.cpp
		src/Machine/Processor/DataMemory/DataMemory.h
		src/Machine/Bus/INBus.cpp
		src/Machine/Bus/INBus.h
		src/Machine/Bus/OUTBus.cpp
		src/Machine/Bus/OUTBus.h
		src/Machine/Processor/BranchControl/BranchControl.cpp
		src/Machine/Processor/BranchControl/BranchControl.h)