// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <algorithm>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    // This function should display 
    // Playing: followed by the song that is playing
   std::cout << "Current song: " << std::endl;
    std::cout << song << std::endl;
    std::cout << "You implement this function"<< std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    // This function should display the current playlist 
    // and then the current song playing.
    for(const auto &obj: playlist)
        std::cout << obj << std::endl;
    std::cout << "Current song: " << std::endl;
    std::cout << current_song << std::endl;
    //std::cout << std::endl;
}

int main() {

    std::list<Song> playlist{
            {"God's Plan",        "Drake",                     5},
            {"Never Be The Same", "Camila Cabello",            5},
            {"Pray For Me",       "The Weekend and K. Lamar",  4},
            {"The Middle",        "Zedd, Maren Morris & Grey", 5},
            {"Wait",              "Maroone 5",                 4},
            {"Whatever It Takes", "Imagine Dragons",           3}          
    };
    
    std::list<Song>::iterator current_song = playlist.begin();

    // Your program logic goes here
    char choice {};
    std::string song_name {};
    std::string song_artist {};
    int song_rating {};
    do {
        if (choice == 'F' || choice =='f') {
            std::cout << "Playing first song" << std::endl;
            current_song = playlist.begin();
        }
        else if (choice == 'N' || choice == 'n') {
            std::cout << "Playing next song" << std::endl;
            current_song++;
            if (current_song == playlist.end()) {
                current_song = playlist.begin();
            }
                
        }
        else if (choice == 'P' || choice == 'p') {
            std::cout << "Playing pervious song" << std::endl;
            if (current_song == playlist.begin()) 
                current_song = playlist.end();
            current_song--;
        }
        else if (choice == 'A' || choice == 'a') {
            std::cout << "Adding song " << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            std::cout << "Enter song name: ";
            getline(std::cin, song_name);
            std::cout << "\nEnter song artist: ";
            getline(std::cin, song_artist);
            std::cout << "Enter song ratign: ";
            std::cin >> song_rating;
            playlist.emplace(current_song, song_name, song_artist, song_rating);
            current_song--;
        }
        else if (choice == 'l' || choice == 'L')
            std::cout << "Listing current playlist" << std::endl;
        else
            std::cout << "Invalid choice" << std::endl;
            
        display_playlist(playlist, *current_song);
        display_menu();
        std::cin >> choice;
    }
    while (choice != 'Q' && choice != 'q');
    

    std::cout << "Thanks for listening!" << std::endl;
    return 0;
}