#ifndef URM_URM_IMPL_HPP
#define URM_URM_IMPL_HPP

#include "urm.hpp"

#include "defines.hpp"

namespace urm {

struct URM::Pimpl {
    const Storage &storage;
    const Decoder &decoder;
    Registries registries;
    Number pc;

    Pimpl(const Storage &storage, const Decoder &decoder);
};

}  // namespace urm

#endif  // URM_URM_IMPL_HPP
