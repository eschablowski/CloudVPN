cmake_minimum_required(VERSION 2.6)
project(CloudVPN_entrypoint)
# The version number.
set(CloudVPN_VERSION_MAJOR 1)
set(CloudVPN_VERSION_MINOR 0)
set(OPENSSL_INCLUDE_DIR /usr/lib)

# configure a header file to pass some of the CMake settings to the source code
configure_file("${PROJECT_SOURCE_DIR}/include/CloudVPN.config.h.in"
               "${PROJECT_BINARY_DIR}/include/CloudVPN.config.h")
# add the binary tree to the search path for include files so that we will find
# TutorialConfig.h

set(cloudvpn_SRC
    "src/main.cpp"
    "src/base64.cpp"
    "src/Encryption/httpRequest.cpp"
    "src/Encryption/RequestToken.cpp"
    "src/Encryption/StreamEncoder.cpp"
    "src/Server/EndpointSocket.cpp"
    "src/Server/TCP.cpp")
add_executable(CloudVPN_entrypoint ${cloudvpn_SRC})
target_include_directories(CloudVPN_entrypoint PUBLIC "include" PRIVATE "src")

find_package(Boost REQUIRED)
find_package(CURL REQUIRED)

target_include_directories(CloudVPN_entrypoint
                           PRIVATE ${Boost_INCLUDE_DIRS} ${CURL_INCLUDE_DIRS})
target_link_libraries(CloudVPN_entrypoint ${Boost_LIBRARIES} ${CURL_LIBRARIES})


install(PROGRAMS CloudVPN_entrypoint DESTINATION bin)
