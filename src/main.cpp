#include <iostream>

#include "storage.hpp"
#include "decoder.hpp"
#include "urm.hpp"

using urm::makeDecoder;
using urm::makeStorage;
using urm::URM;

int main(int argc, char *argv[]) {
    auto storage = makeStorage(argv[1]);
    auto decoder = makeDecoder();
    URM urm{*storage, *decoder};
    std::cout << "Result is: " << unsigned(urm.run()) << std::endl;
    return 0;
}
