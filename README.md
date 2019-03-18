# ClingParser
This project is the prototyp for the new implementation of the function `cling::utils::getWrapPoint` (lib/Utils/SourceNormalization.cpp) of the [cling](https://github.com/root-project/cling). The new implementation is based on the clang library and should make it possible to recognize more C++ statements.

# Result
It should not be possible to implement a **syntax-only** compiler with the clang library, since the -syntax-only mode also performs semantic analyses. The separate deactivation of semantic analysis is currently not possible.
