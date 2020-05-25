#ifndef URM_INSTRUCTION_HPP
#define URM_INSTRUCTION_HPP

#include "defines.hpp"
#include "urm.hpp"

namespace urm {

enum InstructionCode { ZERO = 0, INCR = 1, PROJ = 2, JUMP = 3 };

class Instruction {
public:
    virtual void execute(Number &pc, URM::Registries &registries) const = 0;
};

class ZeroInstr : public Instruction {
    byte r;

public:
    ZeroInstr(byte r);
    void execute(Number &pc, URM::Registries &registries) const override;
};

class IncrInstr : public Instruction {
    byte r;

public:
    IncrInstr(byte r);
    void execute(Number &pc, URM::Registries &registries) const override;
};

class ProjInstr : public Instruction {
    byte s;
    byte d;

public:
    ProjInstr(byte s, byte d);
    void execute(Number &pc, URM::Registries &registries) const override;
};

class JumpInstr : public Instruction {
    byte a;
    byte b;
    byte t;

public:
    JumpInstr(byte a, byte b, byte t);
    void execute(Number &pc, URM::Registries &registries) const override;
};

}  // namespace urm

#endif  // URM_INSTRUCTION_HPP
