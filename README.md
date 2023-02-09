# urm
a simple URM (just for fun)

## How to build

    mkdir -p build/Debug
    cd build/Debug
    cmake -DCMAKE_BUILD_TYPE=Debug ../../
    cmake --build . 
    
## How to use

With python script urmc.py, translate urm assembly program into a binary code for urm. Than pass the binary file to urm program to run it.
