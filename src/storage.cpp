#include "storage.hpp"
#include "storage_impl.hpp"

#include <filesystem>
#include <ios>
#include <optional>

#include "defines.hpp"

using std::ifstream;
using std::ios;
using std::make_optional;
using std::make_unique;
using std::nullopt;
using std::optional;
using std::filesystem::path;

namespace urm {

StoragePtr makeStorage(const path &source) { return make_unique<impl::FileStorage>(source); }

namespace impl {

FileStorage::FileStorage(const path &path) : _in(path, ios::binary) {
    _in.seekg(0, ios::end);
    _len = _in.tellg();
}

optional<WORD> FileStorage::fetch(Number pc) const {
    Number word = 0;
    _in.seekg(pc * sizeof(WORD), ios::beg);
    if (_in && (pc * sizeof(WORD)) < _len) {
        _in.read((char *)&word, sizeof(word));
        return make_optional(word);
    }

    return nullopt;
}

}  // namespace impl

}  // namespace urm
