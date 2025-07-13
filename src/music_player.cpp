#include "music_player.hpp"


MusicPlayer::MusicPlayer(const std::string& filepath) {
    // only using one playlist for now
    m_playlists.push_back(Playlist(filepath));
    if(!m_music.openFromFile(m_playlists[m_playlistIndex].getCurrentSong().getPath())) {
        return;
    }
}

void MusicPlayer::Play() {
    if (m_playlists.empty() || m_playlistIndex >= m_playlists.size()) return;
    if (m_music.getStatus() == sf::Music::Status::Paused || m_music.getStatus() == sf::Music::Status::Stopped) {
        m_music.play();
        m_music.setVolume(m_volume);
        m_music.setLoop(m_loopSong);
        m_playlists[m_playlistIndex].loopPlaylist(m_loopPlaylist);
    }
}
    

void MusicPlayer::Pause() {
    if (m_playlists.empty() || m_playlistIndex >= m_playlists.size()) return;
    if (m_music.getStatus() == sf::Music::Status::Playing) {
        m_music.pause();
    }
}

void MusicPlayer::Stop() {
    if (m_playlists.empty() || m_playlistIndex >= m_playlists.size()) return;
    if (m_music.getStatus() == sf::Music::Status::Playing || m_music.getStatus() == sf::Music::Status::Paused) {
        m_music.stop();
    }
}

void MusicPlayer::Previous() {
    if (m_playlists.empty() || m_playlistIndex >= m_playlists.size()) return;
    m_playlists[m_playlistIndex].gotoPreviousSong();
     if(!m_music.openFromFile(m_playlists[m_playlistIndex].getCurrentSong().getPath())) {
        return;
    }
    m_music.play();
}

void MusicPlayer::Next() {
    if (m_playlists.empty() || m_playlistIndex >= m_playlists.size()) return;
    m_playlists[m_playlistIndex].gotoNextSong();
     if(!m_music.openFromFile(m_playlists[m_playlistIndex].getCurrentSong().getPath())) {
        return;
    }
    m_music.play();
}

void MusicPlayer::VolumeUp(float val) {
    if (m_volume + val > 200) {
        return;
    }
    m_volume += val;
    m_music.setVolume(m_volume);
}

void MusicPlayer::VolumeDown(float val) {
    if (m_volume - val < 0) {
        return;
    }
    m_volume -= val;
    m_music.setVolume(m_volume);
}

bool MusicPlayer::LoopSong(bool loop) {
    m_loopSong = loop;
    m_music.setLoop(m_loopSong);
    return m_loopSong;
}

bool MusicPlayer::LoopPlaylist(bool loop) {
    m_loopPlaylist = loop;
    m_playlists[m_playlistIndex].loopPlaylist(m_loopPlaylist);
    return m_loopPlaylist;
}

float MusicPlayer::getSongVolume() const{
    return m_music.getVolume();
}

MusicPlayer::Status MusicPlayer::getStatus() const {
    switch (m_music.getStatus()) {
        case sf::SoundSource::Status::Playing:
            return Status::Playing;
        case sf::SoundSource::Status::Paused:
            return Status::Paused;
        case sf::SoundSource::Status::Stopped:
        default:
            return Status::Stopped;
    }
}

Song MusicPlayer::getCurrentSong() const {
    return m_playlists[m_playlistIndex].getCurrentSong();
}

Song MusicPlayer::getNextSong() const {
    return m_playlists[m_playlistIndex].getNextSong();
}

Song MusicPlayer::getPreviousSong() const {
    return m_playlists[m_playlistIndex].getPreviousSong();
}

Playlist MusicPlayer::getPlaylist() const {
    return m_playlists[m_playlistIndex];
}