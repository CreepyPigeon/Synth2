#include "OscData.h"

void OscData::setWaveType(const int choice) {
    //juce::dsp::Oscillator<float> osc{ [](float x) {return std::sin(x); }, 200 }; // sine
//juce::dsp::Oscillator<float> osc{ [](float x) {return x / juce::MathConstants<float>::pi; }, 201 }; // saw
//juce::dsp::Oscillator<float> osc{ [](float x) {return x < 0.0f ? -1.0f : 1.0f; }}; // square
    juce::dsp::Oscillator<float> osc{ [](float x) { return x / juce::MathConstants<float>::pi; } };

    switch (choice) {
    case 0:  // sine wave
        initialise([](float x) { return std::sin(x); });
        break;
    case 1:  // saw wave
        initialise([](float x) {return x / juce::MathConstants<float>::pi; });
        break;
    case 2:  // square wave
        initialise([](float x) {return x < 0.0f ? -1.0f : 1.0f; });
        break;
    default:
        jassertfalse;  // something failed
        break;
    }

}