#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct YoutubeChannel{
    string Name;
    int SubscribersCount;
    YoutubeChannel(string name, int subscribersCount){
        Name = name;
        SubscribersCount = subscribersCount;
    }

    bool operator==(const YoutubeChannel& yt1) const {
    
    return this->Name == yt1.Name;
    
}

bool operator<(const YoutubeChannel& yt1) const {
    
    return this->SubscribersCount < yt1.SubscribersCount;
    
} // Again const as nothing changed to make sure it stays the same
//does adding const not matter here ??
// nope it does not matter here as we are not changing the value of yt1, we are just comparing it
// if we were changing the value of yt1, then we would have to add const

};

ostream& operator<<(ostream& COUT, YoutubeChannel& ytChannel){
    COUT << "Name: " << ytChannel.Name << endl;
    COUT << "Subscribers: " << ytChannel.SubscribersCount << endl;
    return COUT;   
}
// DAMN OVERLOADING OPERATOR MAKES SENSE A LIITLE BIT NOW !!!



int main(){

    YoutubeChannel ytChannel("CodeBeauty", 75000);
    cout << ytChannel;
    YoutubeChannel ytChannel2("Amy Sings", 75000);
    cout << ytChannel2;
    YoutubeChannel ytChannel3("CodeBeauty", 75000);
    cout << ytChannel2 << ytChannel;
    cout << (ytChannel == ytChannel3);



    return 0;
}