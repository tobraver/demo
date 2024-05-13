# 程序编译

`gcc crash_c.c -o crash_c -g -rdynamic`

# 运行结果

```
function_1
function_2
function_3
================================================================
[0]: ./crash_c(crash_trace_dump+0x38) [0x7f9c8b7d734b]
[1]: ./crash_c(signal_handler+0x19) [0x7f9c8b7d72f7]
[2]: /lib/x86_64-linux-gnu/libc.so.6(+0x43090) [0x7f9c8b5e3090]
[3]: ./crash_c(function_3+0x24) [0x7f9c8b7d724d]
[4]: ./crash_c(+0x127e) [0x7f9c8b7d727e]
[5]: ./crash_c(+0x129a) [0x7f9c8b7d729a]
[6]: ./crash_c(main+0x3a) [0x7f9c8b7d72d7]
[7]: /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf3) [0x7f9c8b5c4083]
[8]: ./crash_c(_start+0x2e) [0x7f9c8b7d716e]
================================================================
Segmentation fault (core dumped)
```


# 查看位置

[addr2line使用方法](https://blog.csdn.net/mingtiannihaoabc/article/details/131263823)

```
addr2line -f -p -e crash_c 0x127e
function_2 at /home/wz/project/demo/crash/c/crash_c.c:22

addr2line -f -p -e crash_c 0x129a
function_1 at /home/wz/project/demo/crash/c/crash_c.c:28
```


