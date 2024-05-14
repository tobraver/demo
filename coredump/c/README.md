# 程序编译

`gcc coredump_c.c -o coredump_c -g`

# 使能Coredump

```
# 设置
ulimit -c unlimited

# 查看
ulimit -a
```



# 查看位置

[addr2line使用方法](https://blog.csdn.net/mingtiannihaoabc/article/details/131263823)

```
/* "static" means don't export the symbol... */
static void function_2(void)

addr2line -f -p -e crash_c 0x1288
function_2 at /home/wz/project/demo/crash/c/crash_c.c:22
```


