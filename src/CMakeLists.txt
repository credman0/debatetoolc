qt5_add_resources(debatetool_SRCS resources.qrc)

add_executable(debatetool main.cpp ${debatetool_SRCS})
add_subdirectory(core)
add_subdirectory(google-diff-match-patch)
target_link_libraries(debatetool 
    PUBLIC
        Qt5::Qml 
        Qt5::Gui 
        Qt5::Core)
