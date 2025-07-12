#include <SFML/Audio.hpp>
#include <iostream>

int main() {
    sf::Music music;

    // Try loading an audio file (make sure song.ogg is in the same directory)
    if (!music.openFromFile("song.wav")) {
        std::cerr << "❌ Failed to load 'song.wav'\n";
        return 1;
    }

    std::cout << "🎵 Now playing 'song.ogg'. Press Enter to stop...\n";
    music.play();

    std::cin.get();  // Wait for user input

    music.stop();
    std::cout << "🛑 Playback stopped.\n";

    return 0;
}
