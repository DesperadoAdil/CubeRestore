## 3阶魔方还原程序
2019/5/14  [返回](https://desperadoadil.github.io/)

---
### 输入：  
按照 前 后 右 左 上 下 的顺序输入魔方六个面的状态  
输入样例为 codes/cube.in  
- 红色用 R 表示
- 绿色用 G 表示
- 蓝色用 B 表示
- 橙色用 O 表示
- 白色用 W 表示
- 黄色用 Y 表示

### 输出：  
输出还原魔方的[辛马斯特标记](https://baike.baidu.com/item/辛马斯特标记)序列  
输出文件为 codes/cube.out

编译运行：  
```
> g++ -o cube.exe cube.cpp
> ./cube.exe
```

批量测试：(需要先生成cube.exe)  
```
g++ -o test.exe test.cpp
> ./test.exe
```

**感谢[LO-Yang](https://github.com/LO-Yang)和Junliang Li的共同开发**
