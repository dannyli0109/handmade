/* date = March 29th 2021 2:45 pm */

#ifndef HANDMADE_H
#define HANDMADE_H

struct game_offscreen_buffer
{
    void *Memory;
    int Width;
    int Height;
    int Pitch;
    int BytesPerPixel;
};

struct game_sound_buffer
{
    int SamplesPerSecond;
    int SampleCount;
    int16* Samples;
    
};

internal void GameUpdateAndRender(game_offscreen_buffer* Buffer, game_sound_buffer* SoundBuffer);

#endif //HANDMADE_H
