#include <SFML/Audio.hpp>
#include "playlist.hpp"
#include "song.hpp"
#include <string>
#include <vector>

class MusicPlayer {
    public:
        MusicPlayer(const std::string& filepath);

        enum class Status {
            Stopped,
            Paused,
            Playing
        };

        void Play();
        void Pause();
        void Stop();
        void Previous();
        void Next();
        void VolumeUp(float val);
        void VolumeDown(float val);
        bool LoopSong(bool loop);
        bool LoopPlaylist(bool loop);

        // Getting song, playlist and other information...
        float getSongVolume() const;
        Status getStatus() const;
        Song getCurrentSong() const;
        Song getNextSong() const;
        Song getPreviousSong() const;
        Playlist getPlaylist() const;

    private:
        std::vector<Playlist> m_playlists;
        sf::Music m_music;
        int m_playlistIndex = 0;
        float m_volume = 100;
        bool m_loopPlaylist = true;
        bool m_loopSong = false;
};

