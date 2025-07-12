#pragma once
#include <string>
#include <taglib/fileref.h>
#include <taglib/tag.h>
#include <taglib/audioproperties.h>
#include <iostream>

class Song {
    public:
        Song(const std::string& filepath);

        std::string getTitle() const;
        std::string getArtist() const;
        float getDuration() const;
        std::string getPath() const;

        void displayInfo() const;

    private:
        std::string m_path;
        std::string m_title;
        std::string m_artist;
        float m_duration;
};
