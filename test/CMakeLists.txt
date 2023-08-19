include(CTest)

create_test_sourcelist(Tests
    CommonCppTests.cpp
    ip/v4.cpp
)

add_executable(CommonCppTests ${Tests})
target_link_libraries(CommonCppTests PRIVATE ElementsParser)

set(TestsToRun ${Tests})
remove(TestsToRun CommonCppTests.cpp)

foreach(test ${TestsToRun})
    get_filename_component(TName ${test} NAME_WE)
    add_test(NAME ${TName} COMMAND CommonCppTests ${TName})
endforeach()

