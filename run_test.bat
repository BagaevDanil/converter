mkdir build
cd build
cmake ..
cmake --build . --target Test

if exist Debug\Test.exe (
    Debug\Test.exe
)

pause