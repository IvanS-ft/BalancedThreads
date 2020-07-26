configure_file(Config.h.in Config.h)

add_library(BalancedThreads 
    BalancedThreads.c
    Context.c
    Error.c
    Handout.c
    Lock.c
    OSDependent.c
    Thread.c
    Timer.c
)

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})