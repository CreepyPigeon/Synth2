 #include <JuceHeader.h>
#include "OscComponent.h"

//==============================================================================
OscComponent::OscComponent(juce::AudioProcessorValueTreeState& apvts, juce::String waveSelectorId, juce::String fmFreqId, juce::String fmDepthId)
{
    juce::StringArray choices{
        "Sine", "Saw", "Square"
    };
    oscWaveSelector.addItemList(choices, 1);
    addAndMakeVisible(oscWaveSelector);
    oscWaveSelectorAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(apvts, waveSelectorId, oscWaveSelector);

    fmFreqSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    fmFreqSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 25);
    addAndMakeVisible(fmFreqSlider);

    fmFreqAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, fmFreqId, fmFreqSlider);

    fmFreqLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::white);
    fmFreqLabel.setJustificationType(juce::Justification::centred);
    fmFreqLabel.setFont(15.0f);
    addAndMakeVisible(fmFreqLabel);
}

OscComponent::~OscComponent()
{
}

void OscComponent::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::green);
    g.setColour(juce::Colours::white);
    g.drawRect(getLocalBounds());
}

void OscComponent::resized()
{
    oscWaveSelector.setBounds(0, 0, 90, 20);
    fmFreqSlider.setBounds(0, 80, 100, 90);
    fmFreqLabel.setBounds(fmFreqSlider.getX(), fmFreqSlider.getY() - 20, fmFreqSlider.getWidth(), 20);

}
