cmake_minimum_required(VERSION 3.27)
project(RSA)

set(CMAKE_CXX_STANDARD 23)

# Добавляем исполняемый файл и указываем все исходные файлы, включая папку BIGINT
add_executable(RSA main.cpp RSA.cpp RSA.h Utils.h)

# Добавляем все файлы из папки BIGINT
file(GLOB BIGINT_FILES "BIGINT/*.cc" "BIGINT/*.hh")

# Включаем найденные файлы в проект
target_sources(RSA PRIVATE ${BIGINT_FILES})
