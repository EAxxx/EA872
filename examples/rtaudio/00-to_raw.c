
#include <stdio.h>
#include <stdint.h>


int main() {
  FILE *pipein, *wout;
  int16_t buffer;
  float output;

  pipein = popen("ffmpeg -i assets/blip.wav -f s16le -ac 1 -ar 44100 -", "r");
  wout = fopen("assets/blip.dat", "w");

  int count, n=0;
  while (1) {
    count = fread(&buffer, 2, 1, pipein);
    if (count != 1) break;
    output = buffer / (float)32767; /* Scale INT output to a float in range [-1, 1] */
    fprintf(wout, "%f\n", output);
  }

  pclose(pipein);
  fclose(wout);
  return 0;
}
