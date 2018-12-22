#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

bool isnum;
bool isNum(string s){
    isnum = true;
    for(int i = 0; i < s.size(); i++){
        if(!isdigit(s[i])) isnum = false;
    }
    if(isnum){
        return true;
    } else {
        return false;
    }
}
int main(){
reinput_peopleNum:
    cout << "人数を入力" << endl;
    string peopleNum;
    int peopleNum_stoi;
    cin >> peopleNum;
    if(!isNum(peopleNum)){
        cout << "無効な入力" << endl;
        goto reinput_peopleNum;
    }
    peopleNum_stoi = stoi(peopleNum);
    if(peopleNum_stoi >= 10000){
        cout << "無効な入力" << endl;
        goto reinput_peopleNum;
    }
    vector<int> seatNum(peopleNum_stoi);
    for(int i = 0; i < peopleNum_stoi; i++){
        seatNum[i] = -1;
    }
    //config
    random_device rnd;
    int rndNum;
    string pos, val;
    int pos_stoi, val_stoi;
    vector<int> pos_list, val_list, put_list;
    int counter = 0;
    cout << "限定ランダムの設定(目が悪い人など)[endで終了]" << endl;
    cout << "ランダムに選ぶ際の席の番号" << endl;
    for(int i = 0; i < peopleNum_stoi; i++){
        cout << '[';
        if((i+1) / 10 == 0) cout << ' ';
        cout << i+1 << ']';
        if(counter == 5){
            cout << endl;
            counter = -1;
        }
        counter++;
    }
    cout << endl;
    cout << "ランダムに選ぶ席を指定" << endl;
    while(1){
reinput_pos:
        cin >> pos;
        if(pos == "end"){
            for(int i = 0; i < 20; i++){
                cout << endl;
            }
            break;
        }
        if(!isNum(pos)){
            cout << "無効な入力" << endl;
            goto reinput_pos;
        }
        pos_stoi = stoi(pos);
        if(pos_stoi > peopleNum_stoi){
            cout << "無効な入力" << endl;
            goto reinput_pos;
        }
        pos_list.push_back(pos_stoi);
    }
    cout << "出席番号を入力" << endl;
    while(1){
reinput_val:
        cin >> val;
        if(val == "end"){
            for(int i = 0; i < 20; i++){
                cout << endl;
            }
            break;
        }
        if(!isNum(val)){
            cout << "無効な入力" << endl;
            goto reinput_val;
        }
        val_stoi = stoi(val);
        if(val_stoi > peopleNum_stoi){
            cout << "無効な入力" << endl;
            goto reinput_val;
        }
        val_list.push_back(val_stoi);
    }
    bool isExist;
    for(int i = 0; i < val_list.size(); i++){
        retry_sp:
        isExist = false;
        rndNum = rnd() % peopleNum_stoi;
        for(int j = 0; j < pos_list.size(); j++){
            if(pos_list[j] == rndNum) isExist = true;
        }
        if(seatNum[rndNum] != -1) isExist = false;
        if(isExist){
            seatNum[rndNum] = val_list[i];
            put_list.push_back(rndNum);
        } else {
            goto retry_sp;
        }
    }
    //setRandom
    int a = 0;
    for(int i = 0; i < peopleNum_stoi; i++){
        for(int j = 0; j < put_list.size(); j++){
            if(i == put_list[j]) goto skip;
        }
        retry:
        rndNum = rnd() % peopleNum_stoi + 1;
        for(int j = 0; j < peopleNum_stoi; j++){
            if(seatNum[j] == rndNum) goto retry;
        }
        seatNum[i] = rndNum;
        skip:
        a++;
    }
    //do
    counter = 0;
    cout << "ARE YOU READY? (pless Enter)" << endl;
    while(getchar() != '\n');
    while(getchar() != '\n');
    for(int i = 3; i >= 1; i--){
        cout << i << endl;
        if(peopleNum_stoi <= 100)sleep(1);
    }
    cout << "GO!!!" << endl << endl;
    sleep(1);
    cout << "-------黒板--------" << endl << endl;
    for(int i = 0; i < peopleNum_stoi; i++){
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
    cout << "FINISH!!!!" << endl << endl;
    cout << "endで終了" << endl;
    string end;
    while(1){
        cin >> end;
        if(end == "end") break;
    }
}
