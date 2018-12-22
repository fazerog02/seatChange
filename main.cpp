#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main(){
    cout << "人数を入力" << endl;
    int peopleNum;
    cin >> peopleNum;
    vector<int> seatNum(peopleNum);
    for(int i = 0; i < peopleNum; i++){
        seatNum[i] = -1;
    }
    //setRandom
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
    int counter = 0;
    cout << "固定席の設定（endで終了）" << endl;
    cout << "1~人数までの数字で席を指定する" << endl;
    cout << "指定する際の席の番号" << endl;
    for(int i = 0; i < peopleNum; i++){
        cout << '[';
        if(seatNum[i] / 10 == 0) cout << 0;
        cout << i+1 << ']';
        if(counter == 5){
            cout << endl;
            counter = -1;
        }
        counter++;
    }
    cout << endl;
    while(1){
        counter = 0;
        cout << "席を指定" << endl;
        cin >> pos;
        if(pos == "end"){
            for(int i = 0; i < 20; i++){
                cout << endl;
            }
            break;
        }
        cout << "出席番号を入力" << endl;
        cin >> val;
        pos_stoi = stoi(pos);
        seatNum[pos_stoi-1] = val;
        cout << "プレビュー" << endl;
        for(int i = 0; i < peopleNum; i++){
            cout << '[';
            if(seatNum[i] / 10 == 0 && seatNum[i] != -1) cout << 0;
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
