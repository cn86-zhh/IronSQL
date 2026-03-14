# WELCOME TO SRC/INCLUDE/\*.HPP README FILE

- ## 1 `./src/include/*.hpp`
  - 这个目录只能包含来自于`.src/library/*.cpp`的实现申明.
  - 这样做是因为, `./src/library/*.cpp` 是库文件的实现, 而 `./src/include/*.hpp` 是库文件的申明. 库文件存在大量的代码与文件, 为了方便管理, 我将库文件的申明与实现分离开来.
  - 这样做可能让人费解, 或者'操蛋'.
  - 其他的文件目录都是一个独立的模块, 方便拆解与堆叠. 而库文件是一个集合体, 体积相对较大.
