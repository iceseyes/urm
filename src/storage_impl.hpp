#ifndef URM_STORAGE_IMPL_HPP
#define URM_STORAGE_IMPL_HPP

#include <filesystem>
#include <fstream>
#include <iostream>

#include "storage.hpp"

namespace urm::impl {

class FileStorage : public Storage {
    mutable std::ifstream _in;
    size_t _len;

public:
    FileStorage(const std::filesystem::path &path);
    std::optional<WORD> fetch(Number pc) const override;
};

}  // namespace urm::impl

#endif  // URM_STORAGE_IMPL_HPP
