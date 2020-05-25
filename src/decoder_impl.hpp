#ifndef URM_DECODER_IMPL_HPP
#define URM_DECODER_IMPL_HPP

#include "decoder.hpp"

#include <array>
#include <memory>

#include "defines.hpp"
#include "instruction.hpp"

namespace urm::impl {

class BasicDecoder : public Decoder {
    std::unique_ptr<Instruction> decode(WORD) const override;
};

std::array<byte, 4> toByteArray(WORD word);

}  // namespace urm::impl

#endif  // URM_DECODER_IMPL_HPP
