#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Synth2AudioProcessorEditor::Synth2AudioProcessorEditor (Synth2AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),osc(audioProcessor.apvts, "OSC1WAVETYPE", "OSC1FMFREQ", "OSC1FMDEPTH"), adsr(audioProcessor.apvts)
{
    setSize (500, 400);
    addAndMakeVisible(osc);
    addAndMakeVisible(adsr);
}

Synth2AudioProcessorEditor::~Synth2AudioProcessorEditor()
{
}

//==============================================================================
void Synth2AudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll(juce::Colours::black);

}

void Synth2AudioProcessorEditor::resized()
{
    osc.setBounds(10, 10, 175, 200);
    adsr.setBounds(getWidth()/2, 0, getWidth()/2, getHeight());
}