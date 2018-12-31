include_directories(..)

add_executable(Grawler Grawler)
target_link_libraries(Grawler GSTL ApolloEngine pthread)