#include "playlist.hpp"


/*Add code to handle cases where playlist is empty or previous song is not available later...*/

namespace fs = std::filesystem;

Playlist::Playlist(const std::string& filepath) {
    for (const auto & entry : fs::directory_iterator(filepath)) {
        if (entry.is_regular_file()) {
            std::string ext = entry.path().extension().string();
            if (ext == ".mp3" || ext == ".flac" || ext == ".ogg" || ext == ".wav") {
                m_songs.push_back(Song(entry.path().string()));
            }
        }
    }
}

void Playlist::gotoNextSong() {
    if(m_songIndex + 1 < m_songs.size()) {
        m_songIndex++;
    }
    else if(m_loopPlaylist && !m_songs.empty()) {
        m_songIndex = 0;
    }
}

void Playlist::gotoPreviousSong() {
    if (m_songIndex > 0) {
        m_songIndex--;
    }
    else if(m_loopPlaylist && !m_songs.empty()) {
        m_songIndex = m_songs.size() - 1;
    }
}

std::string Playlist::getPath(int index) const {return m_songs[index].getPath();}
std::string Playlist::getPath(Song song) const {return song.getPath();}
Song Playlist::getCurrentSong() const {return m_songs.empty() ? Song("") : m_songs[m_songIndex];}
Song Playlist::getNextSong() const {
    if(m_songIndex + 1 < m_songs.size()) {
        return m_songs[m_songIndex + 1];
    }
    else if(m_loopPlaylist && !m_songs.empty()) {
        return m_songs[0];
    }
    return Song("");
}
Song Playlist::getPreviousSong() const {
     if (m_songIndex > 0) {
        return m_songs[m_songIndex - 1];
    }
    else if(m_loopPlaylist && !m_songs.empty()) {
        return m_songs[m_songs.size() - 1];
    }
    return Song("");
}

int Playlist::getPlaylistSize() const {return m_songs.size();}

void Playlist::enableLoopPlaylist() {m_loopPlaylist = true;}

void Playlist::displayInfo() const {
    std::cout << "Songs in the playlist: \n";
    for (std::size_t i = 0; i < m_songs.size(); i++) {
        std::cout << i + 1 << ". ";
        m_songs[i].displayInfo();
    }
}
