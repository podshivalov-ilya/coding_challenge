project(agame_mech LANGUAGES CXX)

file(GLOB HEADERS *.hpp)
file(GLOB SOURCES *.cpp)

source_group("Headers" FILES ${HEADERS})
source_group("Sources" FILES ${SOURCES})

add_library(${PROJECT_NAME} STATIC ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

target_link_libraries(${PROJECT_NAME})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION lib)
