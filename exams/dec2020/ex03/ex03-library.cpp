#include <iostream>
#include "ex03-library.h"
using namespace std;

// Do not modify
SongDatabase::SongDatabase() {
    this->songs.push_back("Penny Lane");
    this->songsInfo["Penny Lane"] = {"https://youtu.be/S-rB0pHI9fU", 8};

    this->songs.push_back("Trololo");
    this->songsInfo["Trololo"] = {"https://youtu.be/oavMtUWDBTM", 10};

    this->songs.push_back("Ob-La-Di, Ob-La-Da");
    this->songsInfo["Ob-La-Di, Ob-La-Da"] = {"https://youtu.be/_J9NpHKrKMw", 2};

    this->songs.push_back("Don't Worry, Be Happy");
    this->songsInfo["Don't Worry, Be Happy"] = {"https://youtu.be/d-diB65scQU", 3};

    this->songs.push_back("Leave My Kitten Alone");
    this->songsInfo["Leave My Kitten Alone"] = {"https://youtu.be/7BKsy9-Bvok", 5};
}

// Task 3(a).  Implement this method
void SongDatabase::display() {
    for(string s : this->songs) {
        auto it = this->songsInfo.find(s);
        string url = it->second.url;
        unsigned int score = it->second.score;
        string line = "title=" + s + ";" + " url=" + url + ";" + " score=";
        cout << line << score << endl;
    }
    /* ITERATE MAP */
    // for(auto it = this->songsInfo.begin(); it != this->songsInfo.end(); it++){
    //     // cout << this->songsInfo[it]->first << endl;
    //     cout << it->first << endl;
    // }
    // for (auto const& x: this->songsInfo){
    //     cout << x.first << endl;
    // }
}

// Task 3(b).  Implement this method
bool SongDatabase::addSong(string title, string url, unsigned int score) {
    // Look if alrady present
    auto it = this->songsInfo.find(title);
    if (it != this->songsInfo.end())
        return false;
    
    if (score > 10)
        return false;

    this->songs.push_back(title);
    this->songsInfo.insert({title, Info {url,score}});
    return true;

}

// Task 3(a).  Implement this method
void SongDatabase::searchSongs(string howGood) {
    if (howGood.empty())
        return;

    int minScore, maxScore;
    if (howGood == "abysmal") {
        minScore = 0;
        maxScore = 3;
    }
    else if (howGood == "lousy"){
        minScore = 3;
        maxScore = 5;
    }
    else if (howGood == "meh"){
        minScore = 5;
        maxScore = 7;
    }
    else if (howGood == "cool"){
        minScore = 7;
        maxScore = 9;
    }
    else {
        minScore = 9;
        maxScore = 11;
    }

    for(string s : this->songs) {
        auto it = this->songsInfo.find(s);
        if (minScore <= it->second.score && it->second.score < maxScore) {
            string url = it->second.url;
            unsigned int score = it->second.score;
            string line = "title=" + s + ";" + " url=" + url +";" +  " score=";
            cout << line << score << endl;
        }
    }

}
