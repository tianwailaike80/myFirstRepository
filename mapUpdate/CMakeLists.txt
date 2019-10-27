# CMake最低版本要求，如果低于3.10.1版本，则构建过程会被终止
cmake_minimum_required(VERSION 3.10.1)

# 项目信息  
project(xynsln3)

# 添加头文件目录
include_directories(tinyxml)

# 查找当前目录下的所有源文件，并将名称保存到DIR_SRCS变量中
aux_source_directory(mapUpdate DIR_SRCS)

# 指定生成目标
add_executable(xynexe3 ${DIR_SRCS})

# 添加math子目录
add_subdirectory(tinyxml)

# 添加链接库
target_link_libraries(xynexe3 lib_tinyxml)
