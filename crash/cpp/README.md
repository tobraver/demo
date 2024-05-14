# 程序编译

`g++ crash_cpp.cpp -o crash_cpp -g -rdynamic -ldl`

# 运行结果

```
function_1
function_2
function_3
================================================================
[1] signal_handler(int)
[2] /lib/x86_64-linux-gnu/libc.so.6(+0x43090) [0x7f4c04553090]
[3] function_3(int*)
[4] ./crash_cpp(+0x1365) [0x7f4c0494d365]
[5] function_1()
[6] ./crash_cpp(main+0x3a) [0x7f4c0494d3be]
[7] /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf3) [0x7f4c04534083]
[8] ./crash_cpp(_start+0x2e) [0x7f4c0494d20e]
================================================================
Segmentation fault (core dumped)
```


# 查看位置

[addr2line使用方法](https://blog.csdn.net/mingtiannihaoabc/article/details/131263823)

```

/* "static" means don't export the symbol... */
static void function_2(void)

addr2line -f -p -e crash_cpp 0x1365
_ZL10function_2v at /home/wz/project/demo/crash/cpp/crash_cpp.cpp:34
```


