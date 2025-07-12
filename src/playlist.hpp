#pragma once
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include "song.hpp"

class Playlist {
    public:
        Playlist(const std::string& filepath);
        void displayInfo() const;
        std::string getPath(int index) const;
        std::string getPath(Song song) const;
        Song getCurrentSong() const;
        Song getPreviousSong() const;
        Song getNextSong() const;
        int getPlaylistSize() const;
        void gotoNextSong();
        void gotoPreviousSong();
        void enableLoopPlaylist();
        
    private:
        std::vector<Song> m_songs;
        int m_songIndex = 0;
        bool m_loopPlaylist = false;

};