#ifndef SINESYNTH_H
#define SINESYNTH_H

class LUT {
  protected:
    float *lut;

  public:
    LUT();
    int init(unsigned int n_samples);
    float getSample(unsigned int n);
};

class SineLUT : public LUT {
  public:
    SineLUT();
    int init(unsigned int n_samples);
};

class SineSynth {
  private:
    SineLUT *s;
    float fs;
    float freq;
    float head;
    float step;
    unsigned int resolution;

  public:
    SineSynth();
    int init(unsigned int n_resolution, float fs);
    int setFreq(float freq_hz);
    float getSample();
};
#endif
