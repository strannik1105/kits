cmake_minimum_required(VERSION 3.10)

project(kits)

set(SOURCES 
    main.cpp
    common/document_reader.cpp
    common/txt_document_reader.cpp
    kits/kit.cpp
    kits/kits_finder.cpp
    kits/receipt.cpp
)


add_executable(kits ${SOURCES})

target_include_directories(kits
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/include
)