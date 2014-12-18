project(zmq_server)

#add_executable (zmq_server server.c)
add_executable (zmq_server broadcast_pub.c)

target_link_libraries(${PROJECT_NAME} -lzmq)

