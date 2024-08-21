set(DOXYGEN_BUILTIN_STL_SUPPORT YES)
set(DOXYGEN_HTML_OUTPUT            ${PROJECT_BINARY_DIR}/docs/html)
set(DOXYGEN_JAVADOC_AUTOBRIEF      YES)
set(DOXYGEN_GENERATE_HTML          YES)
set(DOXYGEN_HAVE_DOT               YES)
set(DOXYGEN_USE_MDFILE_AS_MAINPAGE README.md)
set(DOXYGEN_EXTRACT_PRIVATE YES)

doxygen_add_docs(docs "${PROJECT_SOURCE_DIR}/README.md"
                 ${PROJECT_SOURCE_DIR}/include
                 COMMENT "Generate HTML documentation")

