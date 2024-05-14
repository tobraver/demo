# 程序编译

`gcc crash_c.c -o crash_c -g -rdynamic`

# 运行结果

```
function_1
function_2
function_3
================================================================
[0]: ./crash_c(crash_trace_dump+0x38) [0x7f45f0b89355]
[1]: ./crash_c(signal_handler+0x19) [0x7f45f0b89301]
[2]: /lib/x86_64-linux-gnu/libc.so.6(+0x43090) [0x7f45f0993090]
[3]: ./crash_c(function_3+0x24) [0x7f45f0b8924d]
[4]: ./crash_c(+0x1288) [0x7f45f0b89288]
[5]: ./crash_c(function_1+0x19) [0x7f45f0b892a4]
[6]: ./crash_c(main+0x3a) [0x7f45f0b892e1]
[7]: /lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf3) [0x7f45f0974083]
[8]: ./crash_c(_start+0x2e) [0x7f45f0b8916e]
================================================================
Segmentation fault (core dumped)
```


# 查看位置

[addr2line使用方法](https://blog.csdn.net/mingtiannihaoabc/article/details/131263823)

```
/* "static" means don't export the symbol... */
static void function_2(void)

addr2line -f -p -e crash_c 0x1288
function_2 at /home/wz/project/demo/crash/c/crash_c.c:22
```


