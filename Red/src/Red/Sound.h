///	@Sound.h
///	Sets up OpenAL audio and allows .ogg files to be played
/// Author: Karsten Pedersen

#ifndef _SOUND_H_
#define _SOUND_H_

#include <memory>
#include <string>

namespace RED
{
struct SoundImpl;

class Sound
{
	std::shared_ptr<SoundImpl> impl;
public:
	Sound();
	Sound(std::string path);
	void Load(std::string path);	//Load in audio file

	//Play sound
	void Play(float vol, float varMin, float varMax);
	void Play();
};
}
#endif //_SOUND_H_