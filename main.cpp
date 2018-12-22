#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main(){
    cout << "INPUT : HOW MANY PEOPLE" << endl;
    int peopleNum;
    cin >> peopleNum;
    vector<int> seatNum(peopleNum);
    for(int i = 0; i < peopleNum; i++){
        seatNum[i] = 10000;
    }
    //setrandom
    random_device rnd;
    int rndNum;
    for(int i = 0; i < peopleNum; i++){
        retry:
        rndNum = rnd() % peopleNum + 1;
        for(int j = 0; j < peopleNum; j++){
            if(seatNum[j] == rndNum) goto retry;
        }
        seatNum[i] = rndNum;
    }
    //config
    string pos;
    int pos_stoi, val;
    int counter;
    while(1){
        cout << "INPUT : ABSORUTE SEAT(input 'end' END)" << endl;
        counter = 0;
        cin >> pos;
        if(pos == "end"){
            for(int i = 0; i < 20; i++){
                cout << endl;
            }
            break;
        }
        cin >> val;
        pos_stoi = stoi(pos);
        seatNum[pos_stoi-1] = val;
        for(int i = 0; i < peopleNum; i++){
            cout << '[';
            if(seatNum[i] / 10 == 0) cout << 0;
            cout << seatNum[i] << ']';
            if(counter == 5){
                cout << endl;
                counter = -1;
            }
            counter++;
        }
        cout << endl;
    }
    //do
    counter = 0;
    cout << "ARE YOU READY?" << endl;
    while(getchar() != '\n');
    while(getchar() != '\n');
    for(int i = 3; i >= 1; i--){
        cout << i << endl;
        sleep(1);
    }
    cout << "GO!!!" << endl << endl;
    sleep(1);
    cout << "-------黒板--------" << endl << endl;
    for(int i = 0; i < peopleNum; i++){
        cout << '[';
        if(seatNum[i] / 10 == 0) cout << 0;
        cout << seatNum[i] << ']';
        if(counter == 5){
            cout << endl;
            counter = -1;
            sleep(1);
        }
        counter++;
    }
    cout << endl << endl;
    cout << "FINISH!!!!" << endl;
    while(getchar() != ' ');
}
