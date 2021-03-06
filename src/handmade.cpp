#include "handmade.h"

internal void RenderWeirdGradient(game_offscreen_buffer* Buffer)
{
    uint8* Row = (uint8*)Buffer->Memory;
    for (int Y = 0; Y < Buffer->Height; ++Y)
    {
        uint32* Pixel = (uint32*)Row;
        for (int X = 0; X < Buffer->Width; ++X)
        {
            uint8 Blue = X;
            uint8 Green = Y;
            
            *Pixel++ = ((Green << 8) | Blue);
        }
        Row += Buffer->Pitch;
    }
}


internal void GameOutputSound(game_sound_buffer* SoundBuffer) 
{
    local_persist real32 tSine;
    int16 ToneVolume = 3000;
    int ToneHz = 256;
    int WavePeriod = SoundBuffer->SamplesPerSecond / ToneHz;
    int16* SampleOut = SoundBuffer->Samples;
    for (int SampleIndex = 0; SampleIndex < SoundBuffer->SampleCount; SampleIndex++)
    {
        real32 SineValue = sinf(tSine);
        int16 SampleValue = (int16)(SineValue * ToneVolume);
        *SampleOut++ = SampleValue;
        *SampleOut++ = SampleValue;
        tSine += 2.0f * Pi32 * 1.0f / (real32)WavePeriod;
    }
}

internal void GameUpdateAndRender(game_offscreen_buffer* Buffer, game_sound_buffer* SoundBuffer)
{
    local_persist int BlueOffset = 0;
    local_persist int GreenOffset = 0;
    local_persist int ToneHz = 256;
    GameOutputSound(SoundBuffer);
    RenderWeirdGradient(Buffer);
}