cmake_minimum_required(VERSION 3.14)

project(GUItestComOp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick QuickControls2 Network)

set(PROJECT_SOURCES
		source/main.cpp
		source/gui.h
		source/gui.cpp
		qml/qml.qrc

		source/d_open_protocol.cpp
		source/d_open_protocol_map.cpp
		source/d_open_protocol_mid.cpp
		mids/d_mid0001.cpp
		mids/d_mid0002.cpp
		mids/d_mid0003.cpp
		mids/d_mid0004.cpp
		mids/d_mid0005.cpp

		mids/d_mid0012.cpp
		mids/d_mid0013.cpp
		mids/d_mid0018.cpp

		mids/d_mid0030.cpp
		mids/d_mid0031.cpp
		mids/d_mid0032.cpp
		mids/d_mid0033.cpp
		mids/d_mid0034.cpp
		mids/d_mid0035.cpp
		mids/d_mid0036.cpp
		mids/d_mid0037.cpp
		mids/d_mid0038.cpp
		mids/d_mid0039.cpp

		mids/d_mid0040.cpp
		mids/d_mid0041.cpp
		mids/d_mid0042.cpp
		mids/d_mid0043.cpp

		mids/d_mid0060.cpp
		mids/d_mid0061.cpp
		mids/d_mid0062.cpp
		mids/d_mid0063.cpp

		mids/d_mid9999.cpp
		#test_connection.cpp
)

set(PROJECT_HEADERS
	include/d_open_protocol.h
	include/d_open_protocol_map.h
	include/d_open_protocol_mid.h
	include/d_open_protocol_factory.h
	include/d_open_protocol_factory_base.h
	mids/d_mid0001.h
	mids/d_mid0002.h
	mids/d_mid0003.h
	mids/d_mid0004.h
	mids/d_mid0005.h

	mids/d_mid0012.h
	mids/d_mid0013.h
	mids/d_mid0018.h

	mids/d_mid0030.h
	mids/d_mid0031.h
	mids/d_mid0032.h
	mids/d_mid0033.h
	mids/d_mid0034.h
	mids/d_mid0035.h
	mids/d_mid0036.h
	mids/d_mid0037.h
	mids/d_mid0038.h
	mids/d_mid0039.h

	mids/d_mid0040.h
	mids/d_mid0041.h
	mids/d_mid0042.h
	mids/d_mid0043.h

	mids/d_mid0060.h
	mids/d_mid0061.h
	mids/d_mid0062.h
	mids/d_mid0063.h

	mids/d_mid9999.h

	include/lib_open_protocol_global.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
	qt_add_executable(GUItestComOp
		MANUAL_FINALIZATION
		${PROJECT_SOURCES} ${PROJECT_HEADERS}
	)
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET GUItestComOp APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
	if(ANDROID)
		add_library(GUItestComOp SHARED
			${PROJECT_SOURCES} ${PROJECT_HEADERS}
		)
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
	else()
		add_executable(GUItestComOp
		  ${PROJECT_SOURCES} ${PROJECT_HEADERS}
		)
	endif()
endif()

target_compile_definitions(GUItestComOp
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
target_include_directories(GUItestComOp PRIVATE include/)
target_link_libraries(GUItestComOp
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::QuickControls2 Qt${QT_VERSION_MAJOR}::Network)

set_target_properties(GUItestComOp PROPERTIES
	MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
	MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
	MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
	MACOSX_BUNDLE TRUE
	WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
	qt_import_qml_plugins(GUItestComOp)
	qt_finalize_executable(GUItestComOp)
endif()
