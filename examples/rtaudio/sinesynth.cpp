#include <cmath>
#include "sinesynth.h"
#include <iostream>
#include <RtAudio.h>

LUT::LUT() {
}

float LUT::getSample(unsigned int n) {
  return this->lut[n];
}

SineLUT::SineLUT() {
}

int SineLUT::init(unsigned int n_samples) {

  const double PI = std::atan(1.0)*4;

  this->lut = new float[n_samples];

  for (int i=0; i<n_samples; i++) {
    this->lut[i] = (float)cos( (double) 2*PI*i/n_samples );
  }

  return n_samples;
}


SineSynth::SineSynth() {

}

//class SineSynth {
 // private:
   // SineLUT *s;

int SineSynth::init(unsigned int n_resolution, float fs) {
  this->s = new SineLUT();
  this->s->init(n_resolution);
  this->resolution = n_resolution;
  this->fs = fs;
  this->head = 0;
  return 1;
}

int SineSynth::setFreq(float freq_hz) {
  this->freq = freq_hz;
  this->step = this->freq * this->resolution / this->fs;
  return 1;
}

float SineSynth::getSample() {
  float ret = this->s->getSample( (int)head );
  this->head = (this->head + this->step);
  if (this->head >= this->resolution)
    this->head -= this->resolution;
  return ret;
}

