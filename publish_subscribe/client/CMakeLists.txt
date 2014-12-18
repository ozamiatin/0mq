project(zmq_client)

#add_executable (${PROJECT_NAME} client.c)
add_executable (${PROJECT_NAME} broadcast_sub.c)

target_link_libraries(${PROJECT_NAME} -lzmq)
