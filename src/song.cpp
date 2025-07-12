#include "song.hpp"

Song::Song(const std::string& filepath):m_path(filepath), m_title("Unknown"), m_artist("Unknown"), m_duration(0.0f){
    TagLib::FileRef file(filepath.c_str());
    if(!file.isNull() && file.tag()) {
        m_title  = file.tag()->title().to8Bit(true);
        m_artist = file.tag()->artist().to8Bit(true);
    }
    if (file.audioProperties()) {
        
        m_duration = file.audioProperties()->lengthInSeconds();
    }
}

std::string Song::getTitle() const { return m_title; }
std::string Song::getArtist() const { return m_artist; }
float Song::getDuration() const { return m_duration; }
std::string Song::getPath() const { return m_path; }

void Song::displayInfo() const {
    // add dunction to properly calculate time from seconds later (for hours..)
    std::cout << "🎵 Playing: " << m_title << " by " << m_artist << " [Duration: " << (int)m_duration/60 << ":" << ((int)m_duration%60) << "] Path: " << m_path << std::endl;
}
