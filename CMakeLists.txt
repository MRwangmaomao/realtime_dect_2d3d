cmake_minimum_required(VERSION 2.8.10)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE release CACHE STRING "Choose the type of build" FORCE)
endif()
add_compile_options(-std=c++11)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")  

project(dete_ncnn_3d)

# 寻找OpenCV库
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# 找到PCL

find_package(PCL REQUIRED)
include_directories( ${PCL_INCLUDE_DIRS} ) 
link_directories(${PCL_LIBRARY_DIRS})
add_definitions( ${PCL_DEFINITIONS} )
# 添加 ncnn头文件
include_directories(${CMAKE_SOURCE_DIR}/include/ncnn/include)

# 添加自定义类头文件
include_directories(${CMAKE_SOURCE_DIR}/include)

# 依赖库
set(libs 
${PCL_LIBRARIES} 
${OpenCV_LIBS} 
-lncnn
-fopenmp
)
 
# 生成可执行文件===== 
add_executable(${PROJECT_NAME} src/main.cpp src/XYZRGBPCViewer.cpp src/ncnn_dect.cpp src/mergeSG.cpp src/2d_3d_merge.cpp)
target_link_libraries(${PROJECT_NAME} ${libs})