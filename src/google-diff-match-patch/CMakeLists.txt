add_library(googledmp diff_match_patch.cpp)
target_link_libraries(googledmp 
    PRIVATE
        Qt5::Qml 
        Qt5::Gui 
        Qt5::Core)

target_link_libraries(debatetool 
    PUBLIC
        googledmp)
