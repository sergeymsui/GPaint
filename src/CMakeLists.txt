
cmake_minimum_required(VERSION 3.24)
project(app)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        Svg
        REQUIRED)

list(APPEND HDR_PATHS
        GP_ApplicationWindow.h
        GP_Application.h
        GP_ActionGroupManager.h
        GP_ActionHandler.h
        GP_ActionFactory.h
        GP_WidgetFactory.h
        GP_global.h
        GP_global.h
        GP_CentralWidget.h
        GP_Document.h
        GP_TabWidget.h
        )

list(APPEND SRC_PATHS
        GP_ActionFactory.cpp
        GP_ActionHandler.cpp
        GP_ApplicationWindow.cpp
        GP_Application.cpp
        GP_ActionGroupManager.cpp
        GP_WidgetFactory.cpp
        GP_TabWindow.cpp
        GP_CentralWidget.cpp
        GP_TabWidget.cpp
        GP_Document.cpp
        )

list(APPEND RESOURCES
        ../data/icons.qrc
        )

qt6_add_resources(QRC_RESOURCES
        ${RESOURCES}
        )

message(STATUS "${QRC_RESOURCES}")

add_executable(app main.cpp ${HDR_PATHS} ${SRC_PATHS} ${QRC_RESOURCES})

target_link_libraries(app
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Svg
        )

if (WIN32)
    set(DEBUG_SUFFIX)
    if (MSVC AND CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB Core Gui Widgets)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()
