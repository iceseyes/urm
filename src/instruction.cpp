#include "instruction.hpp"

#include "defines.hpp"
#include "urm.hpp"

namespace urm {

ZeroInstr::ZeroInstr(byte r) : r(r) {}
void ZeroInstr::execute(Number &pc, URM::Registries &registries) const {
    registries[r] = 0;
    ++pc;
}

IncrInstr::IncrInstr(byte r) : r(r) {}
void IncrInstr::execute(Number &pc, URM::Registries &registries) const {
    registries[r]++;
    ++pc;
}

ProjInstr::ProjInstr(byte s, byte d) : s(s), d(d) {}
void ProjInstr::execute(Number &pc, URM::Registries &registries) const {
    registries[d] = registries[s];
    ++pc;
}

JumpInstr::JumpInstr(byte a, byte b, byte t) : a(a), b(b), t(t) {}
void JumpInstr::execute(Number &pc, URM::Registries &registries) const {
    if (registries[a] == registries[b])
        pc = t * sizeof(WORD);
    else
        ++pc;
}

}  // namespace urm
