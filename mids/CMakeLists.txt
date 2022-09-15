# ========================================================
# Project specific
# ========================================================
set(PROJECT_HEADERS
	include/d_mid0001.h
	include/d_mid0002.h
	include/d_mid9999.h
PARENT_SCOPE)

set(PROJECT_SOURCES
	source/d_mid0001.cpp
	source/d_mid0002.cpp
	source/d_mid9999.cpp
PARENT_SCOPE)

message("Hello ${PROJECT_SOURCES}")
