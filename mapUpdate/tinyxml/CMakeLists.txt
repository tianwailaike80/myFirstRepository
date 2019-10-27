# CMake最低版本要求，如果低于3.10.1版本，则构建过程会被终止 
cmake_minimum_required(VERSION 3.10.1)

# 查找当前目录下的所有源文件，并将名称保存到DIR_LIB_DIVIDE_SRCS变量中
aux_source_directory(. DIR_LIB_TINYXML_SRCS)

# 指定生成目标
add_library(lib_tinyxml ${DIR_LIB_TINYXML_SRCS})
