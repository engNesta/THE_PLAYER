//
// Created by Nesta on 2023-06-30.
//
#define CATCH_CONFIG_MAIN
#include "../Source/MainComponent.h"
#include <juce_core/juce_core.h>
#include <juce_graphics/juce_graphics.h>
#include <juce_gui_basics/juce_gui_basics.h>
#include <juce_audio_processors/juce_audio_processors.h>
#include "Catch2/src/catch2/catch_test_macros.hpp"
//REMEMBER TO CALL THE JUCE NAMESPACE WHEN USING JUCE CLASSES

TEST_CASE("Suite implemented")
{
    MainComponent mainComponent;
}