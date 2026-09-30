set echo on

CFiles=$(find . -type f -name "*.c")
echo "Files found to be compiled:" $CFiles

echo "Building initialized"
assembly="b"
compilerflags="-g -Wall -std=c89 -fPIC"
includeflags="-Isrc"
linkerflags="-lSDL3 -lSDL2_mixer -lSDL2_ttf -lSDL2_mixer -L/Lib -lm -ldl -no-pie"
echo "Compilation is using the Comp. flags: " $compilerflags
echo "Compilation is using the Incl. flags: " $includeflags
echo "Compilation is using the Link. flags: " $linkerflags

echo "Building $assembly..."

echo gcc $CFiles -o $assembly $compilerflags $includeflags $linkerflags
gcc $CFiles $compilerflags $includeflags $linkerflags -o $assembly
