#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "song.hpp"
#include "playlist.hpp"


class MusicPlayer {
    public:
        MusicPlayer();

        void Play();
        void Pause();
        void Stop();
        void Previous();
        void Next();
        void VolumeUp();
        void VolumeDown();
        void LoopSong(bool loop);
        void LoopPlaylist(bool loop);

        void CreatePlaylist();
        void AddSong();
        void RemoveSong();
        void ShufflePlaylist();
    private:
        std::vector<std::string> m_songPaths;
        std::size_t m_currentIndex;
        sf::Music m_music;
        bool m_loop;

        void PlayCurrentSong();
};



int main() {
    Song song = Song("assets/music/output.wav");
    song.displayInfo();
    std::cout << "\n";


    Playlist playlist = Playlist("assets/music/");
    playlist.displayInfo();
    std::cout << "\n";

    sf::Music music;
    // for (int i = 0; i < playlist.getPlaylistSize(); i++) {
        
    // }

    // file should be .ogg or .wav
    if (!music.openFromFile(playlist.getNextSong().getPath())) {
        std::cerr << "❌ Failed to load 'song.wav'\n";
        return 1;
    }
    music.play();
    
    int input = 0;
    float volume = 100;
    music.setLooping(true);

    while (true) {
    std::cout << "🎵🎵 MUSIC PLAYER 🎵🎵:\n";
    std::cout << "1. To Stop Playing input 1\n";
    std::cout << "2. To Pause Playing input 2\n";
    std::cout << "3. To Start/Resume Playing input 3\n";
    std::cout << "4. To Increase Volume input 4\n";
    std::cout << "5. To Decrease Volume input 5\n";
    std::cout << "Input: ";
    
    std::cin >> input;

    switch(input) {
        case 1:
            music.stop();
            std::cout << "\n🛑 Playback stopped.\n\n";
            break;
        case 2:
            music.pause();
            std:: cout <<"\n⏸️  Now paused\n\n";
            break;
        case 3:
            music.play();
            music.setVolume(volume);
            std::cout << "\n▶️  Now playing.\n\n";
            break;
        case 4:
            volume = volume + 10.0;
            music.setVolume(volume);
            std::cout << "\nVolume increased to: " << volume << "\n\n";
            break;
        case 5:
            volume = volume - 10.0;
            music.setVolume(volume);
            std::cout << "\nVolume decreased to: " << volume << "\n\n";
            break;
    }
    // std::cin.get();  // Wait for user input
    // music.stop();
    // std::cout << "🛑 Playback stopped.\n";
    input = 0;
    }
    

    return 0;
}
