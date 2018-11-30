#!/bin/sh
echo "Going to CMake solution..."
cd ..
echo "Deleting bin folder and its content"
sudo rm -r bin
echo "Deleting build folder and its content"
sudo rm -r build
echo "Creating empty build folder"
mkdir build
echo "Entering in build folder"
cd build
echo "Generating solution..."
sudo cmake ..
echo "Generating application..."
sudo make
echo "Executing application..."
cd ..
cd bin
sudo ./Server