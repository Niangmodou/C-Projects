#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Playlist{
private:
    vector<string>songList;
    
public:
    void add_song(string songName){
        songList.push_back(songName);
    }
    
    void add_song_after(string song_name,string new_song_name){
        bool contains = inList(song_name);
        if (contains){
            int ind = 0;
            
            for (int i = 0; i < songList.size(); i++){
                if (songList.at(i) == song_name){
                    ind = i;
                }
            }
            
            auto itPos = songList.begin()+ind+1;
            songList.insert(itPos, new_song_name);
        }else{
            cout << "Song Not in list"<<endl;
        }
        
    }
    
    bool inList(string song_name){
        for(int i = 0; i < songList.size(); i++){
            if(songList.at(i) == song_name){
                return true;
            }
        }
        return false;
    }
    
    void play_song(string song_name){
        bool contains = inList(song_name);
        if (!contains){
            cout<< "Song is Not in List" << endl;
        }else{
            cout << "Playing: "<<song_name<<endl;
        }
    }
    
    void play_list(){
        for (int i = 0 ; i < songList.size(); i++){
            cout << "Playing: " << songList.at(i) << endl;
        }
    }
    void shuffle(){
        vector<string>newList;
        int num;
        
        srand(time(NULL));
        
        
        while (newList.size() != songList.size()){
            
            num = (rand() % songList.size());
            string song = songList.at(num);
            
            if (find(newList.begin(),newList.end(),song) == newList.end()){
                newList.push_back(song);
            }
        }
        
        this->songList = newList;
    }
    
    
};

void intro(){
    cout << "WELCOME TO MO'S PLAYLIST" << endl;
    cout << "I will add my favorite songs in a playlist and play them for you" << endl;
    
    cout << "" << endl;
    cout << "----------------------------------------------" << endl;
}

void close(){
    cout << "--------------------------------------------" << endl;
    cout << "As you can see I love Travis Scott" << endl;
    cout << "Hope you enjoyed!" << endl;
}

int main(){
    
    intro();
    
    Playlist pl;
    pl.add_song("Wit It");
    pl.add_song("STARGAZING");
    pl.add_song("The London");
    pl.add_song("RIP SCREW");
    pl.add_song("WAKE UP");
    pl.add_song("NO BYSTANDERS");
    pl.add_song("SICKO MODE");
    pl.add_song("COFFEE BEAN");
    pl.add_song_after("STARGAZING", "YOSEMITE");
    pl.add_song_after("RIP SCREW", "NC-17");
    pl.add_song("SKELETONS");
    pl.play_list();
    pl.shuffle();
    
    cout << "" << endl;
    cout << "SHUFFLED =====================" << endl;
    cout << "" <<endl;
    pl.play_list();
    
    close();
    
    return 0;
}
