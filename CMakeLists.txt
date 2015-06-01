CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

PROJECT( QUICK2WIRE-C )

SET(QUICK2WIRE_SRC
  ${CMAKE_SOURCE_DIR}/src/gpio.cpp
  ${CMAKE_SOURCE_DIR}/src/board_revision.cpp
)

SET(DEMO_QUICK2WIRE_SRC
	${CMAKE_SOURCE_DIR}/src/gpio.cpp
	${CMAKE_SOURCE_DIR}/src/board_revision.cpp
	${CMAKE_SOURCE_DIR}/src/main.cpp
)

INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/include)


#ADD_LIBRARY( quick2wire_c SHARED ${QUICK2WIRE_SRC})

ADD_EXECUTABLE(quick2wire_demo ${DEMO_QUICK2WIRE_SRC})

#SET_TARGET_PROPERTIES( pam_mkpolohomedir PROPERTIES PREFIX "")
#TARGET_LINK_LIBRARIES( pam_mkpolohomedir ${PAM_LIBRARIES})
#TARGET_LINK_LIBRARIES( pam_mkpolohomedir ${OPENSSL_LIBRARIES})

#ADD_EXECUTABLE ( test_createdirs ${TEST_SRCS})
#TARGET_LINK_LIBRARIES(test_createdirs ${PAM_LIBRARIES})
#TARGET_LINK_LIBRARIES ( test_createdirs ${OPENSSL_LIBRARIES})

#find_package(RapidJSON)

#install(TARGETS pam_mkpolohomedir
#      DESTINATION /lib/security)
