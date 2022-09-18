.==================================================================.
| Isudo                                                            |
| -----                                                            |
|                                                                  |
| Fast, small yet powerful sudo command for Windows.               |
| Written in C and supports old Windows versions.                  |
| Used LLVM based MinGW toolchain for compiling.                   |
|                                                                  |
|   https://github.com/mstorsjo/llvm-mingw                         |
|                                                                  |
| Isudo is licensed under the MIT license. For more information:   |
|                                                                  |
|   https://en.wikipedia.org/wiki/MIT_License                      |
|                                                                  |
| Isudo can be used in console with following style:               |
|                                                                  |
| .==============================================================. |
| | C:\> isudo -h                                                | |
| | Isudo 1.0.0                                                  | |
| |                                                              | |
| | Code: https://github.com/cart96/isudo                        | |
| | Note: Isudo supports argument/option overriding.             | |
| | Usage: isudo.exe [options|command]                           | |
| |                                                              | |
| | Options                                                      | |
| |    -x<command>    Execute a command as admin.                | |
| |    -k             Keep CMD open after execution.             | |
| |    -c             Close CMD after execution.                 | |
| |    -d             Prevent directory replacing.               | |
| |    -h             You already ran that!                      | |
| |    --             Stop processing arguments.                 | |
| |                                                              | |
| | Examples                                                     | |
| |    isudo.exe                                                 | |
| |    isudo.exe -h                                              | |
| |    isudo.exe -k "echo hello"                                 | |
| |    isudo.exe -xnotepad "pass.txt"                            | |
| |    isudo.exe "echo ?" -ck "echo second"                      | |
| |    isudo.exe -cx"C:\app.exe" "arg1 arg2"                     | |
| [______________________________________________________________] |
[__________________________________________________________________]
