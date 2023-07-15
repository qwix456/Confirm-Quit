@echo off

REM edit paths here, important: \ at the end

set NDK=F:\android-ndk-r16b-windows-x86_64\android-ndk-r16b\

set MAIN=F:\Quit-Ok\

call %NDK%ndk-build.cmd NDK_PROJECT_PATH=%MAIN% NDK_APPLICATION_MK=%MAIN%jni\Application.mk MAIN_LOCAL_PATH=%MAIN%jni
pause