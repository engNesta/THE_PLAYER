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

TEST_CASE("Test Input & Output audio processing")
{
    MainComponent mainComponent;

    constexpr int numSamples = 512;
    constexpr int numChannels = 2;

    juce::AudioBuffer<float> inputBuffer(numChannels, numSamples);
    juce::AudioBuffer<float> outputBuffer(numChannels, numSamples);

    juce::AudioSourceChannelInfo bufferInfo(&inputBuffer, 0, numSamples);



    mainComponent.getNextAudioBlock(bufferInfo);

    for (int channel = 0; channel < numChannels; ++channel)
    {
        const float* inputChannel = inputBuffer.getReadPointer(channel);
        const float* outputChannel = bufferInfo.buffer->getReadPointer(channel);

        for (int sample = 0; sample < numSamples; ++sample)
        {
            REQUIRE(inputChannel[sample] == (outputChannel[sample]));
        }
    }


}