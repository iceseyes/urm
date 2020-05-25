#ifndef URM_STORAGE_HPP
#define URM_STORAGE_HPP

#include <filesystem>
#include <memory>
#include <optional>

#include "defines.hpp"

namespace urm {

class Storage {
public:
    virtual std::optional<WORD> fetch(Number pc) const = 0;
};
using StoragePtr = std::unique_ptr<Storage>;

StoragePtr makeStorage(const std::filesystem::path &source);

}  // namespace urm

#endif  // URM_STORAGE_HPP
