#ifndef URM_DECODER_HPP
#define URM_DECODER_HPP

#include <memory>

#include "defines.hpp"

namespace urm {

class Instruction;

class Decoder {
public:
    virtual std::unique_ptr<Instruction> decode(WORD) const = 0;
};
using DecoderPtr = std::unique_ptr<Decoder>;

DecoderPtr makeDecoder();

}  // namespace urm

#endif  // URM_DECODER_HPP
