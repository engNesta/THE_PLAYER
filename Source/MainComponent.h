#pragma once

#include <JuceHeader.h>

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/

class MyMidiInputCallback : public juce::MidiInputCallback
{
public:
    void handleIncomingMidiMessage(juce::MidiInput* source, const juce::MidiMessage& message) override;
};

class MainComponent  : public juce::AudioAppComponent, public juce::Button::Listener, public juce::ComboBox::Listener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;

    //==============================================================================
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo& bufferToFill) override;
    void releaseResources() override;



    //==============================================================================

    juce::TextButton loadButton;
    juce::Label infoLabel;
    juce::ComboBox midiDeviceComboBox;





    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    void buttonClicked(juce::Button *button) override;
    void loadFile();
    void retrieveVST3data(juce::File &file);
    void hostVST3(juce::File &file);
    void createEditor(AudioPluginInstance& pluginInstance);
    std::unique_ptr<AudioPluginInstance> vst3Instance;
    void comboBoxChanged(juce::ComboBox* comboBox) override;


private:
    //==============================================================================
    // Your private member variables go here...
    std::unique_ptr<juce::FileChooser> fileChooser;
    juce::AudioPluginFormatManager formatManager;
    PluginDescription vst3Description;
    juce::MidiInput midiInput;
    MyMidiInputCallback midiInputCallback;





    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

