Development Notes
=================


Goals:
------


1. Define a set of common high-level configurations for `build2` like "C++ build for MSVC" (but phrased differently) with decent recommended flags.
2. Allow quick customization of such common high-level configurations, like "Debug or Release, with or without sanitizers, with flags recommended by Jason Turner or Scott Meyers".
3. Designed to be used seemlessly with `build2`'s tools, easy to use by beginners and allows generating multiple configs at once.
4. Enable the possibility to integrate it or rewrite it easilly inside `build2`'s framework (implies easy to read, modify and having most functionality as library, obviously). 
    - Ideally the expression describing the high-level config should be designed like if it could written as part of a `bdep init -C ...` command.
5. Ideally, a visual interface to help beginners (in-terminal probably).


TODO:
-----

Features:

- [ ] Define the syntaxe of the config expression separately from 
- [ ] Basic support of msvc, llvm/clang, gcc
- [ ] Default flags for basic toolchains and how to disable them
- [ ] Some advanced flags for famous recommdentations: Jason Turner, Scott Meyer
- [ ] Address, Undefined, Thread and Memory sanitizers

Scafholdings:

- [ ] Setup CI
- [ ] Setup separate test package for `libbhlc`
- [ ] Add write and add a clang-format file (using 4 spaces or tab, not 2 spaces `;__;`)
- [ ] Add vscode files to help with debugging and intellisense. Maybe VS too.
- [ ] Consider using `tl-generator` to allow using coroutines to simplify the code.
- [ ] Use this to generate configs for itself as tests and actual usage, in particular for release and sanitizers.

----
DONE:
----

