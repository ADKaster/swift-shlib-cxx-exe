Example project showing an issue with metadata emission in Swift 6.0 beta.

```bash
cmake -B build -GNinja
ninja -C build
```

Tested with:

Swift version 6.0-dev (LLVM 3427f33b53c666b, Swift 225809e3f8e9c7b)
Target: x86_64-unknown-linux-gnu

this should produce an error similar to:

```
[4/5] Linking Swift shared library shlib/libshlib.so
FAILED: shlib/libshlib.so 
: && /home/andrew/swift/build/buildbot_linux/none-swift_package_sandbox_linux-x86_64/usr/bin/swiftc -j 32 -num-threads 32 -emit-library -O  /home/andrew/swift/build/buildbot_linux/none-swift_package_sandbox_linux-x86_64/usr/lib/swift/linux/x86_64/swiftrt.o -Xlinker --no-allow-shlib-undefined -Xlinker --no-undefined -use-ld=lld  -Xlinker -soname -Xlinker libshlib.so -o shlib/libshlib.so shlib/CMakeFiles/shlib.dir/Color.cpp.o shlib/CMakeFiles/shlib.dir/Color.swift.o -L /home/andrew/swift/build/buildbot_linux/none-swift_package_sandbox_linux-x86_64/usr/lib/swift/linux   -L /home/andrew/swift/build/buildbot_linux/none-swift_package_sandbox_linux-x86_64/usr/lib/swift/linux/x86_64   -L /usr/lib/gcc/x86_64-linux-gnu/12 -lstdc++  -lm  -lgcc_s  -lgcc  -lc  -lgcc_s  -lgcc && :
error: link command failed with exit code 1 (use -v to see invocation)
ld.lld: error: undefined symbol: $sSo5ColorVMa
>>> referenced by Color.cpp
>>>               /home/andrew/ladybird-org/testing/swift-tests/swift-shlib-cxx-exe/build/shlib/CMakeFiles/shlib.dir/Color.cpp.o:(Color::fromString(Color&, char const*))
>>> referenced by Color.cpp
>>>               /home/andrew/ladybird-org/testing/swift-tests/swift-shlib-cxx-exe/build/shlib/CMakeFiles/shlib.dir/Color.cpp.o:(Color::fromString(Color&, char const*))
>>> referenced by Color.cpp
>>>               /home/andrew/ladybird-org/testing/swift-tests/swift-shlib-cxx-exe/build/shlib/CMakeFiles/shlib.dir/Color.cpp.o:(Color::fromString(Color&, char const*))
>>> referenced 1 more times
clang: error: linker command failed with exit code 1 (use -v to see invocation)
ninja: build stopped: subcommand failed.\
```
