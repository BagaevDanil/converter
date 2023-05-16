mkdir build
cd build
cmake ..
cmake --build . --target Main

if exist Debug\Main.exe (
    Debug\Main.exe
)

pause