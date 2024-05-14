# 配置分区表

增加`coredump`分区

![Coredump 分区](../doc/img/esp32_core_partition.png)


# 使能Coredump输出

`idf.py menuconfig`

![Coredump 配置输出到Flash](../doc/img/esp32_core_flash_conf.png)


# 程序运行输出

![Coredump 运行输出](../doc/img/esp32_core_flash_save.png)


# Coredump分析

## 拉取Coredump文件

`python E:/Espressif/frameworks/esp-idf-v4.4.7/components/esptool_py/esptool/esptool.py -p COM4 read_flash 0x840000 0x4B000 coredump.bin`


![Core文件拉取](../doc/img/esp32_core_file_featch.png)


## 解析Coredum文件

