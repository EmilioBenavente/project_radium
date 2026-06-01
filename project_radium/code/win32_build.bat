@echo off

set COMMON_CMD_FLAGS=-nologo -MTd -Z7
set COMMON_LINKER_FLAGS=/link /LIBPATH:"..\project_radium\code\" raylib.lib gdi32.lib user32.lib winmm.lib shell32.lib -INCREMENTAL:NO

if not exist ..\..\build mkdir ..\..\build

pushd ..\..\build

del /S /Q *

cl %COMMON_CMD_FLAGS% ..\project_radium\code\ray_radium.c  %COMMON_LINKER_FLAGS%

popd
