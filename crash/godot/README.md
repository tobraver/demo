# 说明

第三方的游戏框架：[godot](https://github.com/godotengine/godot)

崩溃时的异常处理：`godot/platform/linuxbsd/crash_handler_linuxbsd.cpp`

[crash_handler_linuxbsd.cpp](./crash_handler_linuxbsd.cpp)

# 处理过程：

1. 获取崩溃时的堆栈信息

2. 将信息转换为相应的位置信息
