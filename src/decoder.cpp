#include "decoder.hpp"
#include "decoder_impl.hpp"

#include <iostream>
#include <array>
#include <exception>
#include <memory>
#include <string>

#include "defines.hpp"
#include "instruction.hpp"

using std::array;
using std::logic_error;
using std::make_unique;
using std::to_string;
using std::unique_ptr;

namespace urm {

DecoderPtr makeDecoder() { return make_unique<impl::BasicDecoder>(); }

namespace impl {

array<byte, 4> toByteArray(WORD word) {
    return {
        byte(word & 0xFF),
        byte((word >> 8) & 0xFF),
        byte((word >> 16) & 0xFF),
        byte((word >> 24) & 0xFF),
    };
}

std::unique_ptr<Instruction> BasicDecoder::decode(WORD word) const {
    auto bytes = toByteArray(word);
    switch (bytes[0]) {
    case InstructionCode::ZERO:
        return make_unique<urm::ZeroInstr>(bytes[1]);
    case InstructionCode::INCR:
        return make_unique<IncrInstr>(bytes[1]);
    case InstructionCode::PROJ:
        return make_unique<ProjInstr>(bytes[1], bytes[2]);
    case InstructionCode::JUMP:
        return make_unique<JumpInstr>(bytes[1], bytes[2], bytes[3]);
    }

    throw logic_error("unknown instruction code " + to_string(unsigned(bytes[0])));
}

}  // namespace impl

}  // namespace urm
