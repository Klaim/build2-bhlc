# build2-high-level-configs


Syntax being considered:
```

bhlc <toolchain>,<other options groups>,...
-> generates a configuration file

bhlc msvc,debug
-> msvc-debug.config (contains basic recommended flags like warning levels high but not to the max, and debug flags)

bhlc toolchain=msvc=15.9,debug
-> msvc15.9-debug.config (exactly the same as before but more verbose)

bhlc msvc,debug --
-> (exactly the same as before but output to the )

bhlc msvc=15.9,release,warnings=all
-> msvc15.9-release.config (contains basic recommended flags, uses specific toolchain version, rise warning level to the max)

bhlc msvc,{debug release}
-> msvc-debug.config msvc-release.config

bhlc msvc,{debug release release-debug}
-> msvc-debug.config msvc-release.config msvc-release-debug.config (this last one is release (aka optimized) with debug info)

bhlc msvc,{debug release release-minsize}
-> msvc-debug.config msvc-release.config msvc-release-minsize.config

bhlc msvc,{debug release} config.cxx.poptions+=-DSOME_DEFINE=1
-> msvc-debug.config msvc-release.config (with additional `config.cxx.poptions = -DSOME_DEFINE=1` )

bhlc {msvc clang},{debug release}
-> msvc-debug.config msvc-release.config clang-debug.config clang-release.config


bhlc {msvc clang},{debug release},{* asan usan tsan}
-> msvc-debug.config msvc-release.config clang-debug.config clang-release.config
   msvc-debug-asan.config msvc-release-asan.config clang-debug-asan.config clang-release-asan.config
   msvc-debug-usan.config msvc-release-usan.config clang-debug-usan.config clang-release-usan.config
   msvc-debug-tsan.config msvc-release-tsan.config clang-debug-tsan.config clang-release-tsan.config

bhlc {msvc clang},{debug release},{* asan,usan,tsan}
-> msvc-debug.config msvc-release.config clang-debug.config clang-release.config
   msvc-debug-asan-usan-tsan.config msvc-release-asan-usan-tsan.config clang-debug-asan-usan-tsan.config clang-release-asan-usan-tsan.config

bhlc {msvc clang},{debug release}
-> msvc-debug.config msvc-release.config clang-debug.config clang-release.config

bhlc msvc,debug,no-default-flags
-> msvc-debug.config (but without any recommended flags)

bhlc msvc,debug,pedantic
-> msvc-debug.config msvc-release.config (with flags recommended for pedantic diagnostic)

bhlc msvc,debug,pedantic=jturner
-> msvc-debug.config (but with flags recommended by Jason Turner)

bhlc msvc,arch={x86 x64},{debug release}
-> msvc-x86-debug.config msvc-x86-release.config msvc-x64-debug.config msvc-x64-release.config

bhlc msvc,{debug release} --outdir configs/
-> configs/msvc-debug.config configs/msvc-release.config

bhlc create msvc,{debug release}
-> msvc-debug/ msvc-release/ (generate build configuration dirs using `bpkg create`)

```