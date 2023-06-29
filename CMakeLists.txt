cmake_minimum_required(VERSION 3.15)

project(THE_PLAYER
        VERSION 0.0.1
        DESCRIPTION "THE_PLAYER"
        LANGUAGES CXX)

add_subdirectory(Tools/JUCE-7.0.3 JUCE)

juce_add_gui_app(THE_PLAYER
        VERSION 0.0.1
        COMPANY_NAME Nesta
        PRODUCT_NAME "THE_PLAYER")

juce_generate_juce_header(THE_PLAYER)

target_sources(THE_PLAYER
        PRIVATE
        Source/Main.cpp
        Source/MainComponent.cpp)

target_compile_definitions(THE_PLAYER
        PRIVATE
        # JUCE_WEB_BROWSER and JUCE_USE_CURL would be on by default, but you might not need them.
        JUCE_WEB_BROWSER=0  # If you remove this, add `NEEDS_WEB_BROWSER TRUE` to the `juce_add_gui_app` call
        JUCE_USE_CURL=0     # If you remove this, add `NEEDS_CURL TRUE` to the `juce_add_gui_app` call
        JUCE_APPLICATION_NAME_STRING="$<TARGET_PROPERTY:THE_PLAYER,JUCE_PRODUCT_NAME>"
        JUCE_APPLICATION_VERSION_STRING="$<TARGET_PROPERTY:THE_PLAYER,JUCE_VERSION>"
        JUCE_PLUGINHOST_VST3=1)




target_link_libraries(THE_PLAYER
        PRIVATE
        # GuiAppData
        juce::juce_audio_basics
        juce::juce_gui_basics
        juce::juce_graphics
        juce::juce_audio_processors
        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
        juce::juce_recommended_lto_flags)

option(BUILD_UNIT_TESTS "Build JUCE prototype examples" ON)

#if (BUILD_UNIT_TESTS)
#    enable_testing()
#    add_subdirectory(Tests)
#endif()
