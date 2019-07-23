qt5_add_resources(debatetool_SRCS resources.qrc)
add_executable(debatetool main.cpp ${debatetool_SRCS})
target_link_libraries(debatetool Qt5::Qml Qt5::Gui)

