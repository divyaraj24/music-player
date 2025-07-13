#include <SFML/Audio.hpp>
#include <iostream>
#include "music_player.hpp"
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>


int main() {
    // using namespace ftxui;
    //     Element document = hbox({
    //     text("left")   | border,
    //     text("middle") | border | flex,
    //     text("right")  | border,
    // });

    // auto screen = Screen::Create(Dimension::Full(), Dimension::Fit(document));
    // Render(screen, document);
    // screen.Print();



    MusicPlayer mp = MusicPlayer("assets/music/");
    mp.Play();
    mp.LoopPlaylist(true);
    
    int input = 0;

    while (true) {
        mp.getCurrentSong().displayInfo();
        
        if(mp.getStatus() == MusicPlayer::Status::Playing) {
            std::cout << "\n▶️  Now playing.\n\n";
        }
        else if (mp.getStatus() == MusicPlayer::Status::Paused) {
            std:: cout <<"\n⏸️  Now paused\n\n";
        }
        else {
            std::cout << "\n🛑 Playback stopped.\n\n";
        }
        

        std::cout << "🎵🎵 MUSIC PLAYER 🎵🎵:\n";
        std::cout << "1. To Stop Playing input 1\n";
        std::cout << "2. To Pause Playing input 2\n";
        std::cout << "3. To Start/Resume Playing input 3\n";
        std::cout << "4. To Increase Volume input 4\n";
        std::cout << "5. To Decrease Volume input 5\n";
        std::cout << "6. To go to next song input 6\n";
        std::cout << "7. To go to previous song input 7\n";
        std::cout << "8. To exit input 0\n";
        std::cout << "Input: ";
        
        std::cin >> input;

        switch(input) {
            case 0:
                std::cout << "Exiting the music player...\n";
                return 0;
                break;
            case 1:
                mp.Stop();
                
                break;
            case 2:
                mp.Pause();
                
                break;
            case 3:
                mp.Play();
                break;
            case 4:
                mp.VolumeUp(10.0);
                std::cout << "\nVolume increased to: " << mp.getSongVolume()<< "\n\n";
                break;
            case 5:
                mp.VolumeDown(10.0);
                std::cout << "\nVolume decreased to: " << mp.getSongVolume()<< "\n\n";
                break;
            case 6:
                mp.Next();
                break;
            case 7:
                mp.Previous();
                break;
        }
        input = 0;
    }
    

    return 0;
}
