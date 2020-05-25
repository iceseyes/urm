#include "urm.hpp"
#include "urm_impl.hpp"

#include <memory>

#include "storage.hpp"
#include "decoder.hpp"
#include "instruction.hpp"

using std::make_unique;

namespace urm {

URM::Pimpl::Pimpl(const Storage &storage, const Decoder &decoder) : storage(storage), decoder(decoder) {}

URM::URM(const Storage &storage, const Decoder &decoder) : _impl(make_unique<Pimpl>(storage, decoder)) {}

URM::~URM() = default;

Number URM::run() {
    while (auto word = _impl->storage.fetch(_impl->pc)) {
        auto instruction = _impl->decoder.decode(*word);
        instruction->execute(_impl->pc, _impl->registries);
    }

    return _impl->registries[0];
}

}  // namespace urm
