# 用于生成文档
find_package(Doxygen REQUIRED)

doxygen_add_docs(docs
    ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generate project documentation"
)