//
// Created by jarvis on 7/22/19.
//

#ifndef MIPS_MONOCYCLE_CONTROL_H
#define MIPS_MONOCYCLE_CONTROL_H

#include "../../Bus/OUTBus.h"
#include "../../Bus/INBus.h"

#define IS_RTYPE_INSTRUCTION    0x00u
#define IS_LW_INSTRUCTION       0x23u
#define IS_SW_INSTRUCTION       0x2Bu
#define IS_BEQ_INSTRUCTION      0x04u
#define IS_BNE_INSTRUCTION      0x05u
#define IS_LI_INSTRUCTION       0x0Fu
#define IS_J_INSTRUCTION        0x02u

typedef enum InstructionType {
    RTYPE,
    LW,
    SW,
    BEQ,
    BNE,
    LI,
    J,
    NONE
} InstructionType;

typedef enum StateName {
//    Initialization,             /// 0
    InstructionFetch,           /// 0
    InstructionDecode,          /// 1
    MemoryAddressComputation,   /// 2
    MemoryAccessLW,             /// 3
    MemoryAccessSW,             /// 4
    MemoryReadCompletionStep,   /// 5
    Execution,                  /// 6
    RTypeCompletion,            /// 7
    BranchCompletion,           /// 8
    JumpCompletion,             /// 9
    LoadImmediate,              /// 10
    LoadImmediateCompletion     /// 11
} StateName;

class Controller {

private:
    StateName state;

    INBus *inBus;

    OUTBus *BranchSignal;
    OUTBus *MemReadSignal;
    OUTBus *IRWriteSignal;
public:
    OUTBus *getIRWriteSignal() const;

private:
    OUTBus *MemToRegSignal;
    OUTBus *ALUOpSignal;
    OUTBus *MemWriteSignal;
    OUTBus *RegWriteSignal;
    OUTBus *RegDstSignal;
    OUTBus *RegDataSrcSignal;
    OUTBus *BranchJumpSignal;
    OUTBus *IorDSignal;
    OUTBus *PCWriteCondSignal;
    OUTBus *PCWriteSignal;
    OUTBus *AluSrcASignal;
    OUTBus *AluSrcBSignal;
    OUTBus *PCSourceSignal;

public:
    Controller();

    void updateState();

    void initialize(INBus *inBusRef);

    OUTBus *getRegDstSignal() const;

    OUTBus *getBranchSignal() const;

    OUTBus *getMemReadSignal() const;

    OUTBus *getMemToRegSignal() const;

    OUTBus *getAluOpSignal() const;

    OUTBus *getMemWriteSignal() const;

    OUTBus *getRegWriteSignal() const;

    OUTBus *getRegDataSrc() const;

    OUTBus *getBranchJumpSignal() const;

    OUTBus *getIorDSignal() const;

    OUTBus *getPCWriteCondSignal() const;

    OUTBus *getPCWriteSignal() const;

    OUTBus *getAluSrcASignal() const;

    OUTBus *getAluSrcBSignal() const;

    OUTBus *getPCSourceSignal() const;

    InstructionType getInstructionType();

    void printContents();

    void updateIO();
};


#endif //MIPS_MONOCYCLE_CONTROL_H
