### CLI-based Music Player:

This project is for practicing c++ and its features.

### Dependencies:

Install zlib manually

macOS:
`brew install zlib`

Linux (Arch):
`sudo pacman -S zlib`

Ubuntu/Debian:
`sudo apt install zlib1g-dev`

### Goals:

Features to add:

- Add songs – Title, artist, genre, duration
- Display songs – All, by artist, or by genre
- Search – By title or artist
- Create playlist(s) – Save groups of songs
- Shuffle/Play simulation – Random order, track now playing
- Delete song – From library or playlist
- Save/load – Use file I/O to persist songs and playlists

# 1. First Target:

For now, I will focus on creating a simple text based interface to add, display, search, play and pause.

NOTES:

- First I will try to play files like WAV or AIFF which are lossless
