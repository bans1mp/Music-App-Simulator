#include<bits/stdc++.h>
#include<conio.h>
using namespace std ;

//Songs List

vector<vector<string>> songsList = {{"Fall Off - KR$NA" , "Saza-E-Maut - KR$NA X Raftaar" , "Nanchaku - Seedhe Maut" , "Zero Fark - Fotty Seven" , "Change - NF" , "Gnat - Eminem" , "Namastute - Seedhe Maut" ,"Goosebumps - Travis Scott" , "Homicide - Logix X Eminem" , "All Girls Are The Same - RONIN"} ,
                                        {"Mann Bhareya 2.0 - B Praak" , "Dangerously - Charlie Puth" , "Unknown - Jacob Banks" , "How Long - Charlie Puth" , "Riha - Anuv Jain" , "Baarishein - Anuv Jain" ,"Akela Hoon - AMAN" , "Tujhe Kitna Chahein Aur Hum - Arijit Singh" , "Waqt Ki Baatein - Dream Note" , "Kasoor - Prateek Kuhaad"} ,
                                        {"Darkhast - Arijit Singh" , "Tu Jaane Na - Atif Aslam" , "Mehrama - Pritam" , "Rahogi Meri - Arijit Singh" , "Ranjha - B Praak" , "Everything I Need - Skylar Grey" , "Jaded - Sadeyes" , "Say You Wont Let Go - James Arthur" , "Lie - NF" , "Someone You Loved - Lewis Capaldi"} , 
                                        {"We Found Love - Rihanna" , "Uptown Funk - Mark Ronson" , "Gonna Make You Sweat - C+C Music Factory" , "1999 - Prince" , "Poison - Bell Biv DeVoe" , "Call Me Maybe - Carly Rae Jepsen" , "Rock with You - Michael Jackson" , "Groove Is in the Heart - Deee-Lite" , "The Power - Snap" , "Pump Up the Jam - Technotronic"} ,
                                        {"Shape of You - Ed Sheeran" , "Blinding Lights - Weeknd" , "Dance Monkey - Tones and I" , "Rockstar - Post Malone" , "One Dance - Drake" , "Closer - Chainsmokers" ,"Sunflower - Post Malone" ,"Senorita - Shawn Mendes X Camila Cabello" , "Bad Guy - Billie Eilish" , "Perfect - Ed Sheeran"}} ;

//Favorites

vector<string> favorites ;

//Play Queue

queue<string> playQueue ;

void viewQueue(){
    if(playQueue.size() == 0){
         cout<<"The PlayQueue is empty. "<<endl ;
         return ;
    }
        else{
            cout<<"Currently Playing: "<<playQueue.front()<<endl ;
            cout<<"Songs in PlayQueue: "<<playQueue.size()<<endl ;
            cout<<"What do you want to do? "<<endl ;
            cout<<"1. Skip Song \n2. Instant add \n3. Main Menu"<<endl ;
            int opt ;
            cin>>opt ;
            if(opt == 1){
                playQueue.pop() ;
                cout<<"Song Skipped. "<<endl ;
            }
            else if(opt==2){
                cout<<"Enter the genre number and the song number that you want to instant add!"<<endl ;
                int w,e ;
                cin>>w>>e ;
                playQueue.push(songsList[w-1][e-1]) ;
                cout<<"Added to Queue"<<endl ;
            }
            else if(opt == 3) return ;
            else cout<<"Invalid Choice! "<<endl ;
        }
        viewQueue() ;
}

//Playlists

unordered_map<string,vector<string>> playlists ;

void showGenre(vector<string> &genre){
    for(int i = 0 ; i < genre.size() ; i++){
        cout<<i+1<<". "<<genre[i]<<endl ;
    }
}

void viewSongs(){
    cout<<"Select the type of songs you want to see! "<<endl ;
    cout<<"1. Hip Hop \n2. Sad I \n3. Sad II \n4. Dance \n5. Top 10 \n6. Main Menu"<<endl ;
    int x ;
    cin>>x ;
    if(x==6) return ;
    cout<<"The songs are :"<<endl ;
    showGenre(songsList[x-1]) ;
    viewSongs() ;
}

void mainMenu(){
    cout<<"What do you want to do? "<<endl ;
    cout<<"1. View Songs \n2. Add Playlist \n3. View Playlists \n4. Add Favorite Songs \n5. View Liked Songs \n6. Add to PlayQueue \n7. View PlayQueue \n8.Exit "<<endl ;
    int a ;
    cin>>a ;

    if(a==1) viewSongs() ;

    else if(a==2){
        //Add playlists
        cout<<"Enter the name for the playlist! "<<endl ;
        string name ;
        cin>>name ;
        cout<<"Enter the number of songs you want to add! "<<endl ;
        int p ;
        cin>>p ;
        while(p--){
            cout<<"Enter the genre number and the song number that you want to add! "<<endl ;
            int m , n ;
            cin>>m>>n ;
            playlists[name].push_back(songsList[m-1][n-1]) ;
            cout<<"Song added"<<endl ;
        }
        
    }
    else if(a==3){
        if(playlists.empty()) cout<<"No Playlists Found! "<<endl ;
        else{
            for(auto it : playlists){
                cout<<it.first<<":"<<endl ;
                for(int k = 0 ; k<it.second.size() ; k++){
                    cout<<k+1<<". "<<it.second[k]<<endl ;
                }
            }
        }
    }
    else if(a==4){
        //Add liked songs
        cout<<"Enter the number of songs you want to add! "<<endl ;
        int p ;
        cin>>p ;
        while(p--){
            cout<<"Enter the genre number and the song number that you want to add! "<<endl ;
            int m , n ;
            cin>>m>>n ;
            favorites.push_back(songsList[m-1][n-1]) ;
            cout<<"Song added"<<endl ;
        }
    }
    else if(a==5){
        if(favorites.size() == 0) cout<<"No Liked Songs! "<<endl ;
        else{
            cout<<"Your Liked Songs are: "<<endl ;
            for(int i = 0 ; i < favorites.size() ; i++){
                cout<<i+1<<". "<<favorites[i]<<endl ;
            }
        }
    }
    else if(a==6){
        //add to queue
        cout<<"Enter the number of songs you want to add to queue! "<<endl ;
        int p ;
        cin>>p ;
        while(p--){
            cout<<"Enter the genre number and the song number that you want to add! "<<endl ;
            int m , n ;
            cin>>m>>n ;
            playQueue.push(songsList[m-1][n-1]) ;
            cout<<"Song added"<<endl ;
        }
    }
    else if(a==7){
        viewQueue() ;
    }
    else if(a==8){
        cout<<"Thank you for using this program! "<<endl ;
        return ;
    }
    else cout<<"Invalid choice! "<<endl ;
    mainMenu() ;
}

int main(){
    cout<<"Welcome to the Music Player Simulator."<<endl ;
    mainMenu() ;

}