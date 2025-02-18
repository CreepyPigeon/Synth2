#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Synth2AudioProcessorEditor::Synth2AudioProcessorEditor (Synth2AudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
    osc(audioProcessor.apvts, "OSC1WAVETYPE", "OSC1FMFREQ", "OSC1FMDEPTH"),
    adsr(audioProcessor.apvts), filter(audioProcessor.apvts, "FILTERTYPE", "FILTERCUTOFF", "FILTERRES")
{
    setSize (500, 400);
    addAndMakeVisible(osc);
    addAndMakeVisible(adsr);
    addAndMakeVisible(filter);
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
    osc.setBounds(10, 10, getWidth() / 2, getHeight() / 2);
    adsr.setBounds(osc.getRight(), 10, getWidth() / 2, getHeight() / 2);
    filter.setBounds(10, getHeight() / 2, getWidth() / 2, getHeight()/2);
}