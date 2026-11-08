#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

struct Song {
    string artist;
    string title;
    double streams;
};

int main() {
  ifstream inputFile("data.csv");
  vector<Song> songs;
  string header;
  Song currentSong;

  if (!inputFile.is_open()) {
    cout << "Could not open file." << endl;
    return 1;
  }

  inputFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


  while (getline(inputFile, currentSong.artist, ',')) {
    getline(inputFile, currentSong.title, ',');
    inputFile >> currentSong.streams;
    inputFile.ignore();
    songs.push_back(currentSong);
  }

  inputFile.close();

  for (Song song : songs) {
    cout << song.artist << " by " << song.title << ": " << song.streams << " billion streams\n";
  }

  return 0;
}