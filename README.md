# 通讯录

**Date: 2022.6.16**

- ### Windows

  查看 [Release](https://github.com/AkashiNeko/contact/releases/) 。

  如果cmd窗口出现乱码问题：

  1. 打开cmd，切换到程序(.exe)所在目录。
  2. 输入`chcp 65001`，将控制台编码切换为`UTF-8`。
  3. 使用`.\Contact`运行。

- ### Linux

  #### 1. 克隆仓库

  ```bash
  git clone https://github.com/AkashiNeko/contact.git
  cd ./contact
  ```

  #### 2. 编译
  
  ```bash
  make
  ```
  或
  ```bash
  gcc *.c -o Contect -O3
  ```
  
  #### 3.运行
  
  ```bash
  ./Contect
  ```