#ifndef URM_URM_HPP
#define URM_URM_HPP

#include <cstdint>
#include <map>
#include <memory>

#include "defines.hpp"

namespace urm {

class Storage;
class Decoder;
class Executor;

class URM {
public:
    using Registries = std::map<byte, Number>;

    URM(const Storage &storage, const Decoder &decoder);
    URM(const URM &) = delete;
    URM(URM &&) = delete;
    ~URM();

    URM &operator=(const URM &) = delete;
    URM &operator=(URM &&) = delete;

    Number run();

private:
    struct Pimpl;
    std::unique_ptr<Pimpl> _impl;
};

}  // namespace urm

#endif  // URM_URM_HPP
