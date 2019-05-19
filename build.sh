#! /bin/bash

SFML_VERSION=2.5.1

mkdir extern

# Download SFML
curl "https://www.sfml-dev.org/files/SFML-$SFML_VERSION-linux-gcc-64-bit.tar.gz" -o "extern/SFML-$SFML_VERSION.tar.gz"
cd extern
tar -xzf "SFML-$SFML_VERSION.tar.gz"
cd ..

# Build Project
if [ "$1" == "--skip-tests" ]; then
    mkdir build
    cd build

    cmake -DBUILD_TESTS=OFF ..
else
    # Download Catch2
    cd extern
    git clone https://github.com/catchorg/Catch2.git
    cd Catch2
    cmake -Bbuild -H. -DBUILD_TESTING=OFF
    sudo env "PATH=$PATH" cmake --build build/ --target install

    mkdir ../../build
    cd ../../build
    cmake ..
fi
make
cd ..
